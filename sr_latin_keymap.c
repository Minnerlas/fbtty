#include "sr_latin_keymap.h"

#include <stdint.h>

const uint32_t en_latin_keymap[0x27d] = {
	[KEY_RESERVED]         = 0,
	[KEY_ESC]              = 0,
	[KEY_1]                = L'1',
	[KEY_2]                = L'2',
	[KEY_3]                = L'3',
	[KEY_4]                = L'4',
	[KEY_5]                = L'5',
	[KEY_6]                = L'6',
	[KEY_7]                = L'7',
	[KEY_8]                = L'8',
	[KEY_9]                = L'9',
	[KEY_0]                = L'0',
	[KEY_MINUS]            = L'\'',
	[KEY_EQUAL]            = L'+',
	[KEY_BACKSPACE]        = 0, //L'0',
	[KEY_TAB]              = L'\t',
	[KEY_Q]                = L'q',
	[KEY_W]                = L'w',
	[KEY_E]                = L'e',
	[KEY_R]                = L'r',
	[KEY_T]                = L't',
	[KEY_Y]                = L'y',
	[KEY_U]                = L'u',
	[KEY_I]                = L'i',
	[KEY_O]                = L'o',
	[KEY_P]                = L'p',
	[KEY_LEFTBRACE]        = L'{',
	[KEY_RIGHTBRACE]       = L'}',
	[KEY_ENTER]            = L'\n',
	[KEY_LEFTCTRL]         = 0, //L'0',
	[KEY_A]                = L'a',
	[KEY_S]                = L's',
	[KEY_D]                = L'd',
	[KEY_F]                = L'f',
	[KEY_G]                = L'g',
	[KEY_H]                = L'h',
	[KEY_J]                = L'j',
	[KEY_K]                = L'k',
	[KEY_L]                = L'l',
	[KEY_SEMICOLON]        = L';',
	[KEY_APOSTROPHE]       = L'\'',
	[KEY_GRAVE]            = L'`',
	[KEY_LEFTSHIFT]        = 0, //L'0',
	[KEY_BACKSLASH]        = L'\\',
	[KEY_Z]                = L'z',
	[KEY_X]                = L'x',
	[KEY_C]                = L'c',
	[KEY_V]                = L'v',
	[KEY_B]                = L'b',
	[KEY_N]                = L'n',
	[KEY_M]                = L'm',
	[KEY_COMMA]            = L',',
	[KEY_DOT]              = L'.',
	[KEY_SLASH]            = L'/',
	[KEY_RIGHTSHIFT]       = 0, //L'0',
	[KEY_KPASTERISK]       = L'*',
	[KEY_LEFTALT]          = 0, //L'0',
	[KEY_SPACE]            = L' ',
	[KEY_CAPSLOCK]         = 0, //L'0',
	[KEY_F1]               = 0, //L'0',
	[KEY_F2]               = 0, //L'0',
	[KEY_F3]               = 0, //L'0',
	[KEY_F4]               = 0, //L'0',
	[KEY_F5]               = 0, //L'0',
	[KEY_F6]               = 0, //L'0',
	[KEY_F7]               = 0, //L'0',
	[KEY_F8]               = 0, //L'0',
	[KEY_F9]               = 0, //L'0',
	[KEY_F10]              = 0, //L'0',
	[KEY_NUMLOCK]          = 0, //L'0',
	[KEY_SCROLLLOCK]       = 0, //L'0',
	[KEY_KP7]              = L'7',
	[KEY_KP8]              = L'8',
	[KEY_KP9]              = L'9',
	[KEY_KPMINUS]          = L'-',
	[KEY_KP4]              = L'4',
	[KEY_KP5]              = L'5',
	[KEY_KP6]              = L'6',
	[KEY_KPPLUS]           = L'+',
	[KEY_KP1]              = L'1',
	[KEY_KP2]              = L'2',
	[KEY_KP3]              = L'3',
	[KEY_KP0]              = L'0',
	[KEY_KPDOT]            = L'.',

	[KEY_102ND]            = 0, //L'0',
	[KEY_F11]              = 0, //L'0',
	[KEY_F12]              = 0, //L'0',
	[KEY_RIGHTCTRL]        = 0, //L'0',
	[KEY_KPSLASH]          = L'/',
	[KEY_SYSRQ]            = 0, //L'0', // PrtSc
	[KEY_RIGHTALT]         = 0, //L'0',
	[KEY_LINEFEED]         = L'\n',
	[KEY_HOME]             = 0, //L'0',
	[KEY_UP]               = 0, //L'0',
	[KEY_PAGEUP]           = 0, //L'0',
	[KEY_LEFT]             = 0, //L'0',
	[KEY_RIGHT]            = 0, //L'0',
	[KEY_END]              = 0, //L'0',
	[KEY_DOWN]             = 0, //L'0',
	[KEY_PAGEDOWN]         = 0, //L'0',
	[KEY_INSERT]           = 0, //L'0',
	[KEY_DELETE]           = 0, //L'0',
	[KEY_MACRO]            = 0, //L'0',
	[KEY_MUTE]             = 0, //L'0',
	[KEY_VOLUMEDOWN]       = 0, //L'0',
	[KEY_VOLUMEUP]         = 0, //L'0',
	[KEY_POWER]            = 0, //L'0',
	[KEY_KPEQUAL]          = L'=',
	[KEY_KPPLUSMINUS]      = L'±',
	[KEY_PAUSE]            = 0, //L'0',
	[KEY_SCALE]            = 0, //L'0',

	[KEY_KPCOMMA]          = L',',
	[KEY_LEFTMETA]         = 0, //L'0',
	[KEY_RIGHTMETA]        = 0, //L'0',
	[KEY_COMPOSE]          = 0, //L'0',

	[KEY_STOP]             = 0, //L'0',
	[KEY_AGAIN]            = 0, //L'0',
	[KEY_PROPS]            = 0, //L'0',
	[KEY_UNDO]             = 0, //L'0',
	[KEY_FRONT]            = 0, //L'0',
	[KEY_COPY]             = 0, //L'0',
	[KEY_OPEN]             = 0, //L'0',
	[KEY_PASTE]            = 0, //L'0',
	[KEY_FIND]             = 0, //L'0',
	[KEY_CUT]              = 0, //L'0',
	[KEY_HELP]             = 0, //L'0',
	[KEY_MENU]             = 0, //L'0',
	[KEY_CALC]             = 0, //L'0',
	[KEY_SETUP]            = 0, //L'0',
	[KEY_SLEEP]            = 0, //L'0',
	[KEY_WAKEUP]           = 0, //L'0',
	[KEY_FILE]             = 0, //L'0',
	[KEY_SENDFILE]         = 0, //L'0',
	[KEY_DELETEFILE]       = 0, //L'0',
	[KEY_XFER]             = 0, //L'0',
	[KEY_PROG1]            = 0, //L'0',
	[KEY_PROG2]            = 0, //L'0',
	[KEY_WWW]              = 0, //L'0',
	[KEY_MSDOS]            = 0, //L'0',
	[KEY_COFFEE]           = 0, //L'0',
	[KEY_ROTATE_DISPLAY]   = 0, //L'0',
	[KEY_CYCLEWINDOWS]     = 0, //L'0',
	[KEY_MAIL]             = 0, //L'0',
	[KEY_BOOKMARKS]        = 0, //L'0',
	[KEY_COMPUTER]         = 0, //L'0',
	[KEY_BACK]             = 0, //L'0',
	[KEY_FORWARD]          = 0, //L'0',
	[KEY_CLOSECD]          = 0, //L'0',
	[KEY_EJECTCD]          = 0, //L'0',
	[KEY_EJECTCLOSECD]     = 0, //L'0',
	[KEY_NEXTSONG]         = 0, //L'0',
	[KEY_PLAYPAUSE]        = 0, //L'0',
	[KEY_PREVIOUSSONG]     = 0, //L'0',
	[KEY_STOPCD]           = 0, //L'0',
	[KEY_RECORD]           = 0, //L'0',
	[KEY_REWIND]           = 0, //L'0',
	[KEY_PHONE]            = 0, //L'0',
	[KEY_ISO]              = 0, //L'0',
	[KEY_CONFIG]           = 0, //L'0',
	[KEY_HOMEPAGE]         = 0, //L'0',
	[KEY_REFRESH]          = 0, //L'0',
	[KEY_EXIT]             = 0, //L'0',
	[KEY_MOVE]             = 0, //L'0',
	[KEY_EDIT]             = 0, //L'0',
	[KEY_SCROLLUP]         = 0, //L'0',
	[KEY_SCROLLDOWN]       = 0, //L'0',
	[KEY_KPLEFTPAREN]      = L'(',
	[KEY_KPRIGHTPAREN]     = L')',
	[KEY_NEW]              = 0, //L'0',
	[KEY_REDO]             = 0, //L'0',

	[KEY_F13]              = 0, //L'0',
	[KEY_F14]              = 0, //L'0',
	[KEY_F15]              = 0, //L'0',
	[KEY_F16]              = 0, //L'0',
	[KEY_F17]              = 0, //L'0',
	[KEY_F18]              = 0, //L'0',
	[KEY_F19]              = 0, //L'0',
	[KEY_F20]              = 0, //L'0',
	[KEY_F21]              = 0, //L'0',
	[KEY_F22]              = 0, //L'0',
	[KEY_F23]              = 0, //L'0',
	[KEY_F24]              = 0, //L'0',

	[KEY_PLAYCD]           = 0, //L'0',
	[KEY_PAUSECD]          = 0, //L'0',
	[KEY_PROG3]            = 0, //L'0',
	[KEY_PROG4]            = 0, //L'0',
	[KEY_DASHBOARD]        = 0, //L'0',
	[KEY_SUSPEND]          = 0, //L'0',
	[KEY_CLOSE]            = 0, //L'0',
	[KEY_PLAY]             = 0, //L'0',
	[KEY_FASTFORWARD]      = 0, //L'0',
	[KEY_BASSBOOST]        = 0, //L'0',
	[KEY_PRINT]            = 0, //L'0',
	[KEY_HP]               = 0, //L'0',
	[KEY_CAMERA]           = 0, //L'0',
	[KEY_SOUND]            = 0, //L'0',
	[KEY_QUESTION]         = 0, //L'0',
	[KEY_EMAIL]            = 0, //L'0',
	[KEY_CHAT]             = 0, //L'0',
	[KEY_SEARCH]           = 0, //L'0',
	[KEY_CONNECT]          = 0, //L'0',
	[KEY_FINANCE]          = 0, //L'0',
	[KEY_SPORT]            = 0, //L'0',
	[KEY_SHOP]             = 0, //L'0',
	[KEY_ALTERASE]         = 0, //L'0',
	[KEY_CANCEL]           = 0, //L'0',
	[KEY_BRIGHTNESSDOWN]   = 0, //L'0',
	[KEY_BRIGHTNESSUP]     = 0, //L'0',
	[KEY_MEDIA]            = 0, //L'0',

	[KEY_SWITCHVIDEOMODE]  = 0, //L'0',

	[KEY_KBDILLUMTOGGLE]   = 0, //L'0',
	[KEY_KBDILLUMDOWN]     = 0, //L'0',
	[KEY_KBDILLUMUP]       = 0, //L'0',

	[KEY_SEND]             = 0, //L'0',
	[KEY_REPLY]            = 0, //L'0',
	[KEY_FORWARDMAIL]      = 0, //L'0',
	[KEY_SAVE]             = 0, //L'0',
	[KEY_DOCUMENTS]        = 0, //L'0',

	[KEY_BATTERY]          = 0, //L'0',

	[KEY_BLUETOOTH]        = 0, //L'0',
	[KEY_WLAN]             = 0, //L'0',
	[KEY_UWB]              = 0, //L'0',

	[KEY_UNKNOWN]          = 0, //L'0',

	[KEY_VIDEO_NEXT]       = 0, //L'0',
	[KEY_VIDEO_PREV]       = 0, //L'0',
	[KEY_BRIGHTNESS_CYCLE] = 0, //L'0',
	[KEY_BRIGHTNESS_AUTO]  = 0, //L'0',


	[KEY_DISPLAY_OFF]      = 0, //L'0',

	[KEY_WWAN]             = 0, //L'0',
	[KEY_RFKILL]           = 0, //L'0',

	[KEY_MICMUTE]          = 0, //L'0',
	[KEY_SELECTIVE_SCREENSHOT] = 0,
	[POSLEDNJI]            = 0,
	[LALALALA]            = 0,

};

const uint32_t sr_latin_keymap[0x27d] = {
	[KEY_RESERVED]         = 0,
	[KEY_ESC]              = 0,
	[KEY_1]                = L'1',
	[KEY_2]                = L'2',
	[KEY_3]                = L'3',
	[KEY_4]                = L'4',
	[KEY_5]                = L'5',
	[KEY_6]                = L'6',
	[KEY_7]                = L'7',
	[KEY_8]                = L'8',
	[KEY_9]                = L'9',
	[KEY_0]                = L'0',
	[KEY_MINUS]            = L'-',
	[KEY_EQUAL]            = L'=',
	[KEY_BACKSPACE]        = 0, //L'0',
	[KEY_TAB]              = L'\t',
	[KEY_Q]                = L'q',
	[KEY_W]                = L'w',
	[KEY_E]                = L'e',
	[KEY_R]                = L'r',
	[KEY_T]                = L't',
	[KEY_Y]                = L'z',
	[KEY_U]                = L'u',
	[KEY_I]                = L'i',
	[KEY_O]                = L'o',
	[KEY_P]                = L'p',
	[KEY_LEFTBRACE]        = L'š',
	[KEY_RIGHTBRACE]       = L'đ',
	[KEY_ENTER]            = L'\n',
	[KEY_LEFTCTRL]         = 0, //L'0',
	[KEY_A]                = L'a',
	[KEY_S]                = L's',
	[KEY_D]                = L'd',
	[KEY_F]                = L'f',
	[KEY_G]                = L'g',
	[KEY_H]                = L'h',
	[KEY_J]                = L'j',
	[KEY_K]                = L'k',
	[KEY_L]                = L'l',
	[KEY_SEMICOLON]        = L'č',
	[KEY_APOSTROPHE]       = L'ć',
	[KEY_GRAVE]            = L'`',
	[KEY_LEFTSHIFT]        = 0, //L'0',
	[KEY_BACKSLASH]        = L'ž',
	[KEY_Z]                = L'y',
	[KEY_X]                = L'x',
	[KEY_C]                = L'c',
	[KEY_V]                = L'v',
	[KEY_B]                = L'b',
	[KEY_N]                = L'n',
	[KEY_M]                = L'm',
	[KEY_COMMA]            = L',',
	[KEY_DOT]              = L'.',
	[KEY_SLASH]            = L'-',
	[KEY_RIGHTSHIFT]       = 0, //L'0',
	[KEY_KPASTERISK]       = L'*',
	[KEY_LEFTALT]          = 0, //L'0',
	[KEY_SPACE]            = L' ',
	[KEY_CAPSLOCK]         = 0, //L'0',
	[KEY_F1]               = 0, //L'0',
	[KEY_F2]               = 0, //L'0',
	[KEY_F3]               = 0, //L'0',
	[KEY_F4]               = 0, //L'0',
	[KEY_F5]               = 0, //L'0',
	[KEY_F6]               = 0, //L'0',
	[KEY_F7]               = 0, //L'0',
	[KEY_F8]               = 0, //L'0',
	[KEY_F9]               = 0, //L'0',
	[KEY_F10]              = 0, //L'0',
	[KEY_NUMLOCK]          = 0, //L'0',
	[KEY_SCROLLLOCK]       = 0, //L'0',
	[KEY_KP7]              = L'7',
	[KEY_KP8]              = L'8',
	[KEY_KP9]              = L'9',
	[KEY_KPMINUS]          = L'-',
	[KEY_KP4]              = L'4',
	[KEY_KP5]              = L'5',
	[KEY_KP6]              = L'6',
	[KEY_KPPLUS]           = L'+',
	[KEY_KP1]              = L'1',
	[KEY_KP2]              = L'2',
	[KEY_KP3]              = L'3',
	[KEY_KP0]              = L'0',
	[KEY_KPDOT]            = L'.',

	[KEY_102ND]            = L'<',
	[KEY_F11]              = 0, //L'0',
	[KEY_F12]              = 0, //L'0',
	[KEY_RIGHTCTRL]        = 0, //L'0',
	[KEY_KPSLASH]          = L'/',
	[KEY_SYSRQ]            = 0, //L'0', // PrtSc
	[KEY_RIGHTALT]         = 0, //L'0',
	[KEY_LINEFEED]         = L'\n',
	[KEY_HOME]             = 0, //L'0',
	[KEY_UP]               = 0, //L'0',
	[KEY_PAGEUP]           = 0, //L'0',
	[KEY_LEFT]             = 0, //L'0',
	[KEY_RIGHT]            = 0, //L'0',
	[KEY_END]              = 0, //L'0',
	[KEY_DOWN]             = 0, //L'0',
	[KEY_PAGEDOWN]         = 0, //L'0',
	[KEY_INSERT]           = 0, //L'0',
	[KEY_DELETE]           = 0, //L'0',
	[KEY_MACRO]            = 0, //L'0',
	[KEY_MUTE]             = 0, //L'0',
	[KEY_VOLUMEDOWN]       = 0, //L'0',
	[KEY_VOLUMEUP]         = 0, //L'0',
	[KEY_POWER]            = 0, //L'0',
	[KEY_KPEQUAL]          = L'=',
	[KEY_KPPLUSMINUS]      = L'±',
	[KEY_PAUSE]            = 0, //L'0',
	[KEY_SCALE]            = 0, //L'0',

	[KEY_KPCOMMA]          = L',',
	[KEY_LEFTMETA]         = 0, //L'0',
	[KEY_RIGHTMETA]        = 0, //L'0',
	[KEY_COMPOSE]          = 0, //L'0',

	[KEY_STOP]             = 0, //L'0',
	[KEY_AGAIN]            = 0, //L'0',
	[KEY_PROPS]            = 0, //L'0',
	[KEY_UNDO]             = 0, //L'0',
	[KEY_FRONT]            = 0, //L'0',
	[KEY_COPY]             = 0, //L'0',
	[KEY_OPEN]             = 0, //L'0',
	[KEY_PASTE]            = 0, //L'0',
	[KEY_FIND]             = 0, //L'0',
	[KEY_CUT]              = 0, //L'0',
	[KEY_HELP]             = 0, //L'0',
	[KEY_MENU]             = 0, //L'0',
	[KEY_CALC]             = 0, //L'0',
	[KEY_SETUP]            = 0, //L'0',
	[KEY_SLEEP]            = 0, //L'0',
	[KEY_WAKEUP]           = 0, //L'0',
	[KEY_FILE]             = 0, //L'0',
	[KEY_SENDFILE]         = 0, //L'0',
	[KEY_DELETEFILE]       = 0, //L'0',
	[KEY_XFER]             = 0, //L'0',
	[KEY_PROG1]            = 0, //L'0',
	[KEY_PROG2]            = 0, //L'0',
	[KEY_WWW]              = 0, //L'0',
	[KEY_MSDOS]            = 0, //L'0',
	[KEY_COFFEE]           = 0, //L'0',
	[KEY_ROTATE_DISPLAY]   = 0, //L'0',
	[KEY_CYCLEWINDOWS]     = 0, //L'0',
	[KEY_MAIL]             = 0, //L'0',
	[KEY_BOOKMARKS]        = 0, //L'0',
	[KEY_COMPUTER]         = 0, //L'0',
	[KEY_BACK]             = 0, //L'0',
	[KEY_FORWARD]          = 0, //L'0',
	[KEY_CLOSECD]          = 0, //L'0',
	[KEY_EJECTCD]          = 0, //L'0',
	[KEY_EJECTCLOSECD]     = 0, //L'0',
	[KEY_NEXTSONG]         = 0, //L'0',
	[KEY_PLAYPAUSE]        = 0, //L'0',
	[KEY_PREVIOUSSONG]     = 0, //L'0',
	[KEY_STOPCD]           = 0, //L'0',
	[KEY_RECORD]           = 0, //L'0',
	[KEY_REWIND]           = 0, //L'0',
	[KEY_PHONE]            = 0, //L'0',
	[KEY_ISO]              = 0, //L'0',
	[KEY_CONFIG]           = 0, //L'0',
	[KEY_HOMEPAGE]         = 0, //L'0',
	[KEY_REFRESH]          = 0, //L'0',
	[KEY_EXIT]             = 0, //L'0',
	[KEY_MOVE]             = 0, //L'0',
	[KEY_EDIT]             = 0, //L'0',
	[KEY_SCROLLUP]         = 0, //L'0',
	[KEY_SCROLLDOWN]       = 0, //L'0',
	[KEY_KPLEFTPAREN]      = L'(',
	[KEY_KPRIGHTPAREN]     = L')',
	[KEY_NEW]              = 0, //L'0',
	[KEY_REDO]             = 0, //L'0',

	[KEY_F13]              = 0, //L'0',
	[KEY_F14]              = 0, //L'0',
	[KEY_F15]              = 0, //L'0',
	[KEY_F16]              = 0, //L'0',
	[KEY_F17]              = 0, //L'0',
	[KEY_F18]              = 0, //L'0',
	[KEY_F19]              = 0, //L'0',
	[KEY_F20]              = 0, //L'0',
	[KEY_F21]              = 0, //L'0',
	[KEY_F22]              = 0, //L'0',
	[KEY_F23]              = 0, //L'0',
	[KEY_F24]              = 0, //L'0',

	[KEY_PLAYCD]           = 0, //L'0',
	[KEY_PAUSECD]          = 0, //L'0',
	[KEY_PROG3]            = 0, //L'0',
	[KEY_PROG4]            = 0, //L'0',
	[KEY_DASHBOARD]        = 0, //L'0',
	[KEY_SUSPEND]          = 0, //L'0',
	[KEY_CLOSE]            = 0, //L'0',
	[KEY_PLAY]             = 0, //L'0',
	[KEY_FASTFORWARD]      = 0, //L'0',
	[KEY_BASSBOOST]        = 0, //L'0',
	[KEY_PRINT]            = 0, //L'0',
	[KEY_HP]               = 0, //L'0',
	[KEY_CAMERA]           = 0, //L'0',
	[KEY_SOUND]            = 0, //L'0',
	[KEY_QUESTION]         = 0, //L'0',
	[KEY_EMAIL]            = 0, //L'0',
	[KEY_CHAT]             = 0, //L'0',
	[KEY_SEARCH]           = 0, //L'0',
	[KEY_CONNECT]          = 0, //L'0',
	[KEY_FINANCE]          = 0, //L'0',
	[KEY_SPORT]            = 0, //L'0',
	[KEY_SHOP]             = 0, //L'0',
	[KEY_ALTERASE]         = 0, //L'0',
	[KEY_CANCEL]           = 0, //L'0',
	[KEY_BRIGHTNESSDOWN]   = 0, //L'0',
	[KEY_BRIGHTNESSUP]     = 0, //L'0',
	[KEY_MEDIA]            = 0, //L'0',

	[KEY_SWITCHVIDEOMODE]  = 0, //L'0',

	[KEY_KBDILLUMTOGGLE]   = 0, //L'0',
	[KEY_KBDILLUMDOWN]     = 0, //L'0',
	[KEY_KBDILLUMUP]       = 0, //L'0',

	[KEY_SEND]             = 0, //L'0',
	[KEY_REPLY]            = 0, //L'0',
	[KEY_FORWARDMAIL]      = 0, //L'0',
	[KEY_SAVE]             = 0, //L'0',
	[KEY_DOCUMENTS]        = 0, //L'0',

	[KEY_BATTERY]          = 0, //L'0',

	[KEY_BLUETOOTH]        = 0, //L'0',
	[KEY_WLAN]             = 0, //L'0',
	[KEY_UWB]              = 0, //L'0',

	[KEY_UNKNOWN]          = 0, //L'0',

	[KEY_VIDEO_NEXT]       = 0, //L'0',
	[KEY_VIDEO_PREV]       = 0, //L'0',
	[KEY_BRIGHTNESS_CYCLE] = 0, //L'0',
	[KEY_BRIGHTNESS_AUTO]  = 0, //L'0',


	[KEY_DISPLAY_OFF]      = 0, //L'0',

	[KEY_WWAN]             = 0, //L'0',
	[KEY_RFKILL]           = 0, //L'0',

	[KEY_MICMUTE]          = 0, //L'0',
	[KEY_SELECTIVE_SCREENSHOT] = 0,
	[POSLEDNJI]            = 0,
	[LALALALA]            = 0,

};

const uint32_t sr_latin_keymap_shift[0x27d] = {
	[KEY_RESERVED]         = 0,
	[KEY_ESC]              = 0,
	[KEY_1]                = L'!',
	[KEY_2]                = L'"',
	[KEY_3]                = L'#',
	[KEY_4]                = L'$',
	[KEY_5]                = L'%',
	[KEY_6]                = L'&',
	[KEY_7]                = L'/',
	[KEY_8]                = L'(',
	[KEY_9]                = L')',
	[KEY_0]                = L'=',
	[KEY_MINUS]            = L'?',
	[KEY_EQUAL]            = L'*',
	[KEY_BACKSPACE]        = 0, //L'0',
	[KEY_TAB]              = L'\t',
	[KEY_Q]                = L'Q',
	[KEY_W]                = L'W',
	[KEY_E]                = L'E',
	[KEY_R]                = L'R',
	[KEY_T]                = L'T',
	[KEY_Y]                = L'Z',
	[KEY_U]                = L'U',
	[KEY_I]                = L'I',
	[KEY_O]                = L'O',
	[KEY_P]                = L'P',
	[KEY_LEFTBRACE]        = L'Š',
	[KEY_RIGHTBRACE]       = L'Đ',
	[KEY_ENTER]            = L'\n',
	[KEY_LEFTCTRL]         = 0, //L'0',
	[KEY_A]                = L'A',
	[KEY_S]                = L'S',
	[KEY_D]                = L'D',
	[KEY_F]                = L'F',
	[KEY_G]                = L'G',
	[KEY_H]                = L'H',
	[KEY_J]                = L'J',
	[KEY_K]                = L'K',
	[KEY_L]                = L'L',
	[KEY_SEMICOLON]        = L'Č',
	[KEY_APOSTROPHE]       = L'Ć',
	[KEY_GRAVE]            = L'~',
	[KEY_LEFTSHIFT]        = 0, //L'0',
	[KEY_BACKSLASH]        = L'Ž',
	[KEY_Z]                = L'Y',
	[KEY_X]                = L'X',
	[KEY_C]                = L'C',
	[KEY_V]                = L'V',
	[KEY_B]                = L'B',
	[KEY_N]                = L'N',
	[KEY_M]                = L'M',
	[KEY_COMMA]            = L';',
	[KEY_DOT]              = L':',
	[KEY_SLASH]            = L'_',
	[KEY_RIGHTSHIFT]       = 0, //L'0',
	[KEY_KPASTERISK]       = L'*',
	[KEY_LEFTALT]          = 0, //L'0',
	[KEY_SPACE]            = L' ',
	[KEY_CAPSLOCK]         = 0, //L'0',
	[KEY_F1]               = 0, //L'0',
	[KEY_F2]               = 0, //L'0',
	[KEY_F3]               = 0, //L'0',
	[KEY_F4]               = 0, //L'0',
	[KEY_F5]               = 0, //L'0',
	[KEY_F6]               = 0, //L'0',
	[KEY_F7]               = 0, //L'0',
	[KEY_F8]               = 0, //L'0',
	[KEY_F9]               = 0, //L'0',
	[KEY_F10]              = 0, //L'0',
	[KEY_NUMLOCK]          = 0, //L'0',
	[KEY_SCROLLLOCK]       = 0, //L'0',
	[KEY_KP7]              = L'7',
	[KEY_KP8]              = L'8',
	[KEY_KP9]              = L'9',
	[KEY_KPMINUS]          = L'-',
	[KEY_KP4]              = L'4',
	[KEY_KP5]              = L'5',
	[KEY_KP6]              = L'6',
	[KEY_KPPLUS]           = L'+',
	[KEY_KP1]              = L'1',
	[KEY_KP2]              = L'2',
	[KEY_KP3]              = L'3',
	[KEY_KP0]              = L'0',
	[KEY_KPDOT]            = L'.',

	[KEY_102ND]            = L'>',
	[KEY_F11]              = 0, //L'0',
	[KEY_F12]              = 0, //L'0',
	[KEY_RIGHTCTRL]        = 0, //L'0',
	[KEY_KPSLASH]          = L'/',
	[KEY_SYSRQ]            = 0, //L'0', // PrtSc
	[KEY_RIGHTALT]         = 0, //L'0',
	[KEY_LINEFEED]         = L'\n',
	[KEY_HOME]             = 0, //L'0',
	[KEY_UP]               = 0, //L'0',
	[KEY_PAGEUP]           = 0, //L'0',
	[KEY_LEFT]             = 0, //L'0',
	[KEY_RIGHT]            = 0, //L'0',
	[KEY_END]              = 0, //L'0',
	[KEY_DOWN]             = 0, //L'0',
	[KEY_PAGEDOWN]         = 0, //L'0',
	[KEY_INSERT]           = 0, //L'0',
	[KEY_DELETE]           = 0, //L'0',
	[KEY_MACRO]            = 0, //L'0',
	[KEY_MUTE]             = 0, //L'0',
	[KEY_VOLUMEDOWN]       = 0, //L'0',
	[KEY_VOLUMEUP]         = 0, //L'0',
	[KEY_POWER]            = 0, //L'0',
	[KEY_KPEQUAL]          = L'=',
	[KEY_KPPLUSMINUS]      = L'±',
	[KEY_PAUSE]            = 0, //L'0',
	[KEY_SCALE]            = 0, //L'0',

	[KEY_KPCOMMA]          = L',',
	[KEY_LEFTMETA]         = 0, //L'0',
	[KEY_RIGHTMETA]        = 0, //L'0',
	[KEY_COMPOSE]          = 0, //L'0',

	[KEY_STOP]             = 0, //L'0',
	[KEY_AGAIN]            = 0, //L'0',
	[KEY_PROPS]            = 0, //L'0',
	[KEY_UNDO]             = 0, //L'0',
	[KEY_FRONT]            = 0, //L'0',
	[KEY_COPY]             = 0, //L'0',
	[KEY_OPEN]             = 0, //L'0',
	[KEY_PASTE]            = 0, //L'0',
	[KEY_FIND]             = 0, //L'0',
	[KEY_CUT]              = 0, //L'0',
	[KEY_HELP]             = 0, //L'0',
	[KEY_MENU]             = 0, //L'0',
	[KEY_CALC]             = 0, //L'0',
	[KEY_SETUP]            = 0, //L'0',
	[KEY_SLEEP]            = 0, //L'0',
	[KEY_WAKEUP]           = 0, //L'0',
	[KEY_FILE]             = 0, //L'0',
	[KEY_SENDFILE]         = 0, //L'0',
	[KEY_DELETEFILE]       = 0, //L'0',
	[KEY_XFER]             = 0, //L'0',
	[KEY_PROG1]            = 0, //L'0',
	[KEY_PROG2]            = 0, //L'0',
	[KEY_WWW]              = 0, //L'0',
	[KEY_MSDOS]            = 0, //L'0',
	[KEY_COFFEE]           = 0, //L'0',
	[KEY_ROTATE_DISPLAY]   = 0, //L'0',
	[KEY_CYCLEWINDOWS]     = 0, //L'0',
	[KEY_MAIL]             = 0, //L'0',
	[KEY_BOOKMARKS]        = 0, //L'0',
	[KEY_COMPUTER]         = 0, //L'0',
	[KEY_BACK]             = 0, //L'0',
	[KEY_FORWARD]          = 0, //L'0',
	[KEY_CLOSECD]          = 0, //L'0',
	[KEY_EJECTCD]          = 0, //L'0',
	[KEY_EJECTCLOSECD]     = 0, //L'0',
	[KEY_NEXTSONG]         = 0, //L'0',
	[KEY_PLAYPAUSE]        = 0, //L'0',
	[KEY_PREVIOUSSONG]     = 0, //L'0',
	[KEY_STOPCD]           = 0, //L'0',
	[KEY_RECORD]           = 0, //L'0',
	[KEY_REWIND]           = 0, //L'0',
	[KEY_PHONE]            = 0, //L'0',
	[KEY_ISO]              = 0, //L'0',
	[KEY_CONFIG]           = 0, //L'0',
	[KEY_HOMEPAGE]         = 0, //L'0',
	[KEY_REFRESH]          = 0, //L'0',
	[KEY_EXIT]             = 0, //L'0',
	[KEY_MOVE]             = 0, //L'0',
	[KEY_EDIT]             = 0, //L'0',
	[KEY_SCROLLUP]         = 0, //L'0',
	[KEY_SCROLLDOWN]       = 0, //L'0',
	[KEY_KPLEFTPAREN]      = L'(',
	[KEY_KPRIGHTPAREN]     = L')',
	[KEY_NEW]              = 0, //L'0',
	[KEY_REDO]             = 0, //L'0',

	[KEY_F13]              = 0, //L'0',
	[KEY_F14]              = 0, //L'0',
	[KEY_F15]              = 0, //L'0',
	[KEY_F16]              = 0, //L'0',
	[KEY_F17]              = 0, //L'0',
	[KEY_F18]              = 0, //L'0',
	[KEY_F19]              = 0, //L'0',
	[KEY_F20]              = 0, //L'0',
	[KEY_F21]              = 0, //L'0',
	[KEY_F22]              = 0, //L'0',
	[KEY_F23]              = 0, //L'0',
	[KEY_F24]              = 0, //L'0',

	[KEY_PLAYCD]           = 0, //L'0',
	[KEY_PAUSECD]          = 0, //L'0',
	[KEY_PROG3]            = 0, //L'0',
	[KEY_PROG4]            = 0, //L'0',
	[KEY_DASHBOARD]        = 0, //L'0',
	[KEY_SUSPEND]          = 0, //L'0',
	[KEY_CLOSE]            = 0, //L'0',
	[KEY_PLAY]             = 0, //L'0',
	[KEY_FASTFORWARD]      = 0, //L'0',
	[KEY_BASSBOOST]        = 0, //L'0',
	[KEY_PRINT]            = 0, //L'0',
	[KEY_HP]               = 0, //L'0',
	[KEY_CAMERA]           = 0, //L'0',
	[KEY_SOUND]            = 0, //L'0',
	[KEY_QUESTION]         = 0, //L'0',
	[KEY_EMAIL]            = 0, //L'0',
	[KEY_CHAT]             = 0, //L'0',
	[KEY_SEARCH]           = 0, //L'0',
	[KEY_CONNECT]          = 0, //L'0',
	[KEY_FINANCE]          = 0, //L'0',
	[KEY_SPORT]            = 0, //L'0',
	[KEY_SHOP]             = 0, //L'0',
	[KEY_ALTERASE]         = 0, //L'0',
	[KEY_CANCEL]           = 0, //L'0',
	[KEY_BRIGHTNESSDOWN]   = 0, //L'0',
	[KEY_BRIGHTNESSUP]     = 0, //L'0',
	[KEY_MEDIA]            = 0, //L'0',

	[KEY_SWITCHVIDEOMODE]  = 0, //L'0',

	[KEY_KBDILLUMTOGGLE]   = 0, //L'0',
	[KEY_KBDILLUMDOWN]     = 0, //L'0',
	[KEY_KBDILLUMUP]       = 0, //L'0',

	[KEY_SEND]             = 0, //L'0',
	[KEY_REPLY]            = 0, //L'0',
	[KEY_FORWARDMAIL]      = 0, //L'0',
	[KEY_SAVE]             = 0, //L'0',
	[KEY_DOCUMENTS]        = 0, //L'0',

	[KEY_BATTERY]          = 0, //L'0',

	[KEY_BLUETOOTH]        = 0, //L'0',
	[KEY_WLAN]             = 0, //L'0',
	[KEY_UWB]              = 0, //L'0',

	[KEY_UNKNOWN]          = 0, //L'0',

	[KEY_VIDEO_NEXT]       = 0, //L'0',
	[KEY_VIDEO_PREV]       = 0, //L'0',
	[KEY_BRIGHTNESS_CYCLE] = 0, //L'0',
	[KEY_BRIGHTNESS_AUTO]  = 0, //L'0',


	[KEY_DISPLAY_OFF]      = 0, //L'0',

	[KEY_WWAN]             = 0, //L'0',
	[KEY_RFKILL]           = 0, //L'0',

	[KEY_MICMUTE]          = 0, //L'0',
	[KEY_SELECTIVE_SCREENSHOT] = 0,
	[POSLEDNJI]            = 0,
	[LALALALA]            = 0,

};

const uint32_t sr_latin_keymap_altgr[0x27d] = {
	[KEY_RESERVED]         = 0,
	[KEY_ESC]              = 0,
	[KEY_1]                = L'~',
	[KEY_2]                = L'ˇ',
	[KEY_3]                = L'^',
	[KEY_4]                = L'˘',
	[KEY_5]                = L'°',
	[KEY_6]                = L'˛',
	[KEY_7]                = L'`',
	[KEY_8]                = L'˙',
	[KEY_9]                = L'´',
	[KEY_0]                = L'˝',
	[KEY_MINUS]            = L'¨',
	[KEY_EQUAL]            = L'¸',
	[KEY_BACKSPACE]        = 0, //L'0',
	[KEY_TAB]              = L'\t',
	[KEY_Q]                = L'\\',
	[KEY_W]                = L'|',
	[KEY_E]                = L'€',
	[KEY_R]                = L'¶',
	[KEY_T]                = L'ŧ',
	[KEY_Y]                = L'←',
	[KEY_U]                = L'↓',
	[KEY_I]                = L'→',
	[KEY_O]                = L'ø',
	[KEY_P]                = L'p',
	[KEY_LEFTBRACE]        = L'÷',
	[KEY_RIGHTBRACE]       = L'×',
	[KEY_ENTER]            = L'\n',
	[KEY_LEFTCTRL]         = 0, //L'0',
	[KEY_A]                = L'æ',
	[KEY_S]                = L'„',
	[KEY_D]                = L'“',
	[KEY_F]                = L'[',
	[KEY_G]                = L']',
	[KEY_H]                = L'ħ',
	[KEY_J]                = L'j',
	[KEY_K]                = L'k',
	[KEY_L]                = L'ł',
	[KEY_SEMICOLON]        = L'č',
	[KEY_APOSTROPHE]       = L'ß',
	[KEY_GRAVE]            = L'`',
	[KEY_LEFTSHIFT]        = 0, //L'0',
	[KEY_BACKSLASH]        = L'¤',
	[KEY_Z]                = L'‘',
	[KEY_X]                = L'’',
	[KEY_C]                = L'¢',
	[KEY_V]                = L'@',
	[KEY_B]                = L'{',
	[KEY_N]                = L'}',
	[KEY_M]                = L'§',
	[KEY_COMMA]            = L'<',
	[KEY_DOT]              = L'>',
	[KEY_SLASH]            = L'—',
	[KEY_RIGHTSHIFT]       = 0, //L'0',
	[KEY_KPASTERISK]       = L'*',
	[KEY_LEFTALT]          = 0, //L'0',
	[KEY_SPACE]            = L' ',
	[KEY_CAPSLOCK]         = 0, //L'0',
	[KEY_F1]               = 0, //L'0',
	[KEY_F2]               = 0, //L'0',
	[KEY_F3]               = 0, //L'0',
	[KEY_F4]               = 0, //L'0',
	[KEY_F5]               = 0, //L'0',
	[KEY_F6]               = 0, //L'0',
	[KEY_F7]               = 0, //L'0',
	[KEY_F8]               = 0, //L'0',
	[KEY_F9]               = 0, //L'0',
	[KEY_F10]              = 0, //L'0',
	[KEY_NUMLOCK]          = 0, //L'0',
	[KEY_SCROLLLOCK]       = 0, //L'0',
	[KEY_KP7]              = L'7',
	[KEY_KP8]              = L'8',
	[KEY_KP9]              = L'9',
	[KEY_KPMINUS]          = L'-',
	[KEY_KP4]              = L'4',
	[KEY_KP5]              = L'5',
	[KEY_KP6]              = L'6',
	[KEY_KPPLUS]           = L'+',
	[KEY_KP1]              = L'1',
	[KEY_KP2]              = L'2',
	[KEY_KP3]              = L'3',
	[KEY_KP0]              = L'0',
	[KEY_KPDOT]            = L'.',

	[KEY_102ND]            = L'‘',
	[KEY_F11]              = 0, //L'0',
	[KEY_F12]              = 0, //L'0',
	[KEY_RIGHTCTRL]        = 0, //L'0',
	[KEY_KPSLASH]          = L'/',
	[KEY_SYSRQ]            = 0, //L'0', // PrtSc
	[KEY_RIGHTALT]         = 0, //L'0',
	[KEY_LINEFEED]         = L'\n',
	[KEY_HOME]             = 0, //L'0',
	[KEY_UP]               = 0, //L'0',
	[KEY_PAGEUP]           = 0, //L'0',
	[KEY_LEFT]             = 0, //L'0',
	[KEY_RIGHT]            = 0, //L'0',
	[KEY_END]              = 0, //L'0',
	[KEY_DOWN]             = 0, //L'0',
	[KEY_PAGEDOWN]         = 0, //L'0',
	[KEY_INSERT]           = 0, //L'0',
	[KEY_DELETE]           = 0, //L'0',
	[KEY_MACRO]            = 0, //L'0',
	[KEY_MUTE]             = 0, //L'0',
	[KEY_VOLUMEDOWN]       = 0, //L'0',
	[KEY_VOLUMEUP]         = 0, //L'0',
	[KEY_POWER]            = 0, //L'0',
	[KEY_KPEQUAL]          = L'=',
	[KEY_KPPLUSMINUS]      = L'±',
	[KEY_PAUSE]            = 0, //L'0',
	[KEY_SCALE]            = 0, //L'0',

	[KEY_KPCOMMA]          = L',',
	[KEY_LEFTMETA]         = 0, //L'0',
	[KEY_RIGHTMETA]        = 0, //L'0',
	[KEY_COMPOSE]          = 0, //L'0',

	[KEY_STOP]             = 0, //L'0',
	[KEY_AGAIN]            = 0, //L'0',
	[KEY_PROPS]            = 0, //L'0',
	[KEY_UNDO]             = 0, //L'0',
	[KEY_FRONT]            = 0, //L'0',
	[KEY_COPY]             = 0, //L'0',
	[KEY_OPEN]             = 0, //L'0',
	[KEY_PASTE]            = 0, //L'0',
	[KEY_FIND]             = 0, //L'0',
	[KEY_CUT]              = 0, //L'0',
	[KEY_HELP]             = 0, //L'0',
	[KEY_MENU]             = 0, //L'0',
	[KEY_CALC]             = 0, //L'0',
	[KEY_SETUP]            = 0, //L'0',
	[KEY_SLEEP]            = 0, //L'0',
	[KEY_WAKEUP]           = 0, //L'0',
	[KEY_FILE]             = 0, //L'0',
	[KEY_SENDFILE]         = 0, //L'0',
	[KEY_DELETEFILE]       = 0, //L'0',
	[KEY_XFER]             = 0, //L'0',
	[KEY_PROG1]            = 0, //L'0',
	[KEY_PROG2]            = 0, //L'0',
	[KEY_WWW]              = 0, //L'0',
	[KEY_MSDOS]            = 0, //L'0',
	[KEY_COFFEE]           = 0, //L'0',
	[KEY_ROTATE_DISPLAY]   = 0, //L'0',
	[KEY_CYCLEWINDOWS]     = 0, //L'0',
	[KEY_MAIL]             = 0, //L'0',
	[KEY_BOOKMARKS]        = 0, //L'0',
	[KEY_COMPUTER]         = 0, //L'0',
	[KEY_BACK]             = 0, //L'0',
	[KEY_FORWARD]          = 0, //L'0',
	[KEY_CLOSECD]          = 0, //L'0',
	[KEY_EJECTCD]          = 0, //L'0',
	[KEY_EJECTCLOSECD]     = 0, //L'0',
	[KEY_NEXTSONG]         = 0, //L'0',
	[KEY_PLAYPAUSE]        = 0, //L'0',
	[KEY_PREVIOUSSONG]     = 0, //L'0',
	[KEY_STOPCD]           = 0, //L'0',
	[KEY_RECORD]           = 0, //L'0',
	[KEY_REWIND]           = 0, //L'0',
	[KEY_PHONE]            = 0, //L'0',
	[KEY_ISO]              = 0, //L'0',
	[KEY_CONFIG]           = 0, //L'0',
	[KEY_HOMEPAGE]         = 0, //L'0',
	[KEY_REFRESH]          = 0, //L'0',
	[KEY_EXIT]             = 0, //L'0',
	[KEY_MOVE]             = 0, //L'0',
	[KEY_EDIT]             = 0, //L'0',
	[KEY_SCROLLUP]         = 0, //L'0',
	[KEY_SCROLLDOWN]       = 0, //L'0',
	[KEY_KPLEFTPAREN]      = L'(',
	[KEY_KPRIGHTPAREN]     = L')',
	[KEY_NEW]              = 0, //L'0',
	[KEY_REDO]             = 0, //L'0',

	[KEY_F13]              = 0, //L'0',
	[KEY_F14]              = 0, //L'0',
	[KEY_F15]              = 0, //L'0',
	[KEY_F16]              = 0, //L'0',
	[KEY_F17]              = 0, //L'0',
	[KEY_F18]              = 0, //L'0',
	[KEY_F19]              = 0, //L'0',
	[KEY_F20]              = 0, //L'0',
	[KEY_F21]              = 0, //L'0',
	[KEY_F22]              = 0, //L'0',
	[KEY_F23]              = 0, //L'0',
	[KEY_F24]              = 0, //L'0',

	[KEY_PLAYCD]           = 0, //L'0',
	[KEY_PAUSECD]          = 0, //L'0',
	[KEY_PROG3]            = 0, //L'0',
	[KEY_PROG4]            = 0, //L'0',
	[KEY_DASHBOARD]        = 0, //L'0',
	[KEY_SUSPEND]          = 0, //L'0',
	[KEY_CLOSE]            = 0, //L'0',
	[KEY_PLAY]             = 0, //L'0',
	[KEY_FASTFORWARD]      = 0, //L'0',
	[KEY_BASSBOOST]        = 0, //L'0',
	[KEY_PRINT]            = 0, //L'0',
	[KEY_HP]               = 0, //L'0',
	[KEY_CAMERA]           = 0, //L'0',
	[KEY_SOUND]            = 0, //L'0',
	[KEY_QUESTION]         = 0, //L'0',
	[KEY_EMAIL]            = 0, //L'0',
	[KEY_CHAT]             = 0, //L'0',
	[KEY_SEARCH]           = 0, //L'0',
	[KEY_CONNECT]          = 0, //L'0',
	[KEY_FINANCE]          = 0, //L'0',
	[KEY_SPORT]            = 0, //L'0',
	[KEY_SHOP]             = 0, //L'0',
	[KEY_ALTERASE]         = 0, //L'0',
	[KEY_CANCEL]           = 0, //L'0',
	[KEY_BRIGHTNESSDOWN]   = 0, //L'0',
	[KEY_BRIGHTNESSUP]     = 0, //L'0',
	[KEY_MEDIA]            = 0, //L'0',

	[KEY_SWITCHVIDEOMODE]  = 0, //L'0',

	[KEY_KBDILLUMTOGGLE]   = 0, //L'0',
	[KEY_KBDILLUMDOWN]     = 0, //L'0',
	[KEY_KBDILLUMUP]       = 0, //L'0',

	[KEY_SEND]             = 0, //L'0',
	[KEY_REPLY]            = 0, //L'0',
	[KEY_FORWARDMAIL]      = 0, //L'0',
	[KEY_SAVE]             = 0, //L'0',
	[KEY_DOCUMENTS]        = 0, //L'0',

	[KEY_BATTERY]          = 0, //L'0',

	[KEY_BLUETOOTH]        = 0, //L'0',
	[KEY_WLAN]             = 0, //L'0',
	[KEY_UWB]              = 0, //L'0',

	[KEY_UNKNOWN]          = 0, //L'0',

	[KEY_VIDEO_NEXT]       = 0, //L'0',
	[KEY_VIDEO_PREV]       = 0, //L'0',
	[KEY_BRIGHTNESS_CYCLE] = 0, //L'0',
	[KEY_BRIGHTNESS_AUTO]  = 0, //L'0',


	[KEY_DISPLAY_OFF]      = 0, //L'0',

	[KEY_WWAN]             = 0, //L'0',
	[KEY_RFKILL]           = 0, //L'0',

	[KEY_MICMUTE]          = 0, //L'0',
	[KEY_SELECTIVE_SCREENSHOT] = 0,
	[POSLEDNJI]            = 0,
	[LALALALA]            = 0,

};