// This file is part of Notepad++ project
// Copyright (C)2021 Don HO <don.h@free.fr>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "URLCtrl.h"
#include "NppDarkMode.h"
//#include "Parameters.h"  // PapyrusPlugin modification -- not used

// PapyrusPlugin modification -- for OCR_HAND definition
#ifndef OCR_HAND
  #define OCR_HAND 32649
#endif

#include <string>  // PapyrusPlugin modification -- string manipulation for email link

void URLCtrl::create(HWND itemHandle, const TCHAR * link, COLORREF linkColor)
{
	// turn on notify style
    ::SetWindowLongPtr(itemHandle, GWL_STYLE, ::GetWindowLongPtr(itemHandle, GWL_STYLE) | SS_NOTIFY);

	// set the URL text (not the display text)
	if (link)
		_URL = link;

	// set the hyperlink colour
    _linkColor = linkColor;

	// set the visited colour
	_visitedColor = RGB(128,0,128);

	// subclass the static control
	_oldproc = reinterpret_cast<WNDPROC>(::SetWindowLongPtr(itemHandle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(URLCtrlProc)));

	// associate the URL structure with the static control
	::SetWindowLongPtr(itemHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	// save hwnd
	_hSelf = itemHandle;

	loadHandCursor();
}
void URLCtrl::create(HWND itemHandle, int cmd, HWND msgDest)
{
	// turn on notify style
    ::SetWindowLongPtr(itemHandle, GWL_STYLE, ::GetWindowLongPtr(itemHandle, GWL_STYLE) | SS_NOTIFY);

	_cmdID = cmd;
	_msgDest = msgDest;

	// set the hyperlink colour
    _linkColor = RGB(0,0,255);

	// subclass the static control
	_oldproc = reinterpret_cast<WNDPROC>(::SetWindowLongPtr(itemHandle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(URLCtrlProc)));

	// associate the URL structure with the static control
	::SetWindowLongPtr(itemHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	// save hwnd
	_hSelf = itemHandle;

	loadHandCursor();
}

void URLCtrl::destroy()
{
	if (_hfUnderlined)
	{
		::DeleteObject(_hfUnderlined);
		_hfUnderlined = nullptr;
	}
}

HCURSOR& URLCtrl::loadHandCursor()
{
	if (_hCursor == nullptr)
	{
		_hCursor = static_cast<HCURSOR>(::LoadImage(nullptr, MAKEINTRESOURCE(OCR_HAND), IMAGE_CURSOR, SM_CXCURSOR, SM_CYCURSOR, LR_SHARED));
	}

	return _hCursor;
}

void URLCtrl::action()
{
	if (_cmdID)
	{
		::SendMessage(_msgDest?_msgDest:_hParent, WM_COMMAND, _cmdID, 0);
	}
	else
	{
		_linkColor = _visitedColor;

		::InvalidateRect(_hSelf, 0, 0);
		::UpdateWindow(_hSelf);

    // PapyrusPlugin modification -- check for email link
    //
		// Open a browser
		if (_URL.empty())
		{
			TCHAR szWinText[MAX_PATH] = { '\0' };
			::GetWindowText(_hSelf, szWinText, MAX_PATH);
			_URL = std::wstring(szWinText);
		}

		if (_URL.find(L"://") == std::string::npos && _URL.find(L"@") != std::string::npos) {
			// Assume it's an email
			if (_URL.find(L"mailto:") == std::string::npos) {
				_URL = L"mailto:" + _URL;
			}
		}

		::ShellExecute(NULL, TEXT("open"), _URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
    //
    // PapyrusPlugin modification ends
  }
}

LRESULT URLCtrl::runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
      // Free up the structure we allocated
      case WM_NCDESTROY:
        //HeapFree(GetProcessHeap(), 0, url);
        break;

      // Paint the static control using our custom
      // colours, and with an underline text style
      case WM_PAINT:
      {
        DWORD dwStyle = static_cast<DWORD>(::GetWindowLongPtr(hwnd, GWL_STYLE));
        DWORD dwDTStyle = DT_SINGLELINE;

        //Test if centered horizontally or vertically
        if (dwStyle & SS_CENTER)       dwDTStyle |= DT_CENTER;
        if (dwStyle & SS_RIGHT)     dwDTStyle |= DT_RIGHT;
        if (dwStyle & SS_CENTERIMAGE) dwDTStyle |= DT_VCENTER;

			RECT rect{};
        ::GetClientRect(hwnd, &rect);

			PAINTSTRUCT ps{};
        HDC hdc = ::BeginPaint(hwnd, &ps);

			if ((_linkColor == _visitedColor) || (_linkColor == NppDarkMode::getDarkerTextColor()))
			{
				_linkColor = NppDarkMode::isEnabled() ? NppDarkMode::getDarkerTextColor() : _visitedColor;
				::SetTextColor(hdc, _linkColor);
			}
			else if (NppDarkMode::isEnabled())
			{
				::SetTextColor(hdc, NppDarkMode::getLinkTextColor());
			}
			else
			{
				::SetTextColor(hdc, _linkColor);
			}

        ::SetBkColor(hdc, getCtrlBgColor(GetParent(hwnd))); ///*::GetSysColor(COLOR_3DFACE)*/);

		    // Create an underline font
		    if (_hfUnderlined == nullptr)
		    {
			    // Get the default GUI font
    // PapyrusPlugin modification -- use old logic instead of getting it from NppParameters
    //
				//LOGFONT lf{ NppParameters::getDefaultGUIFont() };
				LOGFONT lf{};
                HFONT hf = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);

			    // Add UNDERLINE attribute
			    GetObject(hf, sizeof lf, &lf);
    //
    // PapyrusPlugin modification ends
                lf.lfUnderline = TRUE;

			    // Create a new font
                _hfUnderlined = ::CreateFontIndirect(&lf);
		    }

		    HANDLE hOld = SelectObject(hdc, _hfUnderlined);

		    // Draw the text!
			TCHAR szWinText[MAX_PATH] = { '\0' };
            ::GetWindowText(hwnd, szWinText, MAX_PATH);
            ::DrawText(hdc, szWinText, -1, &rect, dwDTStyle);

            ::SelectObject(hdc, hOld);

            ::EndPaint(hwnd, &ps);

		    return 0;
      }

      case WM_SETTEXT:
      {
        LRESULT ret = ::CallWindowProc(_oldproc, hwnd, Message, wParam, lParam);
        ::InvalidateRect(hwnd, 0, 0);
        return ret;
      }
      // Provide a hand cursor when the mouse moves over us
      //case WM_SETCURSOR:
      case WM_MOUSEMOVE:
      {
            ::SetCursor(loadHandCursor());
            return TRUE;
      }

      case WM_LBUTTONDOWN:
        _clicking = true;
        break;

      case WM_LBUTTONUP:
        if (_clicking)
        {
          _clicking = false;

          action();
        }

        break;

    //Support using space to activate this object
    case WM_KEYDOWN:
      if (wParam == VK_SPACE)
        _clicking = true;
      break;

    case WM_KEYUP:
      if (wParam == VK_SPACE && _clicking)
      {
        _clicking = false;

        action();
      }
      break;

      // A standard static control returns HTTRANSPARENT here, which
      // prevents us from receiving any mouse messages. So, return
      // HTCLIENT instead.
      case WM_NCHITTEST:
        return HTCLIENT;
    }
    return ::CallWindowProc(_oldproc, hwnd, Message, wParam, lParam);
}
