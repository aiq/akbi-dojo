#include "akbi.h"
#include "clingo/io/cRecorder.h"
#include "clingo/io/print.h"
#include "clingo/io/write_type.h"
#include "lessons/activate-akbi.h"
#include "lessons/use-navigation-keys.h"

int main( void )
{
   aLessonPile allLessons;
   alloc_pile_of_lesson_a( &allLessons, 128 );
   put_lesson_a( &allLessons, activateAkbiLesson() );
   put_lesson_a( &allLessons, useNavigationKeys() );

   const int screenWidth = 800;
   const int screenHeight = 450;

   InitWindow( screenWidth, screenHeight, "AKBI-DOJO" );

   Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

   aLesson* lesson = begin_c_( allLessons );
   cRecorder* rec = &recorder_c_( 8 );

   SetTargetFPS( 60 );
   SetExitKey( KEY_NULL );
   while ( !WindowShouldClose() )
   {
      ClearBackground( RAYWHITE );
      if ( IsKeyPressed( a_NextKey ) )
      {
         if ( lesson != rbegin_c_( allLessons ) )
         {
            ++lesson;
         }
      }
      else if ( IsKeyPressed( a_PrevKey ) )
      {
         if ( lesson != begin_c_( allLessons ) )
         {
            --lesson;
         }
      }
      BeginDrawing();
         lesson->exec( lesson->plan );

         DrawRectangle( 0, 0, 800, 50, BLACK );
         write_int64_c( rec, index_of_c_( allLessons, lesson )+1, "(2r0)" );
         DrawText( turn_into_cstr_c( rec ), 10, 15, 20, RED );
         DrawText( lesson->desc, 50, 15, 20, RAYWHITE );
         DrawLine( 0, 50, 800, 50, RAYWHITE );
      EndDrawing();
   }

   CloseWindow();
   return 0;
}