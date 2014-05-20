#ifndef _LINGBRES
#define _LINGBRES
#include <graphics.h>

void circlePlotPoints(int xCenter, int yCenter,int x, int y){
	putpixel(xCenter + x, yCenter + y, WHITE);
	putpixel(xCenter - x, yCenter + y, WHITE);
	putpixel(xCenter + x, yCenter - y, WHITE);
	putpixel(xCenter - x, yCenter - y, WHITE);
	putpixel(xCenter + y, yCenter + x, WHITE);
	putpixel(xCenter - y, yCenter + x, WHITE);
	putpixel(xCenter + y, yCenter - x, WHITE);
	putpixel(xCenter - y, yCenter - x, WHITE);
}

void circleMidPoint(int xCenter,int yCenter,int radius){
	int x = 0;
	int y = radius;
	int p = 1 - radius;
	circlePlotPoints(xCenter,yCenter,x,y);

	while(x < y){
		x++;
		if(p < 0){
			p += 2 * x + 1;
		}else{
			y--;
			p += 2 * (x - y) + 1;
		}
		circlePlotPoints(xCenter,yCenter, x, y);
	}

}

#endif