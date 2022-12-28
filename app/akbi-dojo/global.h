#ifndef GLOBAL_H
#define GLOBAL_H

#include "akbi.h"
#include "clingo/container/pile.h"

/*******************************************************************************

*******************************************************************************/

typedef void aPlan;

typedef void ( *a_lesson )( aPlan* p );

struct aLesson
{
   char const* desc;
   aPlan* plan;
   a_lesson exec;
};
typedef struct aLesson aLesson;

STATIC_VAL_PILE_IMPL_C_(
   __attribute__((unused)),   // Attr
   aLesson,                   // Type
   aLessonPile,               // PileType
   lesson_a                   // FuncSuffix
)

/*******************************************************************************

*******************************************************************************/

Vector2 LessonOrigin = { 0, 50 };
Vector2 LessonDim = { 800, 400 };

/*******************************************************************************

*******************************************************************************/

static Color background_color( void )
{
   return in_akbi_mode() ? RAYWHITE : BLACK;
}

static Color text_color( void )
{
   return in_akbi_mode() ? BLACK : RAYWHITE;
}

static void draw_background( Color color )
{
   DrawRectangleV( LessonOrigin, LessonDim, color );
}

static void draw_text( char const* text, int x, int y, int fontSize, Color color )
{
   DrawText( text, LessonOrigin.x+x, LessonOrigin.y+y, fontSize, color );
}

static void draw_xcenter_text( char const* text, int y, int fontSize, Color color )
{
   int textDim = MeasureText( text, fontSize);
   int delta = ( LessonDim.x - textDim ) / 2;
   DrawText( text, LessonOrigin.x+delta, LessonOrigin.y+y, fontSize, color );
}

static void draw_center_text( char const* text, int fontSize, Color color )
{
   Vector2 textDim = { MeasureText( text, fontSize), fontSize };
   Vector2 delta = { .x = ( LessonDim.x - textDim.x ) / 2, .y = ( LessonDim.y - textDim.y ) / 2 };
   DrawText( text, LessonOrigin.x+delta.x, LessonOrigin.y+delta.y, fontSize, color );
}

#endif