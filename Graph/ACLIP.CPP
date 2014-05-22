#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>


void elips2(long int xcenter,long int ycenter,long int xradius,long int yradius)
{
	long int d1,d2;
	int i,x,y;
	long int rxsq,rysq,tworxsq,tworysq,dx,dy;
	
	// printf("Enter the x Radius of the ellipse : ");
	// scanf("%ld",&rx);

	// printf("Enter the y Radius of the ellipse : ");
	// scanf("%ld",&ry);

	// printf("Enter the x Center of the ellipse : ");
	// scanf("%ld",&xcenter);

	// printf("Enter the y Center of the ellipse : ");
	// scanf("%ld",&ycenter);

	//initgraph(&gd,&gm,"C:\\TC\\BGI");

	rxsq = xradius * xradius;
	rysq = yradius * yradius;
	tworxsq = 2 * rxsq;
	tworysq = 2 * rysq;
	x = 0;
	y = yradius;
	d1 = rysq - (rxsq * yradius) + (0.25 * rxsq);
	dx = tworysq * x;
	dy = tworxsq * y;

	do
	{
		putpixel(xcenter+x,ycenter+y,17);
		putpixel(xcenter-x,ycenter-y,17);
		putpixel(xcenter+x,ycenter-y,17);
		putpixel(xcenter-x,ycenter+y,17);
		//outtextxy(60, 60, "ELLIPSE");

		if (d1 < 0)
		{
			x = x + 1;
			y = y;
			dx = dx + tworysq;
			d1 = d1 + dx + rysq;
		}

		else
		{
			x = x + 1;
			y = y - 1;
			dx = dx + tworysq;
			dy = dy - tworxsq;
			d1 = d1 + dx - dy + rysq;
		}

		//delay(50);

	}while (dx < dy);

	d2 = rysq * ( x + 0.5) * ( x + 0.5 ) + rxsq * (y - 1) * (y-1) - rxsq * rysq;

	do
	{
		putpixel(xcenter+x,ycenter+y,17);
		putpixel(xcenter-x,ycenter-y,17);
		putpixel(xcenter+x,ycenter-y,17);
		putpixel(xcenter-x,ycenter+y,17);
		//outtextxy(60, 60, "ELLIPSE");

		if (d2 > 0)
		{
			x = x;
			y = y - 1;
			dy = dy - tworxsq;
			d2 = d2 - dy + rxsq;
		}

		else
		{
			x = x + 1;
			y = y - 1;
			dy = dy - tworxsq;
			dx = dx + tworysq;
			d2 = d2 + dx -dy + rxsq;
		}

		//delay(50);

	} while (y > 0);

	//getch();
	//closegraph();
}

void lineDDA2(int xa,int ya,int xb,int yb)
{
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

	putpixel((int)(x+0.5),(int)(y+0.5),17);

	for(k = 0;k<steps;k++){
		x += xIncrement;
		y += yIncrement;
		putpixel((int)(x+0.5),int(y+0.5),17);
	}
}

void aClipKotak(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd)
{
	lineDDA2(xa,ya,xb,yb);
	lineDDA2(xa,ya,xd,yd);
	lineDDA2(xb,yb,xc,yc);
	lineDDA2(xc,yc,xd,yd);

	boundaryFill4(((xa+xc)/2),((ya+yc)/2), 1, 17);
	boundaryFill4(((xa+xc)/2),((ya+yc)/2), 0, WHITE);

	lineDDA(xa,ya,xb,yb);
	lineDDA(xa,ya,xd,yd);
	lineDDA(xb,yb,xc,yc);
	lineDDA(xc,yc,xd,yd);
}

void aClipElips(long int xcenter,long int ycenter,long int stangle,long int endangle, long int xradius,long int yradius)
{
	setcolor(17);
	ellipse(xcenter,ycenter, 0, 360, xradius, yradius);
	
	boundaryFill4(xcenter, ycenter, 1, 17);
	boundaryFill4(xcenter, ycenter, 0, WHITE);

	setcolor(15);

	ellipse(xcenter,ycenter,0 , 360, xradius, yradius);
}

/*void main()
{
	//draw_rectangle(100,100,300,300);

	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	rectangle(100,100,200,200);
	//aClipKotak(150,250,150,150,250,150,250,250);
	aClipElips(200,200,0,360,50,50);

	//ellipse(100,100,0,360,50,50);
	//aClipElips(150,150,0,360,50,50);
	//aClipKotak(100,200,100,100,200,100,200,200);

	getch();
}*/
