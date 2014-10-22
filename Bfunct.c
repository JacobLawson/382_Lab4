#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)


void main() {

	unsigned char	x, y, xvect, yvect;
	int i;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	xvect=1;	yvect=1;
	drawBlock(y,x);

	while(1) {

		if(xvect==1){
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
		for (i=300; i>=0; i--  ){
			movedelay();
		}


				clearDisplay();
				drawBlock(y,x);
	}
}
