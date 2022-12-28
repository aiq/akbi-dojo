#ifndef LESSONS_ACTIVATE_AKBI_H
#define LESSONS_ACTIVATE_AKBI_H

#include "../global.h"

static void activateAkbiLessonExec( aPlan* p )
{
   if ( not in_akbi_mode() )
   {
      draw_background( RAYWHITE );
      draw_center_text( "activate akbi mode with pressing the CAPSLOCK key", 20, BLUE );
   }
   else
   {
      draw_background( BLACK );
      draw_xcenter_text( "Congratulations !", 20, 20, RED );

      draw_center_text( "press PREV[q] or NEXT[e] to switch between the lessons", 20, RAYWHITE );
   }
}

static aLesson activateAkbiLesson( void )
{
   return (aLesson){
      .desc = "acivate akbi",
      .plan = NULL,
      .exec = &activateAkbiLessonExec
   };
}

#endif