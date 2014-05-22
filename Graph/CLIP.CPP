#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int rx1, ry1, rx2, ry2;
int i,j=0,n;
float x1[8],y1[8];

void clip(float e,float f,float m,int xAwal, int yAwal, int xAkhir, int yAkhir)
{
	rx1 = xAwal;
	ry1 = yAwal;
	rx2 = xAkhir;
	ry2 = yAkhir;

	while(e<rx1 || e>rx2 || f<ry1 || f>ry2)
	{
		if(e<rx1)
		{
			f+=m*(rx1-e);
			e=rx1;
		}
		else if(e>rx2)
		{
			f+=m*(rx2-e);
			e=rx2;
		}
		if(f<ry1)
		{
			e+=(ry1-f)/m;
			f=ry1;
		}
		else if(f>ry2)
		{
			e+=(ry2-f)/m;
			f=ry2;
		}
	}
	x1[j]=e;
	y1[j]=f;
	j++;
}

void draw_rectangle(int xAwal, int yAwal, int xAkhir, int yAkhir)
{
	int gd=DETECT,gm;
	int i,n;
	float x[8],y[8],m;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	
	rx1 = xAwal;
	ry1 = yAwal;
	rx2 = xAkhir;
	ry2 = yAkhir;
	
	// printf("Insert Coordinates for Rectangle : \n");
	// printf("Enter X(min) & Y(min) = ");
    // scanf("%d%d",&rx1,&ry1);
	// printf("Enter X(max) & Y(max) = ");
    // scanf("%d%d",&rx2,&ry2);
	
	printf("Insert number of sides for polygon (2 for line, n for n-gon) : ");
	scanf("%d",&n);
	
	printf("Insert the Coordinates : \n");
	for(i=0;i<n;i++)
	{
	    printf("Vertex X[%d] Y[%d] = ",i+1,i+1);
	    scanf("%f%f",&x[i],&y[i]);
	}
	
	cleardevice();
	
	outtextxy(10,10,"Before clipping");
	outtextxy(10,470,"Press any key....");
	//rectangle(rx1,ry1,rx2,ry2);
	
	for(i=0;i<n-1;i++)
	line(x[i],y[i],x[i+1],y[i+1]);
	line(x[i],y[i],x[0],y[0]);
	getch();
	cleardevice();
	
	for(i=0;i<n-1;i++)
	{
		m=(y[i+1]-y[i])/(x[i+1]-x[i]);
		clip(x[i],y[i],m,100,100,300,300);
		clip(x[i+1],y[i+1],m,100,100,300,300);
	}
	m=(y[i]-y[0])/(x[i]-x[0]);
	clip(x[i],y[i],m,100,100,300,300);
	clip(x[0],y[0],m,100,100,300,300);
	
	outtextxy(10,10,"After clipping");
	outtextxy(10,470,"Press any key....");
	rectangle(rx1,ry1,rx2,ry2);
	
	for(i=0;i<j-1;i++)
	line(x1[i],y1[i],x1[i+1],y1[i+1]);
	getch();
}

void main()
{
	draw_rectangle(100,100,300,300);
}