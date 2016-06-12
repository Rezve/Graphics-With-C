#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void blinkEye() {
     for(int i=20;i>0;i-=2) {

       setcolor(BLACK);
       setfillstyle(1,BLACK);
       fillellipse(360, 140,20, 20);

       setfillstyle(1,WHITE);
       fillellipse(360, 140,20, i);

       delay(40);
     }
     fillellipse(360, 140,20, 20);
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

    fillellipse(240, 140,20, 20);
    fillellipse(360, 140,20, 20);
    pieslice(300,200,180,360,100);

    outtextxy(260, 330, "Bikroy.Com");

    for(;;){
       if(kbhit()){
	  char key = getch();

	  if(key == 'e')
	     exit(1);
	  if(key == 'b')
	     blinkEye();

       }
    }
}

