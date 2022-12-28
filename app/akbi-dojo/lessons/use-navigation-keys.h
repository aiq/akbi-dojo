#ifndef LESSONS_USE_NAVIGATION_KEYS_H
#define LESSONS_USE_NAVIGATION_KEYS_H

#include "../global.h"

typedef struct
{
   Vector2 ballPos;
} useNavigationKeysPlan;


static void useNavigationKeysExec( aPlan* p )
{
   if ( not in_akbi_mode() )
   {
      draw_background( RAYWHITE );
      draw_center_text( "switch to akbi mode [CAPSLOCK]", 20, BLUE );
      return;
   }

   draw_background( BLACK );

   draw_text( "use this keys", 20, 40, 20, RAYWHITE );
   draw_text( "w a s d", 20, 70, 20, RED );

   draw_text( "modify with", 20, 140, 20, RAYWHITE );
   draw_text( "SHIFT", 20, 170, 20, RED );

   draw_text( "like", 20, 240, 20, RAYWHITE );
   draw_text( "s", 20, 270, 20, RED );
   draw_text( "SHIFT + d", 20, 300, 20, RED );
   draw_text( "SHIFT + w", 20, 330, 20, RED );

   Rectangle box = { LessonDim.x-590, LessonOrigin.y+10, 580, 380 };
   Rectangle innerBox = { box.x + 21, box.y + 21, box.width - 42, box.height - 42 };
   DrawRectangleLinesEx( box, 1.0, RAYWHITE );
   useNavigationKeysPlan* plan = p;
   {
      Vector2 ball = plan->ballPos;
      if ( IsKeyDown( a_ShiftKey ) and IsKeyDown( a_RightKey ) )
         ball.x = innerBox.x + innerBox.width;
      else if ( IsKeyDown( a_RightKey ) )
         ball.x += 2.0f;
      else if ( IsKeyDown( a_ShiftKey ) and IsKeyDown( a_LeftKey ) )
         ball.x = innerBox.x;
      else if ( IsKeyDown( a_LeftKey ) )
         ball.x -= 2.0f;
      else if ( IsKeyDown( a_ShiftKey ) and IsKeyDown( a_UpKey ) )
         ball.y = innerBox.y;
      else if ( IsKeyDown( a_UpKey ) )
         ball.y -= 2.0f;
      else if ( IsKeyDown( a_ShiftKey ) and IsKeyDown( a_DownKey ) )
         ball.y = innerBox.y + innerBox.height;
      else if ( IsKeyDown( a_DownKey ) )
         ball.y += 2.0f;

      if ( CheckCollisionPointRec( ball, innerBox ) ) plan->ballPos = ball;
   }
   
   DrawCircleV( plan->ballPos, 20, MAROON );
}

static aLesson useNavigationKeys( void )
{
   static useNavigationKeysPlan plan = {
      .ballPos = { 400, 250 }
   };

   return (aLesson){
      .desc = "use navigation keys",
      .plan = &plan,
      .exec = &useNavigationKeysExec
   };
}

#endif