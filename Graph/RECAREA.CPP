#ifndef _RECAREA
#define _RECAREA
#include <graphics.h>
#include <Graph/queue.cpp>
#include <dos.h>
void recboundaryFill4(int x,int y, int fill, int boundary){
	int current;

	current = getpixel(x,y);
	if((current!=boundary) && (current != fill)){
		setcolor(fill);
		putpixel(x,y,fill);
		recboundaryFill4(x+1,y,fill,boundary);//KANAN
		recboundaryFill4(x-1,y,fill,boundary);//KIRI
		recboundaryFill4(x,y+1,fill,boundary);//BAWAH
		recboundaryFill4(x,y-1,fill,boundary);//ATAS
	}
}


void boundaryFill4(int x,int y,int fill,int boundary){
	int current;

	MyQueue<int> Qx;
	MyQueue<int> Qy;
	Qx.push(x);
	Qy.push(y);
	while(Qx.size()!=0){
		int xNow = Qx.front();
		int yNow = Qy.front();
		Qx.pop();
		Qy.pop();
		
		current = getpixel(xNow,yNow);
		
		if((current!=boundary) && (current!=fill) && xNow >=0 && xNow < getmaxx() && yNow >=0 && yNow < getmaxy()){
			putpixel(xNow,yNow,fill);

			//TAMBAH KANAN
			Qx.push(xNow+1);
			Qy.push(yNow);

			//TAMBAH KIRI
			Qx.push(xNow-1);
			Qy.push(yNow);

			//TAMBAH BAWAH
			Qx.push(xNow);
			Qy.push(yNow+1);

			//TAMBAH ATAS
			Qx.push(xNow);
			Qy.push(yNow-1);
		}
	}
}


#endif