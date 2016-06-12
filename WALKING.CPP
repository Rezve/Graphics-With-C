#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void man(int posX,int posY ) {
   //head
   ellipse(posX,posY, 0,360, 40,30);
   //body
   line(posX,posY+30,posX, posY+80);
   //hand
   line(posX-20,posY+45,posX+20,posY+45);

   //leg
   line(posX,posY+80,posX-40,posY+150);
   line(posX,posY+80,posX+40, posY+150);

   //feet
   //line(posX-40, posY+150, posX-30,posY+150);
}


void man2(int posX,int posY ) {
   //head
   ellipse(posX,posY, 0,360, 40,30);
   //body
   line(posX,posY+30,posX, posY+80);
   //hand
   line(posX-20,posY+45,posX+20,posY+45);

   //leg
   line(posX,posY+80,posX-20,posY+150);
   line(posX,posY+80,posX+20, posY+150);
}


void man3(int posX,int posY ) {
   //head
   ellipse(posX,posY, 0,360, 40,30);
   //body
   line(posX,posY+30,posX, posY+80);
   //hand
   line(posX-20,posY+45,posX+20,posY+45);

   //leg
   line(posX,posY+80,posX-10,posY+150);
   line(posX,posY+80,posX+10, posY+150);
}

void man4(int posX,int posY ) {
   //head
   ellipse(posX,posY, 0,360, 40,30);
   //body
   line(posX,posY+30,posX, posY+80);
   //hand
   line(posX-20,posY+45,posX+20,posY+45);

   //leg
   line(posX,posY+80,posX,posY+150);
   line(posX,posY+80,posX, posY+150);
}


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* initialize graphics, local variables*/
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   int posX = 100;
   int posY = 200;

   for(i=0;i<20;i++) {
       if(kbhit())
	   exit(1);

       posX += 5;
       man(posX, posY);
       delay(200);
       clearviewport();

       posX += 5;
       man2(posX, posY);
       delay(200);
       cleardevice();

       posX += 5;
       man3(posX, posY);
       delay(200);
       cleardevice();

       posX += 5;
       man4(posX,posY);
       delay(200);
       cleardevice();
   }

   //ellipse(300,200,0,360,40,30);
   //body
   //line(300,230,300,280);
   //hand
   //line(280,245,320,245);

   //leg
   //line(300,280,260,350);
   //line(300,280,340,350);

   /* clean up */
   getch();
   closegraph();
   return 0;
}

