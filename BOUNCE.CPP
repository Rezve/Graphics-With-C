/*
	Bouncing ball
	
	KEY:
		w for jump
		e for exit

*/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<DOS.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }
   //Intro text
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(125,240,"Press any key to start.");
   getch();
   clearviewport();

  // bar(0,400,600,400);

   //bar3d(left, top, right, bottom, (right-left)/4, 1);
   setfillstyle(3,3);
   bar3d(20, 400, 500, 430, 30, 1);


   int i = 0;
   int posY = 10;
   int gravity = 1;
   int velocityY = 15;
   int bounce = -10;
   int jump = 2;

   setbkcolor(5);
   while(1) {
       int old_p = posY;

       if(kbhit() && jump > 0){
	   char key = getch();

	   if(key == 'w') {
	       bounce = -10;
	       velocityY = -15;
	       gravity = 1;
	       jump--;
	   }

	   if(key == 'e')
	       exit(1);
       }

       velocityY += gravity;
       posY += velocityY;

       if(posY < 330 ) {
	   //hide ball
	   setcolor(5);
	   setfillstyle(0, 5);
	   fillellipse(300 , old_p, 50, 50);

	   //new ball
	   setcolor(5);
	   setfillstyle(1, 4);
	   fillellipse(300 , posY , 50, 50);
       }

       if(posY >= 330 ){
	 velocityY = bounce;
	 posY = 330;
	 bounce += 3;

	 if(bounce > 0){
	    bounce = 0;
	    jump = 2;
	  }
       }

     delay(30);
     i++;

     //debug
      //printf("%d  ", velocityY);
   }

}
