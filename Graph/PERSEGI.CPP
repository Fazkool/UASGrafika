#ifndef _PERSEGI
#define _PERSEGI
#include <graphics.h>
#include <Graph/DDA.CPP>

void DrawKotak(int xa,int ya,int xb,int yb){
	 //aturan :
	 // B C
	 // A D
	 lineDDA(xa,ya,xb,ya);
	 lineDDA(xa,ya,xa,yb);
	 lineDDA(xb,yb,xa,yb);
	 lineDDA(xb,yb,xb,ya);
}
	void DrawKotak1(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd){
	 //aturan :
	 // B C
	 // A D
	 lineDDA(xa,ya,xb,yb);
	 lineDDA(xa,ya,xd,yd);
	 lineDDA(xb,yb,xc,yc);
	 lineDDA(xc,yc,xd,yd);
}
#endif