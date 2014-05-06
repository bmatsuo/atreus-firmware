// numbers under 100: normal keys
// numbers between 99 and 200: shifted keys
// numbers between 199 and 300: function pre-invocations
// numbers over 300: function invocations

#define ROW_COUNT 4
#define COL_COUNT 11
#define KEY_COUNT ROW_COUNT*COL_COUNT

// TODO: use usb_keyboard.h constants here
int base_layer[KEY_COUNT] =
  { 20, 26, 8,   21,  23,  0,  28, 24, 12, 18, 19,
    4,  22, 7,   9,   10,  0,  11, 13, 14, 15, 51,
    29, 27, 6,   25,  5,  104, 17, 16, 54, 55, 56,
    41, 43, 108, 102, 42, 101, 44, 201, 52, 47, 40 };

int fn_layer[KEY_COUNT] =
  { 108+30, 108+31, 108+45, 108+46, 108 + 49, 0, 75, 36, 37, 38, 108+37,
    108+32, 108+33, 108+38, 108+39, 53, 0, 78, 33, 34, 35, 108+48,
    108 + 34, 108 + 35, 45, 46, 108+53, 104, 49, 30, 31, 32, 108+47,
    200, 108 + 73, 108, 102, 302, 101, 0, 0, 8, 39, 48 };

// insert, home, end, delete

int bonus_layer[KEY_COUNT] =
  { KEY_HOME,  KEY_UP,  KEY_END, 0, 0, 0, KEY_F7, KEY_F8, KEY_F9, KEY_F10,
    KEY_LEFT, KEY_DOWN, KEY_RIGHT, 0, 0, 0, KEY_F4, KEY_F5, KEY_F6, KEY_F11,
    KEY_INSERT, KEY_DELETE,  0, 0, 0, 0, KEY_F1, KEY_F2, KEY_F3, KEY_F12,
    302, 0, 108, 102, 42, 101, 44, 0, 0, 0, 0 };

int *layers[] = {base_layer, fn_layer, bonus_layer};

int fn_decay = 0;

void activate_fn() {
  fn_decay = 10;
};

void toggle_fn() {
  if(!current_layer_number) {
    current_layer_number = 2;
  } else {
    current_layer_number = 0;
  };
};

void (*layer_functions[])(void) = {reset, activate_fn, toggle_fn};

void per_cycle() {
  if(fn_decay) {
    current_layer = layers[1];
    fn_decay--;
  }
};