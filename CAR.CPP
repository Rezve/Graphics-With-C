/*  

	moving car
	
	
 KEY:
	l for light
	d for move forward
	a for backword 
	e for exit

*/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void car(int posX, int posY, int light, int backLight) {
   //chakka
   setfillstyle(4,4);
   fillellipse(posX, posY, 20,20);
   fillellipse(posX+100, posY, 20,20);

   //boltu
   setfillstyle(1,0);
   fillellipse(posX,posY,5,5);
   fillellipse(posX+100, posY,5,5);

   //dhakna
   arc(posX, posY, 0, 180, 30);
   arc(posX+100, posY, 0,180, 30);

   //bottom line
   line(posX+30, posY, posX+70, posY); //mid connector
   line(posX-30, posY, posX-70,posY); //left connector
   line(posX+130, posY, posX+200, posY); //right connector

   //mid line
   line(posX-70,posY, posX-70, posY-30); //back
   line(posX+200, posY, posX+200, posY-30); //front

   if(backLight > 0) {
	//back light
	setfillstyle(1,RED);
	bar(posX-78, posY-30, posX-71, posY-10);
	line(posX-85,posY-20, posX-100, posY-20); //mid
	line(posX-85, posY-25, posX-100, posY-30); //top
	line(posX-85, posY-15, posX-100, posY-10);
   }else{
	rectangle(posX-78, posY-30, posX-71, posY-10);
   }

   if(light>0) {
       //light
       setfillstyle(1,4);
       pieslice(posX+210, posY-18, 90, 270, 10);    //head light
       line(posX+215, posY-17, posX+228, posY-17);  //mid light
       line(posX+215, posY-13, posX+228, posY-7);   //bottom light
       line(posX+215, posY-22, posX+228, posY-27);  //top light
   }else{
       //light
       setfillstyle(0,1);
       pieslice(posX+210, posY-18, 90, 270, 10);    //head light
   }
   //glash
   arc(posX-20,posY-30, 120, 180, 50); //back
   line(posX+200, posY-30, posX+100, posY-80); //front

   //top body
   line(posX-45, posY-73, posX+100, posY-80);

}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

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

   int posX = 200;
   int posY = 300;
   int speed = 0;
   int light = 0;
   int backLight = 0;

   for(;;) {
       if(kbhit()){
	   char key = getch();

	   if(key == 'e')
	       exit(1);

	   if(key == 'd'){
	       speed = 1;
	       backLight = 0;
	   }

	   if(key == 'b'){
	       speed = 0;
	       backLight = 0;
	   }

	   if(key == 'a'){
	       speed = -1;
	       backLight = 1;
	   }
	   if(key == 'l'){
	       if(light == 1)
		   light = 0;
	       else
		   light = 1;
	   }
       }

       posX += speed;

       car(posX, posY, light, backLight);
       delay(10);
       cleardevice();
   }
}

