

#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<Graph/PDATA.CPP>
#include<Graph/RECAREA.CPP>
#include<Graph/PERSEGI.CPP>
#include<Graph/ELIPS3.CPP>
#include<Graph/DDA.CPP>
#include<Graph/CLIP.CPP>
#include<Graph/ACLIP.CPP>

union REGS i, o;
int leftcolor[15];
    int cek=0;
int color=0;
int frame_length=1000;
int arryX[500];
int arryY[500];
int arry_nX[500];
int arry_nY[500];
int arrx_nX[500];
int arrx_nY[500];
int arrxX[500];
int arrxY[500];

int COUNTERY;
int COUNTERX;

int pivot_x,pivot_y;

int STORE_YLINE_X[200];
int STORE_YLINE_Y[200];
int STORE_XLINE_X[200];
int STORE_XLINE_Y[200];
float P[1][3],P1[1][3];
int get_key()
{
   union REGS i,o;
 
   i.h.ah = 0;
   int86(22,&i,&o);
 
   return ( o.h.ah );
}
 
void draw_color_panel()
{
   int left, top, c, color;
 
   left = 100;
   top = 436;
 
   color = getcolor();
   setcolor(GREEN);
   DrawKotak(4,431,635,457);
   setcolor(RED);
   settextstyle(TRIPLEX_FONT,0,2);
   outtextxy(10,431,"FILL : ");
 
   for( c = 1 ; c <= 15 ; c++ )
   {
      setfillstyle(SOLID_FILL, c);
      bar(left, top, left+16, top+16);
      leftcolor[c-1] = left;
      left += 26;
   }
 
   setcolor(color);
}
 
void draw_shape_panel()
{
    int left, top, c, color;

   left = 529;
   top = 45;

   color = getcolor();
   setcolor(GREEN);
   DrawKotak(525,40,633,255);

   for( c = 1 ; c <= 3 ; c++ )
   {
      DrawKotak(left, top, left+49, top+25);
	  DrawKotak(left+51, top, left+100, top+25);
      top += 30;
   }
   DrawKotak(left, top, left+100, top+25);
   top += 30;
   DrawKotak(left, top, left+100, top+25);
   top += 30;
   DrawKotak(left, top, left+100, top+25);
   top += 30;
   boundaryFill4(550,50, RED, WHITE);
   DrawKotak(550, 83, 558, 91);
   lineDDA(585, 50, 625, 65);
   boundaryFill4(555,87, WHITE, WHITE);
   elips(605, 87, 10, 10);
   DrawKotak(584, 109, 625, 126);
   outtextxy(550,135,"CLEAR");
   setcolor(RED);
  /* outtextxy(530,45,"tes");
   outtextxy(530,75,"Line");
   outtextxy(530,105,"Pixel");
   outtextxy(530,135,"Ellipse");
   outtextxy(530,165,"Freehand");
   outtextxy(530,195,"DrawKotak");
   outtextxy(530,225,"Clear"); */
   setcolor(color);
}
void refresh(int toggle)
{
    int left, top, c, color;

   left = 529;
   top = 45;

   color = getcolor();
   setcolor(GREEN);
   DrawKotak(525,40,633,255);

   for( c = 1 ; c <= 3 ; c++ )
   {
      DrawKotak(left, top, left+49, top+25);
	  DrawKotak(left+51, top, left+100, top+25);
      top += 30;
   }
   DrawKotak(left, top, left+100, top+25);
   top += 30;
   DrawKotak(left, top, left+100, top+25);
   top += 30;
   DrawKotak(left, top, left+100, top+25);
   boundaryFill4(550,50, RED, WHITE);
   DrawKotak(550, 83, 558, 91);
   lineDDA(585, 50, 625, 65);
   boundaryFill4(555,87, WHITE, WHITE);
   elips(605, 87, 10, 10);
   DrawKotak(584, 109, 625, 126);
   if (toggle == 1)
   boundaryFill4(600,115, GREEN, WHITE);
   outtextxy(550,135,"CLEAR");
   outtextxy(550,165,"CLIP");
   outtextxy(550,195,"ACLIP");
 
   setcolor(RED);
  /* outtextxy(530,45,"tes");
   outtextxy(530,75,"Line");
   outtextxy(530,105,"Pixel");
   outtextxy(530,135,"Ellipse");
   outtextxy(530,165,"Freehand");
   outtextxy(530,195,"DrawKotak");
   outtextxy(530,225,"Clear"); */
   setcolor(color);
}
 
void change_color(int x, int y)
{
   int c;
 
   for( c = 0 ; c <= 13 ; c++ )
   {
      if( x > leftcolor[c] && x < leftcolor[c+1] && y > 437 && y < 453 )
         setcolor(c+1);
      if( x > leftcolor[14] && x < 505 && y > 437 && y < 453 )
         setcolor(WHITE);
   }
}
 
char change_shape(int x, int y)
{
     if ( x > 529 && x < 578 && y > 45 && y < 70 )
      return 'b';
   else if ( x > 580 && x < 629 && y > 45 && y < 70 )
      return 'l';
   else if ( x > 529 && x < 578 && y > 75 && y < 100 )
      return 'p';
   else if ( x > 580 && x < 629 && y > 75 && y < 100 )
      return 'e';
   else if ( x > 529 && x < 578 && y > 105 && y < 130 )
      return 'f';
   else if ( x > 580 && x < 629 && y > 105 && y < 130 )
   {
   cek=0;
      return 'r';
	}
   else if ( x > 529 && x < 625 && y > 135 && y < 160 )
      return 'c';
   else if ( x > 529 && x < 625 && y > 165 && y < 190 )
      return 'k';
   else if ( x > 529 && x < 625 && y > 195 && y < 220 )
      return 'a';
   
   
      
   return '0';
}
 
void showmouseptr()
{
   i.x.ax = 1;
   int86(0x33,&i,&o);
}
 
void hidemouseptr()
{
   i.x.ax = 2;
   int86(0x33,&i,&o);
}


void matrixIdentity(float T[3][3])
{

     int i,j;

    /*  Make matrix T as Identity Matrix by
    Storing 1 in the left diagonal positions of Matrix T
    and store 0 in other positions  */

     for(i=0;i<3;i++)
     {
     for(j=0;j<3;j++)
     {
	 if(i==j)
	   T[i][j]=1;
	 else
	   T[i][j]=0;

      }

     }


}



void matrixMul(float P[1][3],float T[3][3])
{

     int i,j,k;

     //Initialize Matrix P1 with Zero
     for(i=0;i<3;i++)
	 P1[0][i]=0;

     //Mutiply T with P and store the result in P1
     for(k=0;k<1;k++)
       for(i=0;i<3;i++)
       for(j=0;j<3;j++)
	P1[k][i]+=P[k][j]*T[j][i];
	
}

 void translate_point(int x,int y,int tx,int ty)
//Translate a point by translation factors tx,ty
{

     float T[3][3];
     matrixIdentity(T);
     T[2][0]=tx;
     T[2][1]=ty;

     P[0][0]=x;
     P[0][1]=y;
     P[0][2]=1;

     matrixMul(P,T);
}
void scale_point(int x,int y,float sx,float sy)
/* Scale a point by scaling factors sx,sy and
   with respect to some fixed point  */
{

      float S[3][3];
      matrixIdentity(S);

      S[0][0]=sx;
      S[2][0]=(1-sx)*pivot_x;
      S[1][1]=sy;
      S[2][1]=(1-sy)*pivot_y;

      P[0][0]=x;
      P[0][1]=y;
      P[0][2]=1;

      matrixMul(P,S);

}

void rotate_point(int x,int y,float angle)
// Rotate a point by given angle
{
	
     float R[3][3];
     float radian;
	angle*=-1;
     radian=(3.141/180)*angle;
     matrixIdentity(R);

     R[0][0]=cos(radian);
     R[1][0]=-1*sin(radian);
     R[2][0]=pivot_x*(1-cos(radian))+pivot_y*sin(radian);
     R[0][1]=sin(radian);
     R[1][1]=cos(radian);
     R[2][1]=pivot_y*(1-cos(radian))-pivot_x*sin(radian);

     P[0][0]=x;
     P[0][1]=y;
     P[0][2]=1;
     matrixMul(P,R);

}
void reflect_point_Y(int x,int y)
{
	cout<<"x "<<x<<"y "<<y;
     float R[3][3];
     matrixIdentity(R);
     R[0][0]=-1;
     P[0][0]=x;
     P[0][1]=y;
     P[0][2]=1;
     matrixMul(P,R);
}

void restrictmouseptr( int x1, int y1, int x2, int y2)
{
   i.x.ax = 7;
   i.x.cx = x1;
   i.x.dx = x2;
   int86(0x33,&i,&o);
 
   i.x.ax = 8;
   i.x.cx = y1;
   i.x.dx = y2;
   int86(0x33,&i,&o);
}
 
void getmousepos(int *button,int *x,int *y)
{
   i.x.ax = 3;
   int86(0x33,&i,&o);
 
   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}
 
int main()
{
	int toggle=0;
   int gd = DETECT,gm;
   int cek2=0;
   PDATA dataQueue[100];
   int maxQueue = 1000;
   int count=0;
   int maxx,maxy,x,y,button,prevx,prevy,temp1,temp2,key,color;
   char ch = 'f' ;            // default free-hand drawing
 
   initgraph(&gd,&gm,"C:\\TC\\BGI");
 
   maxx = getmaxx();
   maxy = getmaxy();
 
   setcolor(BLUE);
   DrawKotak(0,0,maxx,maxy);
 
   setcolor(WHITE);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   //outtextxy(maxx/2-180,maxy-28,"<a href="http://www.programmingsimplified.com"">www.programmingsimplified.com"</a>);
 
   draw_color_panel();
   refresh(toggle);
 
   setviewport(1,1,maxx-1,maxy-1,1);
 
   restrictmouseptr(1,1,maxx-1,maxy-1);
   showmouseptr();
   DrawKotak(2,2,518,427);
   setviewport(1,1,519,428,1);

   while(1)
   {
      if(kbhit())
      {
         key = get_key();
 
         if( key == 1 )
         {
            closegraph();
            exit(0);
         }
		/*else
		 {
			printf("%d",key);
		 }*/
      }
 
      getmousepos(&button,&x,&y);
 
      if( button == 1 )
      {
         if( x > 4 && x < 635 && y > 431 && y < 457 )
		 {
             change_color( x, y );
			 cek2=1;
	     }
         else if ( x > 529 && x < 625 && y > 40 && y < 250 )
		 {
             ch = change_shape( x, y );
			 cek2=1;
		 }
		 else
		 {
			cek2=0;
		 }
		 
				   
         temp1 = x ;
         temp2 = y ;
		if ( ch == 'c' )
		{
			ch = 'f';          // setting to freehand drawing
			clearviewport();

			setcolor(WHITE);
			DrawKotak(2,2,518,427);
			count=0;
			// for(int i=0;i<count;i++){
				
				// dataQueue[i].Draw();
			
			// }
		} 
		 if(cek2!=1)
		 {
         if ( ch == 'f' )
         {
			setcolor(WHITE);
            hidemouseptr();
            while( button == 1 )
            {
               lineDDA(temp1,temp2,x,y);
               temp1 = x;
               temp2 = y;
               getmousepos(&button,&x,&y);
            }
            showmouseptr();
			
         }
 
         while( button == 1)
            getmousepos(&button,&x,&y);
 
         /* to avoid interference of mouse while drawing */
         hidemouseptr();
 
         if( ch == 'p')
            putpixel(x,y,WHITE);
 
         else if ( ch == 'b' )
         {
			if (x > 2 && x < 518 && y > 2 && y < 427) 
			{
				boundaryFill4(x,y,getcolor(), WHITE);
				if(count<maxQueue){
					PDATA temp(3,getcolor());
					temp.x1 =x;
					temp.y1 =y;
					dataQueue[count]= temp;
					count++;
				}
			}
		}
		else if ( ch == 'l')
		{
	    setcolor(WHITE);
	    lineDDA(temp1,temp2,x,y);
		while(!kbhit())
			  {
				 key = get_key();
		 
				 if( key == 28 ) //jika ditekan enter
				 {
					PDATA temp(0,0);
					temp.x1 = temp1;
					temp.y1 = temp2;
					temp.x2 = x;
					temp.y2 = y;
		
					if(count<maxQueue){
						dataQueue[count]= temp;
						count++;
					}		
					break;
				 }
				 
				 else if(key==73)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					
					pivot_x=temp1;
					pivot_y=temp2;
					scale_point(x,y,1.1,1.1);
					x=P1[0][0];
					y=P1[0][1];
					lineDDA(temp1,temp2,x,y);
					 
				 }
				 else if(key==81)//jika di tekan .
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}					
					
					pivot_x=temp1;
					pivot_y=temp2;
					scale_point(x,y,0.9,0.9);
					x=P1[0][0];
					y=P1[0][1];
					lineDDA(temp1,temp2,x,y);
					 
				 }
				 else if(key==51)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=temp1;
					pivot_y=temp2;
					rotate_point(x,y,-45);
					x=P1[0][0];
					y=P1[0][1];
					lineDDA(temp1,temp2,x,y);
					 
				 }
				 else if(key==52)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=temp1;
					pivot_y=temp2;
					rotate_point(x,y,45);
					x=P1[0][0];
					y=P1[0][1];
					lineDDA(temp1,temp2,x,y);
					 
				 }
				 else if(key==77)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					translate_point(temp1,temp2,1,0);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,1,0);
					x=P1[0][0];
					y=P1[0][1];
					
					lineDDA(temp1,temp2,x,y);

				 }
				 else if(key==80)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(temp1,temp2,0,1);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,0,1);
					x=P1[0][0];
					y=P1[0][1];
					
					lineDDA(temp1,temp2,x,y);

				 }
				 else if(key==72)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(temp1,temp2,0,-1);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,0,-1);
					x=P1[0][0];
					y=P1[0][1];
					
					lineDDA(temp1,temp2,x,y);

				 }
				 else if(key==75)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(temp1,temp2,-1,0);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,-1,0);
					x=P1[0][0];
					y=P1[0][1];
					lineDDA(temp1,temp2,x,y);

				 }
				 
			  }
		
		}
		else if ( ch == 'e')
		{
		
	    setcolor(WHITE);
	    elips(temp1,temp2,abs(x-temp1),abs(y-temp2));
		while(!kbhit())
			  {
				 key = get_key();
		 
				 if( key == 28 ) //jika ditekan enter
				 {
					
					PDATA temp(2,0);
					temp.x1 = temp1;
					temp.y1 = temp2;
					temp.x2 = abs(x-temp1);
					temp.y2 = abs(y-temp2);
					if(count<maxQueue){
						dataQueue[count]= temp;
						count++;
					}			
					break;
				 }
				 
				 else if(key==73)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					
					pivot_x=temp1;
					pivot_y=temp2;
					scale_point(x,y,1.1,1.1);
					x=P1[0][0];
					y=P1[0][1];
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));
					 
				 }
				 else if(key==81)//jika di tekan .
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}					
					
					pivot_x=temp1;
					pivot_y=temp2;
					scale_point(x,y,0.9,0.9);
					x=P1[0][0];
					y=P1[0][1];
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));
					 
				 }
				 else if(key==51)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=temp1;
					pivot_y=temp2;
					rotate_point(x,y,-90);
					x=P1[0][0];
					y=P1[0][1];
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));
					 
				 }
				 else if(key==52)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=temp1;
					pivot_y=temp2;
					rotate_point(x,y,90);
					x=P1[0][0];
					y=P1[0][1];
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));
					 
				 }
				 else if(key==77)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					translate_point(temp1,temp2,1,0);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,1,0);
					x=P1[0][0];
					y=P1[0][1];
					
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));

				 }
				 else if(key==80)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(temp1,temp2,0,1);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,0,1);
					x=P1[0][0];
					y=P1[0][1];
					
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));

				 }
				 else if(key==72)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(temp1,temp2,0,-1);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,0,-1);
					x=P1[0][0];
					y=P1[0][1];
					
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));

				 }
				 else if(key==75)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(temp1,temp2,-1,0);
					temp1=P1[0][0];
					temp2=P1[0][1];
					translate_point(x,y,-1,0);
					x=P1[0][0];
					y=P1[0][1];
					elips(temp1,temp2,abs(x-temp1),abs(y-temp2));

				 }
				 
			  }
	
		}
		else if ( ch == 'r' )
		{
	    setcolor(WHITE);
		int x1,x2,x3,x4,y1,y2,y3,y4;
		x1=x;
		y1=temp2;
		x2=temp1;
		y2=temp2;
		x3=temp1;
		y3=y;
		x4=x;
		y4=y;
	    DrawKotak1(x1, y1, x2,y2,x3,y3,x4,y4);	
			while(!kbhit())
			  {
				 key = get_key();
		 
				 if( key == 28 ) //jika ditekan enter
				 {
					PDATA temp(1,0);
					temp.x1 = x1;
					temp.y1 = y1;
					temp.x2 = x2;
					temp.y2 = y2;
					temp.x3 = x3;
					temp.y3 = y3;
					temp.x4 = x4;
					temp.y4 = y4;
					if(count<maxQueue){
						dataQueue[count]= temp;
						count++;
					}					
					break;
				 }
				 
				 else if(key==73)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					
					pivot_x=x1;
					pivot_y=y1;
					scale_point(x2,y2,1.1,1.1);
					x2=P1[0][0];
					y2=P1[0][1];
					scale_point(x3,y3,1.1,1.1);
					x3=P1[0][0];
					y3=P1[0][1];
					scale_point(x4,y4,1.1,1.1);
					x4=P1[0][0];
					y4=P1[0][1];
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);
					 
				 }
				 else if(key==81)//jika di tekan .
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}					
					
					pivot_x=x1;
					pivot_y=y1;
					scale_point(x2,y2,0.9,0.9);
					x2=P1[0][0];
					y2=P1[0][1];
					scale_point(x3,y3,0.9,0.9);
					x3=P1[0][0];
					y3=P1[0][1];
					scale_point(x4,y4,0.9,0.9);
					x4=P1[0][0];
					y4=P1[0][1];
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);
					 
				 }
				 else if(key==51)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=x1;
					pivot_y=y1;
					rotate_point(x2,y2,-45);
					x2=P1[0][0];
					y2=P1[0][1];
					rotate_point(x3,y3,-45);
					x3=P1[0][0];
					y3=P1[0][1];
					rotate_point(x4,y4,-45);
					x4=P1[0][0];
					y4=P1[0][1];
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);
					 
				 }
				 else if(key==52)
				 {
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=x1;
					pivot_y=y1;
					rotate_point(x2,y2,45);
					x2=P1[0][0];
					y2=P1[0][1];
					rotate_point(x3,y3,45);
					x3=P1[0][0];
					y3=P1[0][1];
					rotate_point(x4,y4,45);
					x4=P1[0][0];
					y4=P1[0][1];
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);
					 
				 }
				 else if(key==77)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}
					pivot_x=x1;
					pivot_y=y1;
					translate_point(x1,y1,1,0);
					x1=P1[0][0];
					y1=P1[0][1];
					translate_point(x2,y2,1,0);
					x2=P1[0][0];
					y2=P1[0][1];
					translate_point(x3,y3,1,0);
					x3=P1[0][0];
					y3=P1[0][1];
					translate_point(x4,y4,1,0);
					x4=P1[0][0];
					y4=P1[0][1];
					
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);

				 }
				 else if(key==80)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(x1,y1,0,1);
					x1=P1[0][0];
					y1=P1[0][1];
					translate_point(x2,y2,0,1);
					x2=P1[0][0];
					y2=P1[0][1];
					translate_point(x3,y3,0,1);
					x3=P1[0][0];
					y3=P1[0][1];
					translate_point(x4,y4,0,1);
					x4=P1[0][0];
					y4=P1[0][1];
					
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);

				 }
				 else if(key==72)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(x1,y1,0,-1);
					x1=P1[0][0];
					y1=P1[0][1];
					translate_point(x2,y2,0,-1);
					x2=P1[0][0];
					y2=P1[0][1];
					translate_point(x3,y3,0,-1);
					x3=P1[0][0];
					y3=P1[0][1];
					translate_point(x4,y4,0,-1);
					x4=P1[0][0];
					y4=P1[0][1];
					
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);

				 }
				 else if(key==75)//jika tombol kanan ditekan
				 {			
					clearviewport();

					setcolor(WHITE);
					DrawKotak(2,2,518,427);
					
					for(int i=0;i<count;i++){
						
						dataQueue[i].Draw();
					
					}				 
					translate_point(x1,y1,-1,0);
					x1=P1[0][0];
					y1=P1[0][1];
					translate_point(x2,y2,-1,0);
					x2=P1[0][0];
					y2=P1[0][1];
					translate_point(x3,y3,-1,0);
					x3=P1[0][0];
					y3=P1[0][1];
					translate_point(x4,y4,-1,0);
					x4=P1[0][0];
					y4=P1[0][1];
					
					DrawKotak1(x1, y1, x2,y2, x3, y3,x4,y4);

				 }
				 
			  }

	 }
			else if(ch == 'k') {
					PDATA temp(4,0);
					temp.x1 = temp1;
					temp.y1 = temp2;
					temp.x2 = x;
					temp.y2 = y;
					if(count<maxQueue){
						dataQueue[count]= temp;
						count++;
					}
				clipp(temp1,temp2, x, y);	
			}
			else if(ch == 'a') {
			  if (toggle == 0) {
				   toggle = 1;
				   printf("TOGGLE ON");
				   
				   }
				else if (toggle == 1) {
				   toggle = 0;
				   printf("TOGGLE OFF");
				   
				   }
				   }
			
			
			
			

	 showmouseptr();
	 cout<<"isi queue : "<<count<<"\n";
    }
	}
	


   }
   
	
		
				   
}