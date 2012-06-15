/* ----------------------------------------------------------------------------
 * ergoDOX layout : QWERTY
 *
 * This is an overly basic implementation.  It needs to be replaced.
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <avr/pgmspace.h>
#include "lib/data-types.h"
#include "lib/usb/usage-page/keyboard--short-names.h"
#include "lib/key-functions.h"

#include "../matrix.h"
#include "../matrix--private.h"
#include "../layout.h"


// aliases
// #define f_press &kbfun_press
// #define f_relea &kbfun_release
// #define f_l_set &kbfun_layer_set
// #define f_l_inc &kbfun_layer_inc
// #define f_l_dec &kbfun_layer_dec
// #define f_2kcap &kbfun_2_keys_capslock_press_release
kbfun_funptr_t PROGMEM _kb_layout_functions[6] = {
	&kbfun_press,
	&kbfun_release,
	&kbfun_layer_set,
	&kbfun_layer_inc,
	&kbfun_layer_dec,
	&kbfun_2_keys_capslock_press_release
};
#define f_press 0
#define f_relea 1
#define f_l_set 2
#define f_l_inc 3
#define f_l_dec 4
#define f_2kcap 5


uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// ----------------------------------------------------------------------------
	LAYER(  // layer 0: default
// unused
0,
// left hand
_grave,    _1,      _2,      _3,      _4,      _5,  _equal,
_bracketL, _Q,      _W,      _E,      _R,      _T,  _esc,
_tab,      _A,      _S,      _D,      _F,      _G,
_shiftL,   _Z,      _X,      _C,      _V,      _B,   1,
_guiL,     _arrowL, _arrowU, _arrowD, _arrowR,
                                                 _bs,
                                                 _del,     _ctrlL,
                                              _end, _home, _altL,
// right hand
         _backslash, _6, _7,      _8,      _9,      _0,         _dash,
         _bracketL,  _Y, _U,      _I,      _O,      _P,         _bracketR,
                     _H, _J,      _K,      _L,      _semicolon, _quote,
          1,         _N, _M,      _comma,  _period, _slash,     _shiftR,
                         _arrowL, _arrowD, _arrowU, _arrowR,    _guiR,
            _space,
_ctrlR,     _enter,
_altR,  _pageU, _pageD ),
// ----------------------------------------------------------------------------
	LAYER(  // layer 1: function and symbol keys
// unused
0,
// left hand
0, _F1,        _F2,        _F3,       _F4,       _F5,       _F11,
0, _braceL_kp, _braceR_kp, _bracketL, _bracketR,  0,        _esc,
0, _semicolon, _slash,     _dash,      0,        _colon_kp,
0,  0,          0,          0,         0,         0,         0,
0, _arrowL,    _arrowU,    _arrowD,   _arrowR,
                                                       _bs,
                                                       _del,     _ctrlL,
                                                    _end, _home, _altL,
// right hand
         _F12, _F6,       _F7,     _F8,        _F9,        _F10,          0,
          0,    0,        _dash,   _lt_kp,     _gt_kp,     _currencyUnit, 0,
               _backslash, 0,      _parenL_kp, _parenR_kp, _equal,        0,
          0,   _mul_kp,    0,       0,          0,          0,            0,
                          _arrowL, _arrowD,    _arrowU,    _arrowR,       0,
            _space,
_ctrlR,     _enter,
_altR,  _pageU, _pageD )
// ----------------------------------------------------------------------------
};


uint8_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// ----------------------------------------------------------------------------
	LAYER(  // layer 0: default
// unused
   0,
// left hand
f_press,f_press,f_press,f_press,f_press,f_press,f_press,
f_press,f_press,f_press,f_press,f_press,f_press,f_press,
f_press,f_press,f_press,f_press,f_press,f_press,
f_2kcap,f_press,f_press,f_press,f_press,f_press,f_l_inc,
f_press,f_press,f_press,f_press,f_press,
                                           f_press,
                                           f_press,  f_press,
                                       f_press,f_press,f_press,
// right hand
       f_press,f_press,f_press,f_press,f_press,f_press,f_press,
       f_press,f_press,f_press,f_press,f_press,f_press,f_press,
               f_press,f_press,f_press,f_press,f_press,f_press,
       f_l_inc,f_press,f_press,f_press,f_press,f_press,f_2kcap,
                       f_press,f_press,f_press,f_press,f_press,
          f_press,
f_press,  f_press,
f_press,f_press,f_press ),
// ----------------------------------------------------------------------------
	LAYER(  // layer 1: function and symbol keys
// unused
   0,
// left hand
f_press,f_press,f_press,f_press,f_press,f_press,f_press,
f_press,f_press,f_press,f_press,f_press,f_press,f_press,
f_press,f_press,f_press,f_press,f_press,f_press,
f_press,f_press,f_press,f_press,f_press,f_press,      0,
f_press,f_press,f_press,f_press,f_press,
                                           f_press,
                                           f_press,  f_press,
                                       f_press,f_press,f_press,
// right hand
       f_press,f_press,f_press,f_press,f_press,f_press,f_press,
       f_press,f_press,f_press,f_press,f_press,f_press,f_press,
               f_press,f_press,f_press,f_press,f_press,f_press,
             0,f_press,f_press,f_press,f_press,f_press,f_press,
                       f_press,f_press,f_press,f_press,f_press,
          f_press,
f_press,  f_press,
f_press,f_press,f_press )
// ----------------------------------------------------------------------------
};


uint8_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// ----------------------------------------------------------------------------
	LAYER(  // layer 0: default
// unused
   0,
// left hand
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
f_2kcap,f_relea,f_relea,f_relea,f_relea,f_relea,f_l_dec,
f_relea,f_relea,f_relea,f_relea,f_relea,
                                           f_relea,
                                           f_relea,  f_relea,
                                       f_relea,f_relea,f_relea,
// right hand
       f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
       f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
               f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
       f_l_dec,f_relea,f_relea,f_relea,f_relea,f_relea,f_2kcap,
                       f_relea,f_relea,f_relea,f_relea,f_relea,
          f_relea,
f_relea,  f_relea,
f_relea,f_relea,f_relea ),
// ----------------------------------------------------------------------------
	LAYER(  // layer 1: function and symbol keys
// unused
   0,
// left hand
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,      0,
f_relea,f_relea,f_relea,f_relea,f_relea,
                                           f_relea,
                                           f_relea,  f_relea,
                                       f_relea,f_relea,f_relea,
// right hand
       f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
       f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
               f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
             0,f_relea,f_relea,f_relea,f_relea,f_relea,f_relea,
                       f_relea,f_relea,f_relea,f_relea,f_relea,
          f_relea,
f_relea,  f_relea,
f_relea,f_relea,f_relea )
// ----------------------------------------------------------------------------
};

