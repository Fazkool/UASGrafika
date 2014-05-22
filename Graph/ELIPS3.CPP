#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

void elips(long int xcenter,long int ycenter,long int xradius,long int yradius)
{
	long int d1,d2;
	int i,gd = DETECT ,gm,x,y;
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
		putpixel(xcenter+x,ycenter+y,15);
		putpixel(xcenter-x,ycenter-y,15);
		putpixel(xcenter+x,ycenter-y,15);
		putpixel(xcenter-x,ycenter+y,15);
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
		putpixel(xcenter+x,ycenter+y,15);
		putpixel(xcenter-x,ycenter-y,15);
		putpixel(xcenter+x,ycenter-y,15);
		putpixel(xcenter-x,ycenter+y,15);
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

//void main()
//{
       //	elips(200,50,200,50);
//}