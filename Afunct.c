#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void movedelay();
extern void drawBlock(unsigned char row, unsigned char col);
extern void drawLine(unsigned char row2, unsigned char col2);


#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)



void main() {

	unsigned char	x, y, xvect, yvect,y2, button_press, x2;
	int i, j, k;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	y2=4;		x2=1;
	xvect=1;	yvect=1;
	drawBlock(y,x);
	drawLine(y2,x2);
	while(1) {

		if (x<=1 && (y <= y2 && y >= y2-1)){		//Checks to see if the ball hit the paddle
				xvect=1;
		}
		if (x==0){									//Checks to see if ball missed the paddle
			for(k = 0; k<12; k++) {
				for(j = 0; j<12; j++) {
					drawLine(j,k);					//This is the game over screen
					}
				 }
			while(button_press == FALSE) {
				if(AUX_BUTTON == 0)	{				//If you lose the game, this restarts it
					button_press = TRUE;
				}
			}
					xvect=1;
		}


		if(xvect==1){				//These are just boundary conditions to check if the ball hit the wall
			x++;
			if(x==12){
				xvect=0;
			}
		}
		if(xvect==0){
			x--;
			if(x==0){
				xvect=1;
			}
		}
		if(yvect==1){
			y++;
			if(y==8){
				yvect=0;
			}
		}
		if(yvect==0){
			y--;
			if(y==0){
				yvect=1;
			}
		}

// =================================================================
//					Movement for the Line
// =================================================================
		if (UP_BUTTON == 0)
		{
			while(UP_BUTTON == 0);
			if (y2>=1)
				y2-=1;
				button_press = TRUE;
		}
			else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y2<=6)
					y2+=1;
				button_press = TRUE;
			}
			if (button_press) {
				button_press = FALSE;
				clearDisplay();

				drawLine(y2,x2);
				drawLine(y2-1,x2);

				drawBlock(y,x);
			}
			clearDisplay();
			drawBlock(y,x);
			drawLine(y2,x2);
			drawLine(y2-1,x2);

//	=============================================================
// 					Time Delay with Drawing
//	=============================================================
			for(i = 0; i<350; i++)									// provides the time delay and lets us draw without
			{														// waiting for the clock
				if (UP_BUTTON == 0)
				{
					while(UP_BUTTON == 0);
					if (y2>=1)
						y2-=1;
					button_press = TRUE;
				}
				else if (DOWN_BUTTON == 0)
				{
					while(DOWN_BUTTON == 0);
					if (y2<=6)
						y2+=1;
					button_press = TRUE;
				}
				if (button_press)
				{
					button_press = FALSE;
					clearDisplay();

					drawLine(y2,x2);
					drawLine(y2-1,x2);

					drawBlock(y,x);
				}
				movedelay();
			}
		}
}
