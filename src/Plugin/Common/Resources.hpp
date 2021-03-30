/*
This file is part of Papyrus Plugin for Notepad++.

Copyright (C) 2021 blu3mania <blu3mania@hotmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define STR_(X) #X
#define STR(X)  STR_(X)

#define PLUGIN_NAME     L"Papyrus"
#define MAJOR_VERSION   0
#define MINOR_VERSION   2
#define PATCH_VERSION   0
#define BUILD_NUMBER    0 // This number will be replaced by build script
#define PLUGIN_VERSION  STR(MAJOR_VERSION) L"." STR(MINOR_VERSION) L"." STR(PATCH_VERSION)

#define USE_UNICODE     TRUE

//
// Messages
//

#define PPM_COMPILATION_DONE      WM_USER
#define PPM_COMPILATION_FAILED    (WM_USER + 1)
#define PPM_ANONYMIZATION_FAILED  (WM_USER + 2)
#define PPM_COMPILER_NOT_FOUND    (WM_USER + 3)
#define PPM_OTHER_ERROR           (WM_USER + 4)
#define PPM_JUMP_TO_ERROR         (WM_USER + 5)

#define PARAM_COMPILATION_ONLY                0
#define PARAM_COMPILATION_WITH_ANONYMIZATION  1

//
// Resources
//

// Errors window resources
#define IDD_ERRORS_WINDOW                                 16000 // Base #
#define IDC_ERRORS_LIST                                   (IDD_ERRORS_WINDOW + 1)


// About dialog resources
#define IDD_ABOUT_DIALOG                                  17000 // Base + 1000
#define IDC_ABOUT_PRODUCT_NAME                            (IDD_ABOUT_DIALOG + 1)
#define IDC_ABOUT_PRODUCT_VERSION                         (IDD_ABOUT_DIALOG + 2)
#define IDC_ABOUT_COPYRIGHT                               (IDD_ABOUT_DIALOG + 3)
#define IDC_ABOUT_HOMEPAGE                                (IDD_ABOUT_DIALOG + 4)
#define IDC_ABOUT_HOMEPAGE_LINK                           (IDD_ABOUT_DIALOG + 5)
#define IDC_ABOUT_LICENSE                                 (IDD_ABOUT_DIALOG + 6)
#define IDC_ABOUT_LICENSE_LINK                            (IDD_ABOUT_DIALOG + 7)
#define IDC_ABOUT_AUTHORS                                 (IDD_ABOUT_DIALOG + 11)
#define IDC_ABOUT_ORIG_AUTHOR                             (IDC_ABOUT_AUTHORS + 1)
#define IDC_ABOUT_ORIG_AUTHOR_EMAIL                       (IDC_ABOUT_AUTHORS + 2)
#define IDC_ABOUT_AUTHOR                                  (IDC_ABOUT_AUTHORS + 3)
#define IDC_ABOUT_AUTHOR_EMAIL                            (IDC_ABOUT_AUTHORS + 4)
#define IDC_ABOUT_LIBRARIES                               (IDD_ABOUT_DIALOG + 21)
#define IDC_ABOUT_LIBRARY_NPP                             (IDC_ABOUT_LIBRARIES + 1)
#define IDC_ABOUT_LIBRARY_NPP_LINK                        (IDC_ABOUT_LIBRARIES + 2)
#define IDC_ABOUT_LIBRARY_SCINTILLA                       (IDC_ABOUT_LIBRARIES + 3)
#define IDC_ABOUT_LIBRARY_SCINTILLA_LINK                  (IDC_ABOUT_LIBRARIES + 4)
#define IDC_ABOUT_LIBRARY_TINYXML                         (IDC_ABOUT_LIBRARIES + 5)
#define IDC_ABOUT_LIBRARY_TINYXML_LINK                    (IDC_ABOUT_LIBRARIES + 6)
#define IDC_ABOUT_LIBRARY_GSL                             (IDC_ABOUT_LIBRARIES + 7)
#define IDC_ABOUT_LIBRARY_GSL_LINK                        (IDC_ABOUT_LIBRARIES + 8)


// Settings dialog resources
#define IDD_SETTINGS_DIALOG                               18000 // Base + 2000
#define IDC_SETTINGS_TABS                                 (IDD_SETTINGS_DIALOG + 1)

#define IDC_SETTINGS_TAB_LEXER                            (IDD_SETTINGS_DIALOG + 100)
#define IDC_SETTINGS_LEXER_SCRIPT_GROUP                   (IDC_SETTINGS_TAB_LEXER + 1)
#define IDC_SETTINGS_LEXER_FOLD_MIDDLE                    (IDC_SETTINGS_TAB_LEXER + 2)
#define IDC_SETTINGS_LEXER_CLASS_NAME_CACHING             (IDC_SETTINGS_TAB_LEXER + 3)
#define IDC_SETTINGS_LEXER_CLASS_LINK                     (IDC_SETTINGS_TAB_LEXER + 11)
#define IDC_SETTINGS_LEXER_CLASS_LINK_UNDERLINE           (IDC_SETTINGS_LEXER_CLASS_LINK + 1)
#define IDC_SETTINGS_LEXER_CLASS_LINK_FGCOLOR_LABEL       (IDC_SETTINGS_LEXER_CLASS_LINK + 2)
#define IDC_SETTINGS_LEXER_CLASS_LINK_BGCOLOR_LABEL       (IDC_SETTINGS_LEXER_CLASS_LINK + 3)
#define IDC_SETTINGS_LEXER_CLASS_LINK_MODIFIER_LABEL      (IDC_SETTINGS_LEXER_CLASS_LINK + 4)
#define IDC_SETTINGS_LEXER_CLASS_LINK_MODIFIER_SHIFT      (IDC_SETTINGS_LEXER_CLASS_LINK + 5)
#define IDC_SETTINGS_LEXER_CLASS_LINK_MODIFIER_CTRL       (IDC_SETTINGS_LEXER_CLASS_LINK + 6)
#define IDC_SETTINGS_LEXER_CLASS_LINK_MODIFIER_ALT        (IDC_SETTINGS_LEXER_CLASS_LINK + 7)
#define IDC_SETTINGS_LEXER_STYLER_CONFIG_TEXT1            (IDC_SETTINGS_TAB_LEXER + 31)
#define IDC_SETTINGS_LEXER_STYLER_CONFIG_TEXT2            (IDC_SETTINGS_LEXER_STYLER_CONFIG_TEXT1 + 1)
#define IDC_SETTINGS_LEXER_STYLER_CONFIG_LINK             (IDC_SETTINGS_LEXER_STYLER_CONFIG_TEXT1 + 2)

#define IDC_SETTINGS_TAB_KEYWORD_MATCHER                  (IDD_SETTINGS_DIALOG + 500)
#define IDC_SETTINGS_MATCHER                              (IDC_SETTINGS_TAB_KEYWORD_MATCHER + 1)
#define IDC_SETTINGS_MATCHER_KEYWORDS_LABEL               (IDC_SETTINGS_MATCHER + 1)
#define IDC_SETTINGS_MATCHER_KEYWORD_FUNCTION             (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 1)
#define IDC_SETTINGS_MATCHER_KEYWORD_STATE                (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 2)
#define IDC_SETTINGS_MATCHER_KEYWORD_EVENT                (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 3)
#define IDC_SETTINGS_MATCHER_KEYWORD_PROPERTY             (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 4)
#define IDC_SETTINGS_MATCHER_KEYWORD_GROUP                (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 5)
#define IDC_SETTINGS_MATCHER_KEYWORD_STRUCT               (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 6)
#define IDC_SETTINGS_MATCHER_KEYWORD_IF                   (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 7)
#define IDC_SETTINGS_MATCHER_KEYWORD_ELSE                 (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 8)
#define IDC_SETTINGS_MATCHER_KEYWORD_WHILE                (IDC_SETTINGS_MATCHER_KEYWORDS_LABEL + 9)
#define IDC_SETTINGS_MATCHER_INDICATOR_ID_LABEL           (IDC_SETTINGS_MATCHER + 20)
#define IDC_SETTINGS_MATCHER_INDICATOR_ID                 (IDC_SETTINGS_MATCHER + 21)
#define IDS_SETTINGS_MATCHER_INDICATOR_ID_TOOLTIP         (IDC_SETTINGS_MATCHER + 22)
#define IDC_SETTINGS_MATCHER_MATCHED_STYLE_LABEL          (IDC_SETTINGS_MATCHER + 30)
#define IDC_SETTINGS_MATCHER_MATCHED_STYLE_DROPDOWN       (IDC_SETTINGS_MATCHER + 31)
#define IDC_SETTINGS_MATCHER_MATCHED_FGCOLOR_LABEL        (IDC_SETTINGS_MATCHER + 32)
#define IDC_SETTINGS_MATCHER_UNMATCHED_STYLE_LABEL        (IDC_SETTINGS_MATCHER + 40)
#define IDC_SETTINGS_MATCHER_UNMATCHED_STYLE_DROPDOWN     (IDC_SETTINGS_MATCHER + 41)
#define IDC_SETTINGS_MATCHER_UNMATCHED_FGCOLOR_LABEL      (IDC_SETTINGS_MATCHER + 42)

#define IDC_SETTINGS_TAB_ERROR_ANNOTATOR                  (IDD_SETTINGS_DIALOG + 700)
#define IDC_SETTINGS_ANNOTATOR_ANNOTATION_GROUP           (IDC_SETTINGS_TAB_ERROR_ANNOTATOR + 1)
#define IDC_SETTINGS_ANNOTATOR_ENABLE_ANNOTATION          (IDC_SETTINGS_ANNOTATOR_ANNOTATION_GROUP + 1)
#define IDC_SETTINGS_ANNOTATOR_ANNOTATION_FGCOLOR_LABEL   (IDC_SETTINGS_ANNOTATOR_ANNOTATION_GROUP + 2)
#define IDC_SETTINGS_ANNOTATOR_ANNOTATION_BGCOLOR_LABEL   (IDC_SETTINGS_ANNOTATOR_ANNOTATION_GROUP + 3)
#define IDC_SETTINGS_ANNOTATOR_ANNOTATION_ITALIC          (IDC_SETTINGS_ANNOTATOR_ANNOTATION_GROUP + 4)
#define IDC_SETTINGS_ANNOTATOR_ANNOTATION_BOLD            (IDC_SETTINGS_ANNOTATOR_ANNOTATION_GROUP + 5)
#define IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP            (IDC_SETTINGS_TAB_ERROR_ANNOTATOR + 21)
#define IDC_SETTINGS_ANNOTATOR_ENABLE_INDICATION          (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 1)
#define IDC_SETTINGS_ANNOTATOR_INDICATOR_ID_LABEL         (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 2)
#define IDC_SETTINGS_ANNOTATOR_INDICATOR_ID               (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 3)
#define IDS_SETTINGS_ANNOTATOR_INDICATOR_ID_TOOLTIP       (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 4)
#define IDC_SETTINGS_ANNOTATOR_INDICATOR_STYLE_LABEL      (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 5)
#define IDC_SETTINGS_ANNOTATOR_INDICATOR_STYLE_DROPDOWN   (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 6)
#define IDC_SETTINGS_ANNOTATOR_INDICATOR_FGCOLOR_LABEL    (IDC_SETTINGS_ANNOTATOR_INDICATOR_GROUP + 7)

#define IDC_SETTINGS_TAB_COMPILER                         (IDD_SETTINGS_DIALOG + 800)
#define IDC_SETTINGS_COMPILER_GAMES_GROUP                 (IDC_SETTINGS_TAB_COMPILER + 1)
#define IDC_SETTINGS_COMPILER_RADIO_AUTO                  (IDC_SETTINGS_COMPILER_GAMES_GROUP + 1)
#define IDC_SETTINGS_COMPILER_RADIO_SKYRIM                (IDC_SETTINGS_COMPILER_GAMES_GROUP + 2)
#define IDC_SETTINGS_COMPILER_RADIO_SSE                   (IDC_SETTINGS_COMPILER_GAMES_GROUP + 3)
#define IDC_SETTINGS_COMPILER_RADIO_FO4                   (IDC_SETTINGS_COMPILER_GAMES_GROUP + 4)
#define IDS_SETTINGS_COMPILER_RADIO_AUTO_TOOLTIP          (IDC_SETTINGS_COMPILER_GAMES_GROUP + 5)
#define IDC_SETTINGS_COMPILER_ALLOW_UNMANAGED_SOURCE      (IDC_SETTINGS_COMPILER_GAMES_GROUP + 10)
#define IDC_SETTINGS_COMPILER_AUTO_DEFAULT_GAME_LABEL     (IDC_SETTINGS_COMPILER_GAMES_GROUP + 30)
#define IDC_SETTINGS_COMPILER_AUTO_DEFAULT_GAME_DROPDOWN  (IDC_SETTINGS_COMPILER_GAMES_GROUP + 31)
#define IDC_SETTINGS_COMPILER_AUTO_DEFAULT_OUTPUT_LABEL   (IDC_SETTINGS_COMPILER_GAMES_GROUP + 32)
#define IDC_SETTINGS_COMPILER_AUTO_DEFAULT_OUTPUT         (IDC_SETTINGS_COMPILER_GAMES_GROUP + 33)
#define IDC_SETTINGS_COMPILER_SKYRIM_TOGGLE               (IDC_SETTINGS_COMPILER_GAMES_GROUP + 50)
#define IDC_SETTINGS_COMPILER_SKYRIM_CONFIGURE            (IDC_SETTINGS_COMPILER_GAMES_GROUP + 51)
#define IDC_SETTINGS_COMPILER_SSE_TOGGLE                  (IDC_SETTINGS_COMPILER_GAMES_GROUP + 60)
#define IDC_SETTINGS_COMPILER_SSE_CONFIGURE               (IDC_SETTINGS_COMPILER_GAMES_GROUP + 61)
#define IDC_SETTINGS_COMPILER_FO4_TOGGLE                  (IDC_SETTINGS_COMPILER_GAMES_GROUP + 70)
#define IDC_SETTINGS_COMPILER_FO4_CONFIGURE               (IDC_SETTINGS_COMPILER_GAMES_GROUP + 71)

#define IDC_SETTINGS_TAB_GAME                             (IDD_SETTINGS_DIALOG + 900)
#define IDC_SETTINGS_TAB_GAME_INSTALL_PATH_LABEL          (IDC_SETTINGS_TAB_GAME + 1)
#define IDC_SETTINGS_TAB_GAME_INSTALL_PATH                (IDC_SETTINGS_TAB_GAME + 2)
#define IDC_SETTINGS_TAB_GAME_COMPILER_PATH_LABEL         (IDC_SETTINGS_TAB_GAME + 3)
#define IDC_SETTINGS_TAB_GAME_COMPILER_PATH               (IDC_SETTINGS_TAB_GAME + 4)
#define IDC_SETTINGS_TAB_GAME_IMPORT_DIRECTORIES_LABEL1   (IDC_SETTINGS_TAB_GAME + 5)
#define IDC_SETTINGS_TAB_GAME_IMPORT_DIRECTORIES_LABEL2   (IDC_SETTINGS_TAB_GAME + 6)
#define IDC_SETTINGS_TAB_GAME_IMPORT_DIRECTORIES          (IDC_SETTINGS_TAB_GAME + 7)
#define IDC_SETTINGS_TAB_GAME_OUTPUT_DIRECTORY_LABEL      (IDC_SETTINGS_TAB_GAME + 8)
#define IDC_SETTINGS_TAB_GAME_OUTPUT_DIRECTORY            (IDC_SETTINGS_TAB_GAME + 9)
#define IDC_SETTINGS_TAB_GAME_FLAG_FILE_LABEL             (IDC_SETTINGS_TAB_GAME + 10)
#define IDC_SETTINGS_TAB_GAME_FLAG_FILE                   (IDC_SETTINGS_TAB_GAME + 11)
#define IDC_SETTINGS_TAB_GAME_ANONYMIZE                   (IDC_SETTINGS_TAB_GAME + 12)
#define IDC_SETTINGS_TAB_GAME_OPTIMIZE                    (IDC_SETTINGS_TAB_GAME + 13)
#define IDC_SETTINGS_TAB_GAME_RELEASE                     (IDC_SETTINGS_TAB_GAME + 14)
#define IDC_SETTINGS_TAB_GAME_FINAL                       (IDC_SETTINGS_TAB_GAME + 15)
