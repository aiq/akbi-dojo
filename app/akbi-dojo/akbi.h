#ifndef AKBI_H
#define AKBI_H

#include "raylib.h"

/*******************************************************************************

*******************************************************************************/

enum a_Key {
   a_ShiftKey = KEY_LEFT_SHIFT,
   a_ControlKey = KEY_LEFT_CONTROL,
   a_AltKey = KEY_LEFT_ALT,

   a_UpKey = KEY_W,
   a_LeftKey = KEY_A,
   a_DownKey = KEY_S,
   a_RightKey = KEY_D,

   a_PrevKey = KEY_Q,
   a_NextKey = KEY_E
};
typedef enum a_Key a_Key;

/*******************************************************************************

*******************************************************************************/

static bool in_akbi_mode( void )
{
   return IsKeyDown( KEY_CAPS_LOCK );
}

#endif