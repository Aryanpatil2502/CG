
//C3(B)

// BEGINNING OF CODE
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void bresenhamCircle(int xcord, int ycord, int rad) {
// function to draw circle using Bresenhamn algorithm
	int dec, x, y;
	dec = 3-2*rad; // dec is decision parameter
	x = 0;
	y = rad;

	while (y >= x) {
		putpixel(xcord+x, ycord+y, 15); // bottom right
		putpixel(xcord+y, ycord+x, 15); // right side
		putpixel(xcord+y, ycord-x, 15); // right up
		putpixel(xcord+x, ycord-y, 15); // top
		putpixel(xcord-x, ycord-y, 15); // left top
		putpixel(xcord-y, ycord-x, 15); // left side
		putpixel(xcord-y, ycord+x, 15); // left bottom
		putpixel(xcord-x, ycord+y, 15); // bottom
		x++;
		// note: 15 is the colour, instead you can also put WHITE, RED, GREEN, etc.
	
		// decision paramter
		if (dec > 0) {
			
			dec = dec+4*(x-y)+10;
            y--;
		}
		else {
			dec = dec+4*x+6;
		}
		// delay(10); // optional delay to watch the circle being made
	}
}

void ddaLine(float x1, float y1, float x2, float y2) {
// DDA line drawing algorithm
	float dx, dy, steps, x, y, xinc, yinc;

	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if (dx>dy) {
		steps = dx;
	}
	else {
		steps = dy;
	}

	x = x1;
	y = y1;
	putpixel(round(x), round(y), 15);

	xinc = (x2-x1)/steps;
	yinc = (y2-y1)/steps;
	
	for (int i=0; i<steps; i++) {
		x = x + xinc;
		y = y + yinc;
		putpixel(round(x), round(y), 15);
	}
}

int main() {
	float x1, y1, x2, y2; // variables to store coordinates of rectangle
	float X, Y; // variables to store coordinates of rhombus
	int x, y, r; // variables to store coordinates of circle

	cout<<endl<<"Enter coordinates:";
	cout<<endl<<"Enter value for X1:\t";
	cin>>x1;
	cout<<endl<<"Enter value for Y1:\t";
	cin>>y1;
	cout<<endl<<"Enter value for X2:\t";
	cin>>x2;
	cout<<endl<<"Enter value for Y2:\t";
	cin>>y2;

	// initializing graphics window
		int gd=DETECT, gm;
		initgraph(&gd, &gm, NULL);

	// making rectangle
		ddaLine(x1, y1, x1, y2); // left line
		ddaLine(x1, y2, x2, y2); // bottom line
		ddaLine(x2, y2, x2, y1); // right line
		ddaLine(x2, y1, x1, y1); // top line

	// making rhombus
		X=(x2+x1)/2;
		Y=(y2+y1)/2;

		ddaLine(X, y1, x2, Y); // top to right edge
		ddaLine(x2, Y, X, y2); // right to bottom edge
		ddaLine(X, y2, x1, Y); // bottom to left edge
		ddaLine(x1, Y, X, y1); // left to top edge

	// making circle inside rhombus
	/*
	NEVER REALLY FIGURED OUT HOW TO MAKE THIS ONE. IF YOU KNOW, PLEASE CONTRIBUTE.
	*/
		x = (x1+x2)/2;
		y = (y1+y2)/2;
		r = sqrt(pow((x2 - x1) / 4, 2) + pow((y2 - y1) / 4, 2));
		bresenhamCircle(x,y,r);

	delay(50000);
	closegraph();
	return 0;
}
// END OF CODE
//TEST CASE TO TEST - 
//Enter coordinates:
//Enter value for X1: 50
//Enter value for Y1: 50
//Enter value for X2: 200
//Enter value for Y2: 200

