#include <interception.h>
#include <utils.h>

#include <iostream>

enum ScanCode {
  SC_ESCAPE = 1,          //
  SC_1 = 2,               //
  SC_2 = 3,               //
  SC_3 = 4,               //
  SC_4 = 5,               //
  SC_5 = 6,               //
  SC_6 = 7,               //
  SC_7 = 8,               //
  SC_8 = 9,               //
  SC_9 = 10,              //
  SC_0 = 11,              //
  SC_MINUS = 12,          // -
  SC_EQUALS = 13,         // =
  SC_BACKSPACE = 14,      //
  SC_TAB = 15,            //
  SC_Q = 16,              //
  SC_W = 17,              //
  SC_E = 18,              //
  SC_R = 19,              //
  SC_T = 20,              //
  SC_Y = 21,              //
  SC_U = 22,              //
  SC_I = 23,              //
  SC_O = 24,              //
  SC_P = 25,              //
  SC_LBRACK = 26,         // [
  SC_RBRACK = 27,         // ]
  SC_RETURN = 28,         //
  SC_LCTRL = 29,          //
  SC_A = 30,              //
  SC_S = 31,              //
  SC_D = 32,              //
  SC_F = 33,              //
  SC_G = 34,              //
  SC_H = 35,              //
  SC_J = 36,              //
  SC_K = 37,              //
  SC_L = 38,              //
  SC_SEMI = 39,           // ;
  SC_APOS = 40,           // '
  SC_GRAVE = 41,          // `
  SC_LSHIFT = 42,         //
  SC_BSLASH = 43,         //
  SC_Z = 44,              //
  SC_X = 45,              //
  SC_C = 46,              //
  SC_V = 47,              //
  SC_B = 48,              //
  SC_N = 49,              //
  SC_M = 50,              //
  SC_COMMA = 51,          //
  SC_DOT = 52,            // .
  SC_SLASH = 53,          // /
  SC_RSHIFT = 54,         //
  SC_NPMULT = 55,         // *
  SC_LALT = 56,           //
  SC_SPACE = 57,          //
  SC_CAPSLOCK = 58,       //
  SC_F1 = 59,             //
  SC_F2 = 60,             //
  SC_F3 = 61,             //
  SC_F4 = 62,             //
  SC_F5 = 63,             //
  SC_F6 = 64,             //
  SC_F7 = 65,             //
  SC_F8 = 66,             //
  SC_F9 = 67,             //
  SC_F10 = 68,            //
  SC_NUMLOCK = 69,        //
  SC_SCRLOCK = 70,        //
  SC_NP7 = 71,            //
  SC_NP8 = 72,            //
  SC_NP9 = 73,            //
  SC_NPSUB = 74,          //
  SC_NP4 = 75,            //
  SC_NP5 = 76,            //
  SC_NP6 = 77,            //
  SC_NPADD = 78,          //
  SC_NP1 = 79,            //
  SC_NP2 = 80,            //
  SC_NP3 = 81,            //
  SC_NP0 = 82,            //
  SC_NPDOT = 83,          //
  SC_ALTPRINT = 84,       // created by Alt+Print
  SC_LBSLASH = 86,        //  Left BackSlash \  or < > |  right of left shift on UK/Germany keyboards
  SC_F11 = 87,            //
  SC_F12 = 88,            //
  SC_NPEQUALS1 = 89,      // Numpad [=] on Apple
  SC_LWIN = 91,           //
  SC_RWIN = 92,           //
  SC_APPLICATION = 93,    //
  SC_F13 = 100,           //           (NEC PC98)
  SC_F14 = 101,           //           (NEC PC98)
  SC_F15 = 102,           //           (NEC PC98)
  SC_F16 = 103,           // Apple KB
  SC_F17 = 104,           //
  SC_F18 = 105,           //
  SC_F19 = 106,           //
  SC_F20 = 107,           //
  SC_F21 = 108,           //
  SC_F22 = 109,           //
  SC_F23 = 110,           //
  SC_KANA = 112,          // (Japanese keyboard)
  SC_LANG2 = 113,         // (Korean 'Hanja key' according to Firefox spec)
  SC_LANG1 = 114,         // (Korean 'Han/Yeong key' according to Firefox spec)
  SC_ABNT_C1 = 115,       // / ? on Portugese (Brazilian) keyboards
  SC_CONVERT = 121,       // (Japanese keyboard)
  SC_NOCONVERT = 123,     // (Japanese keyboard)
  SC_YEN = 125,           // (Japanese keyboard)
  SC_ABNT_C2 = 126,       // Numpad . on Portugese (Brazilian) keyboards
  SC_NPEQUALS2 = 141,     // = NaN numeric keypad (NEC PC98)
  SC_PREVTRACK = 144,     // Previous Track (CIRCUMFLEX on Japanese keyboard)
  SC_AT = 145,            //           (NEC PC98)
  SC_COLON = 146,         //           (NEC PC98)
  SC_UNDERLINE = 147,     //           (NEC PC98)
  SC_KANJI = 148,         // (Japanese keyboard)
  SC_STOP = 149,          //           (NEC PC98)
  SC_AX = 150,            //           (Japan AX)
  SC_UNLABELED = 151,     //            (J3100)
  SC_NEXTTRACK = 153,     // Next Track
  SC_NPRET = 156,         // Enter on numeric keypad
  SC_RCTRL = 157,         //
  SC_MUTE = 160,          // Mute
  SC_CALCULATOR = 161,    // Calculator
  SC_PLAYPAUSE = 162,     // Play / Pause
  SC_MEDIASTOP = 164,     // Media Stop
  SC_E0LSHF = 170,        // produced by Print key without modifier.
  SC_VOLUMEDOWN = 174,    // Volume -
  SC_VOLUMEUP = 176,      // Volume +
  SC_WEBHOME = 178,       // Web home
  SC_NUMPADCOMMA = 179,   // , on numeric keypad (NEC PC98)
  SC_DIVIDE = 181,        // / on numeric keypad
  SC_PRINT = 183,         // Print aka SysRq, wrapped in E0 2A (fake LShift) when no modifiers down
  SC_RALT = 184,          // right Alt
  SC_BREAK = 198,         // Produced by Ctrl+Pause
  SC_HOME = 199,          // Home on arrow keypad
  SC_UP = 200,            // UpArrow on arrow keypad
  SC_PGUP = 201,          // PgUp on arrow keypad
  SC_LEFT = 203,          // LeftArrow on arrow keypad
  SC_RIGHT = 205,         // RightArrow on arrow keypad
  SC_END = 207,           // End on arrow keypad
  SC_DOWN = 208,          // DownArrow on arrow keypad
  SC_PGDOWN = 209,        // PgDn on arrow keypad
  SC_INSERT = 210,        // Insert on arrow keypad
  SC_DELETE = 211,        // Delete on arrow keypad
  SC_APPS = 221,          // AppMenu key
  SC_POWER = 222,         // System Power
  SC_SLEEP = 223,         // System Sleep
  SC_WAKE = 227,          // System Wake
  SC_WEBSEARCH = 229,     // Web Search
  SC_WEBFAVORITES = 230,  // Web Favorites
  SC_WEBREFRESH = 231,    // Web Refresh
  SC_WEBSTOP = 232,       // Web Stop
  SC_WEBFORWARD = 233,    // Web Forward
  SC_WEBBACK = 234,       // Web Back
  SC_MYCOMPUTER = 235,    // My Computer
  SC_MAIL = 236,          // Mail
  SC_MEDIASELECT = 237,   // Media Select
  SC_LEFT_E = 0xE04B,
  SC_UP_E = 0xE048,
  SC_DOWN_E = 0xE050,
  SC_RIGHT_E = 0xE04D,
  SC_HOME_E = 0xE047,
  SC_END_E = 0xE04F,
};

enum ModState {
  MS_DEFAULT,
  MS_RMETA,
  MS_LMETA,
  MS_RMETA_ACTIVE,
  MS_LMETA_ACTIVE,
  MS_TASK_SWITCHER,
  MS_CAPSLOCK,
  MS_CAPSLOCK_AS_CTRL_ACTIVE,
};

enum Side { S_NONE, S_RIGHT, S_LEFT };

void send(InterceptionContext context, InterceptionDevice device, unsigned short code, unsigned short state) {
  InterceptionKeyStroke stroke;
  stroke.code = code;
  stroke.state = state;
  stroke.information = 0;
  interception_send(context, device, (InterceptionStroke *)&stroke, 1);
}

void stroke_send(InterceptionContext context, InterceptionDevice device, unsigned short code, char offset = 0) {
  send(context, device, code, 0 + offset);
  send(context, device, code, 1 + offset);
}

int main() {
  using namespace std;

  InterceptionContext context;
  InterceptionDevice device;
  InterceptionStroke stroke;

  raise_process_priority();

  context = interception_create_context();

  interception_set_filter(context, interception_is_keyboard,
                          INTERCEPTION_FILTER_KEY_DOWN | INTERCEPTION_FILTER_KEY_UP | INTERCEPTION_FILTER_KEY_E0 |
                              INTERCEPTION_FILTER_KEY_E1);
  interception_set_filter(context, interception_is_mouse, INTERCEPTION_FILTER_MOUSE_LEFT_BUTTON_DOWN);

  unsigned char modState = MS_DEFAULT;
  bool isRShift = false;
  bool isLShift = false;

  while (interception_receive(context, device = interception_wait(context), &stroke, 1) > 0) {
    if (interception_is_keyboard(device)) {
      InterceptionKeyStroke &keystroke = *(InterceptionKeyStroke *)&stroke;
      // cout << keystroke.code << "," << keystroke.state << endl;
      switch (modState) {
        case MS_DEFAULT:
          switch (keystroke.code) {
            case SC_LALT:
              if (keystroke.state == 0) {
                modState = MS_LMETA;
              } else if (keystroke.state == 2) {
                modState = MS_RMETA;
              }
              break;
            case SC_CAPSLOCK:
              modState = MS_CAPSLOCK;
              break;
            case SC_LWIN:
              send(context, device, SC_LALT, keystroke.state % 2);
              break;
            case SC_RWIN:
            case SC_APPLICATION:
              send(context, device, SC_LALT, keystroke.state % 2 + 2);
              break;
            default:
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
        case MS_RMETA:
          switch (keystroke.code) {
            case SC_LALT:
              if (keystroke.state == 3) {
                modState = MS_DEFAULT;
                stroke_send(context, device, SC_F13);
              }
              break;
            case SC_LWIN:
              send(context, device, SC_LALT, keystroke.state % 2);
              break;
            case SC_RWIN:
            case SC_APPLICATION:
              send(context, device, SC_LALT, keystroke.state % 2 + 2);
              break;
            default:
              modState = MS_RMETA_ACTIVE;
              send(context, device, SC_RCTRL, 0);
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
        case MS_LMETA:
          switch (keystroke.code) {
            case SC_LALT:
              if (keystroke.state == 1) {
                modState = MS_DEFAULT;
                stroke_send(context, device, SC_F14);
              }
              break;
            case SC_TAB:
              modState = MS_TASK_SWITCHER;
              send(context, device, SC_LALT, 0);
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
              break;
            case SC_H:
              if (keystroke.state == 0) {
                send(context, device, SC_LWIN, 2);
                send(context, device, SC_DOWN_E, 2);
                send(context, device, SC_DOWN_E, 3);
                send(context, device, SC_LWIN, 3);
              }
              break;
            case SC_Q:
              if (keystroke.state == 0) {
                send(context, device, SC_LALT, 0);
                send(context, device, SC_F4, 0);
                send(context, device, SC_F4, 1);
                send(context, device, SC_LALT, 1);
              }
              break;
            case SC_SPACE:
              if (keystroke.state == 0) {
                stroke_send(context, device, SC_LWIN, 2);
              }
              break;
            case SC_LWIN:
              send(context, device, SC_LALT, keystroke.state % 2);
              break;
            case SC_RWIN:
            case SC_APPLICATION:
              send(context, device, SC_LALT, keystroke.state % 2 + 2);
              break;
            default:
              modState = MS_LMETA_ACTIVE;
              if (keystroke.code == SC_LSHIFT) {
                isLShift = true;
              }
              if (keystroke.code == SC_RSHIFT) {
                isRShift = true;
              }
              send(context, device, SC_LCTRL, 0);
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
        case MS_RMETA_ACTIVE:
          switch (keystroke.code) {
            case SC_LALT:
              if (keystroke.state == 3) {
                send(context, device, SC_RCTRL, 1);
                modState = MS_DEFAULT;
              }
              break;
            case SC_LWIN:
              send(context, device, SC_LALT, keystroke.state % 2);
              break;
            case SC_RWIN:
            case SC_APPLICATION:
              send(context, device, SC_LALT, keystroke.state % 2 + 2);
              break;
            default:
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
        case MS_LMETA_ACTIVE:
          switch (keystroke.code) {
            case SC_LALT:
              if (keystroke.state == 1) {
                send(context, device, SC_LCTRL, 1);
                isLShift = isRShift = false;
                modState = MS_DEFAULT;
              }
              break;
            case SC_LWIN:
              send(context, device, SC_LALT, keystroke.state % 2);
              break;
            case SC_RWIN:
            case SC_APPLICATION:
              send(context, device, SC_LALT, keystroke.state % 2 + 2);
              break;
            case SC_SPACE:
              if (isRShift || isLShift) {
                if (keystroke.state == 1) {
                  if (isRShift) {
                    send(context, device, SC_RSHIFT, 1);
                  } else if (isLShift) {
                    send(context, device, SC_LSHIFT, 1);
                  }
                  send(context, device, SC_LCTRL, 1);
                  send(context, device, SC_LWIN, 2);
                  send(context, device, SC_V, 0);
                  send(context, device, SC_V, 1);
                  send(context, device, SC_LWIN, 3);
                  send(context, device, SC_LCTRL, 0);
                  if (isRShift) {
                    send(context, device, SC_RSHIFT, 0);
                  } else if (isLShift) {
                    send(context, device, SC_LSHIFT, 0);
                  }
                }
              } else {
                interception_send(context, device, (InterceptionStroke *)&stroke, 1);
              }
              break;
            default:
              if (keystroke.code == SC_LSHIFT) {
                isLShift = keystroke.state == 0;
              }
              if (keystroke.code == SC_RSHIFT) {
                isRShift = keystroke.state == 0;
              }
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
        case MS_TASK_SWITCHER:
          if (keystroke.state == 1 && keystroke.code == SC_LALT) {
            modState = MS_DEFAULT;
          }
          interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          break;
        case MS_CAPSLOCK:
          switch (keystroke.code) {
            case SC_CAPSLOCK:
              if (keystroke.state == 1) {
                modState = MS_DEFAULT;
              }
              break;
            case SC_ESCAPE:
              send(context, device, SC_LCTRL, 1);
              send(context, device, SC_RCTRL, 1);
              send(context, device, SC_LSHIFT, 1);
              send(context, device, SC_RSHIFT, 1);
              send(context, device, SC_LALT, 1);
              send(context, device, SC_LALT, 3);
              interception_destroy_context(context);
              return 0;
            case SC_H:
              send(context, device, SC_LEFT_E, keystroke.state % 2 + 2);
              break;
            case SC_J:
              send(context, device, SC_DOWN_E, keystroke.state % 2 + 2);
              break;
            case SC_K:
              send(context, device, SC_UP_E, keystroke.state % 2 + 2);
              break;
            case SC_L:
              send(context, device, SC_RIGHT_E, keystroke.state % 2 + 2);
              break;
            case SC_A:
              send(context, device, SC_HOME_E, keystroke.state % 2 + 2);
              break;
            case SC_E:
              send(context, device, SC_END_E, keystroke.state % 2 + 2);
              break;
            case SC_D:
              send(context, device, SC_NPDOT, keystroke.state % 2 + 2);
              break;
            case SC_T:
              if (keystroke.state == 0) {
                send(context, device, SC_LCTRL, 0);
                send(context, device, SC_LSHIFT, 0);
                send(context, device, SC_LALT, 0);
                send(context, device, SC_T, 0);
                send(context, device, SC_T, 1);
                send(context, device, SC_LALT, 1);
                send(context, device, SC_LSHIFT, 1);
                send(context, device, SC_LCTRL, 1);
              }
              break;
            case SC_COMMA:
              send(context, device, SC_PREVTRACK, keystroke.state % 2 + 2);
              break;
            case SC_DOT:
              send(context, device, SC_NEXTTRACK, keystroke.state % 2 + 2);
              break;
            case SC_SLASH:
              send(context, device, SC_PLAYPAUSE, keystroke.state % 2 + 2);
              break;
            case SC_LWIN:
              send(context, device, SC_LALT, keystroke.state % 2);
              break;
            case SC_RWIN:
            case SC_APPLICATION:
              send(context, device, SC_LALT, keystroke.state % 2 + 2);
              break;
            case SC_LALT:
              break;
            case SC_LSHIFT:
            case SC_RSHIFT:
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
              break;
            default:
              modState = MS_CAPSLOCK_AS_CTRL_ACTIVE;
              send(context, device, SC_RCTRL, 0);
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
        case MS_CAPSLOCK_AS_CTRL_ACTIVE:
          switch (keystroke.code) {
            case SC_CAPSLOCK:
              if (keystroke.state == 1) {
                send(context, device, SC_RCTRL, 1);
                modState = MS_DEFAULT;
              }
              break;
            default:
              interception_send(context, device, (InterceptionStroke *)&stroke, 1);
          }
          break;
      }
    } else if (interception_is_mouse(device)) {
      interception_send(context, device, &stroke, 1);
    }
  }

  interception_destroy_context(context);

  return 0;
}
