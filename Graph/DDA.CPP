#ifndef DDA_H
#define DDA_H

#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void lineDDA(int xa,int ya,int xb,int yb){
	int dx = xb-xa,dy = yb-ya,steps,k;
	float xIncrement, yIncrement, x = xa, y = ya;

	
	abs(10);
	
	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}else{
		steps = abs(dy);
	}

	xIncrement = dx / (float) steps;
	yIncrement = dy / (float) steps;

	//WARNA

	putpixel((int)(x+0.5),(int)(y+0.5),WHITE);

	for(k = 0;k<steps;k++){
		x += xIncrement;
		y += yIncrement;
		putpixel((int)(x+0.5),int(y+0.5),WHITE);
	}
}
#endif