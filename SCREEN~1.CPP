
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<DOS.h>

void draw_laddu(int _posX,int _posY) {
    int posX = _posX;
    int posY = _posY;
    int radius = 10;
    int count;
    int color = 0;
    int direction = rand()%9;


    for(count = 0;count <50;count++) {
	setcolor(color);
	circle(posX,posY,radius);

	radius +=2;

	switch(direction) {
	    case 0:
		//left
		posX--;
	    break;
	    case 1:
		//right
		posX++;
	    break;
	    case 2:
		//down
		posY++;
	    break;
	    case 3:
		//up
		posY--;
	    break;
	    case 4:
		//down-right
		posX++;
		posY++;
	    break;
	    case 5:
		//down-left
		posX--;
		posY++;
	    break;
	    case 6:
		//up-right
		posX++;
		posY--;
	    break;
	    case 7:
		//up-left
		posX--;
		posY--;
	    break;
	    case 8:
		//no change of position
	    break;
	}

	color++;
	if(color>15)
	    color = 0;

	delay(50);
    }

    posX = _posX;
    posY = _posY;
    radius = 10;

    for(count = count;count >0; count--) {
	setcolor(0);
	circle(posX,posY,radius);

	switch(direction) {
	    case 0:
		//left
		posX--;
	    break;
	    case 1:
		//right
		posX++;
	    break;
	    case 2:
		//down
		posY++;
	    break;
	    case 3:
		//up
		posY--;
	    break;
	    case 4:
		//down-right
		posX++;
		posY++;
	    break;
	    case 5:
		//down-left
		posX--;
		posY++;
	    break;
	    case 6:
		//up-right
		posX++;
		posY--;
	    break;
	    case 7:
		//up-left
		posX--;
		posY--;
	    break;
	    case 8:
		//no change
	    break;
	}

	radius +=2;

	delay(20);
    }


}


int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
  // char msg[80];

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   setcolor(12);

   char msg[20];

   for(;;) {
      if(kbhit())
	exit(1);
      draw_laddu(rand()%500 ,rand()%400 );
   }

}
