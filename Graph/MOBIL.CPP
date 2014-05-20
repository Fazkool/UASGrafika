#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>

#define ROUND(a) ((int)(a+0.5))

void lineDDA(int xa,int ya,int xb,int yb){
	int dx = xb-xa,dy = yb-ya,steps,k;
	float xIncrement, yIncrement, x = xa, y = ya;

	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}else{
		steps = abs(dy);
	}
	xIncrement = dx / (float) steps;
	yIncrement = dy / (float) steps;

	putpixel(ROUND(x),ROUND(y),WHITE);

	for(k = 0;k<steps;k++){
		x += xIncrement;
		y += yIncrement;
		putpixel(ROUND(x),ROUND(y),WHITE);
	}
}

void DrawKotak(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd){
	 //aturan :
	 // B C
	 // A D
	 lineDDA(xa,ya,xb,yb);
	 lineDDA(xa,ya,xd,yd);
	 lineDDA(xb,yb,xc,yc);
	 lineDDA(xc,yc,xd,yd);
}
void DrawMobil(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd){
		 //xa = 50 ya = 200
		 //xb = 50 yb = 150
		 //xc = 200 yc = 150
		 //xd = 200 yd = 200
	int jarak1 = (xd-xa)/15;
	int jarak2 = (ya-yc)*2/5;
	int jarak3 = (xd-xa)/5;
	int jarak4 = (ya-yb);
	int jarak5 = (xd-xa)/3*2;
	DrawKotak(xa+jarak1,ya-jarak4,xa+jarak3+jarak1,ya-jarak4*2,xd-jarak1-jarak3,yd-(jarak4*2),xd-jarak1,yd-jarak4);
	DrawKotak(xa,ya,xb,yb,xc,yc,xd,yd);

	DrawKotak(xa+jarak1,ya+jarak2,xa+jarak1,ya,xa+jarak1+jarak3,ya,xa+jarak1+jarak3,ya+jarak2);
	DrawKotak(xc-jarak1-jarak3,yd+jarak2,xc-jarak1-jarak3,yd,xc-jarak1,yd,xc-jarak1,yd+jarak2);

}

int main(){
	int grd;
	int grm;
	int gresult;

	detectgraph(&grd,&grm);
	initgraph(&grd,&grm,"C:\\TC\\BGI");

      //	lineDDA(50,50,123,75);
      //	lineDDA(50,50,73,125);
     //	DrawKotak(60,150,90,100,160,100,190,150);
      //	DrawKotak(50,200,50,150,200,150,200,200);
      //	DrawKotak(60,220,60,200,90,200,90,220);
      //	DrawKotak(160,220,160,200,190,200,190,220);
      int a,b,c,d;
      a=300;
      b=300;
      c= 250;
      d= 500 ;
	DrawMobil(a,b,a,c,d,c,d,b);

      //	DrawMobil(50,200,50,150,200,150,200,200);
	getch();
	return 0;
}