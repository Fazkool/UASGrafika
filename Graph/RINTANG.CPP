#ifndef RINTANG_H
#define RINTANG_H
#include <graphics.h>
#include <Graph/DDA.cpp>
#include <Graph/transf2.cpp>
#include <iostream.h>
#include <Graph/recarea.cpp>

class Rintang{
	public:
	
		//Posisi Mobil
		int mobilY;
	
		//UKURAN MAKSIMAL
		int maxx;
		int maxy;
		
		int x;
		int y;
		int type;
		int alive;
		
		//EMPAT SEKAWAN
		Rintang(){
			x = 0;
			y = 0;
			type = 0;
			alive = 0;
			maxx = 639;
			maxy = 479;
			mobilY = (479+1)/8*6-1;
		}

		Rintang(int nx,int ny,int ntype,int nalive){
			x = nx;
			y = ny;
			type = ntype;
			alive = nalive;
			maxx = 639;
			maxy = 479;
			mobilY = (479+1)/8*6-1;
		}

		Rintang(const Rintang& R){
			x = R.x;
			y = R.y;
			type = R.type;
			alive = R.alive;
			maxx = 639;
			maxy = 479;
			mobilY = (479+1)/8*6-1;
			//return *this;
		}

		~Rintang(){

		}

		//OPERATOR=
		Rintang& operator=(const Rintang& R){
			x = R.x;
			y = R.y;
			type = R.type;
			alive = R.alive;
			maxx = 639;
			maxy = 479;
			mobilY = (479+1)/8*6-1;
			return *this;
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
		
		
		void drawStone(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,bool rot ){
				//cara gambar degan asumsi no rotasi
				//urutan
				//    a 
				//2  c   3
				//		b
				//1      4
				//drawStone(40,80,40,60,90,60,90,80);
				int ax,ay,bx,by,cx,cy;
				ax = x1+(x4-x1)/2;
				ay = y2-(y4-y3)/3;
				bx = x4-(x4-x1)/3.5;
				by = y3+(y4-y3)/2.5;
				cx = x2+(x4-x1)/6;
				cy = y2;
				
				// if(rot){//gambar terbalik  //nil buat biar titik a , b, cikutkerotasi juga :v
									
					
					// Matrix3x3 mr;//ROTASI
					// Matrix3x3 mt;//TRANSLASI
					
					// transformPoints2(mr,x1,&ax,70+(mobilY+20),&ay);
					// transformPoints2(mt,ax,&ax,ay,&ay);
					
					// transformPoints2(mr,x*213+142,&dx,70+(mobilY+20),&dy);
					// transformPoints2(mt,dx,&dx,dy,&dy);
				
					// transformPoints2(mr,x*213+82,&bx,70+(mobilY-40),&by);
					// transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					
					// transformPoints2(mr,x*213+142,&cx,70+(mobilY-40),&cy);
					// transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					
				// }
				
				lineDDA(x1, y1, x4, y4);
				lineDDA(x1, y1, cx, cy);
				lineDDA(cx, cy, ax, ay);
				lineDDA(ax, ay, bx, by);
				lineDDA(bx, by, x4, y4);
		
		
		
		}
		//METHOD
		void draw(){
			int ax,ay,bx,by,cx,cy,dx,dy;
			if(type == 0){//BOX
				if(y<=10){
					
					Matrix3x3 ms;//SCALE
					Matrix3x3 mt;//TRANSLASI
					
					//TITIK PENGGAMBARAN
					int drawx1;//X1 SETELAH DITRANSFORMASI
					int drawy1;//Y1 SETELAH DITRANSFORMASI
					int drawx2;//X2 SETELAH DITRANSFORMASI
					int drawy2;//Y2 SETELAH DITRANSFORMASI
					int drawfx;//X UNTUK FILL
					int drawfy;//Y UNTUK FILL
					
					scale2(0.1*y,0.1*y,x*213+112,mobilY-10,ms);
					
					translate2(-(x-1)*(213)*(10-y)/10,-(mobilY-40-(maxy+1)/8-1)*(10-y)/10,mt);
					
					transformPoints2(ms,x*213+82,&drawx1,mobilY+20,&drawy1);
					transformPoints2(ms,x*213+142,&drawx2,mobilY+20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //BAWAH LUAR
					
					ax =drawx1;ay=drawy1;
					dx =drawx2;dy=drawy2;
					
					
					transformPoints2(ms,x*213+82,&drawx1,mobilY-40,&drawy1);
					transformPoints2(ms,x*213+142,&drawx2,mobilY-40,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//ATAS LUAR
					
					bx =drawx1;by=drawy1;
					cx =drawx2;cy=drawy2;
					
					transformPoints2(ms,x*213+82,&drawx1,mobilY+20,&drawy1);
					transformPoints2(ms,x*213+82,&drawx2,mobilY-40,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KIRI LUAR
					
					transformPoints2(ms,x*213+142,&drawx1,mobilY+20,&drawy1);
					transformPoints2(ms,x*213+142,&drawx2,mobilY-40,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					
					//KOTAK DALAM KOTAK
					
					transformPoints2(ms,x*213+92,&drawx1,mobilY+10,&drawy1);
					transformPoints2(ms,x*213+132,&drawx2,mobilY+10,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //BAWAH LUAR
					
					transformPoints2(ms,x*213+92,&drawx1,mobilY-30,&drawy1);
					transformPoints2(ms,x*213+132,&drawx2,mobilY-30,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//ATAS LUAR
					
					transformPoints2(ms,x*213+92,&drawx1,mobilY+10,&drawy1);
					transformPoints2(ms,x*213+92,&drawx2,mobilY-30,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KIRI LUAR
					
					transformPoints2(ms,x*213+132,&drawx1,mobilY+10,&drawy1);
					transformPoints2(ms,x*213+132,&drawx2,mobilY-30,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					
					//SILANG DALAM KOTAK
					
					transformPoints2(ms,x*213+92,&drawx1,mobilY+10,&drawy1);
					transformPoints2(ms,x*213+132,&drawx2,mobilY-30,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); // SILANG KIRI BAWAH KE KANAN ATAS
					
					transformPoints2(ms,x*213+92,&drawx1,mobilY-30,&drawy1);
					transformPoints2(ms,x*213+132,&drawx2,mobilY+10,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); // SILANG KIRI ATAS KE KANAN BAWAH
					
					DrawKotak1(ax,ay,bx,by,cx,cy,dx,dy);
					
					
					//AREA FILLNYA
					if(y>0){//KALO Y 0 JADI TITIK, GA AMAN BUAT FILL
						transformPoints2(ms,x*213+82,&drawfx,mobilY-40,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						boundaryFill4(drawfx+2,drawfy+1,BLUE,WHITE);
						
						//AREA FILL DI DALAM KOTAK BRO
						
						transformPoints2(ms,x*213+92+5,&drawfx,mobilY-27,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA ATAS
						
						transformPoints2(ms,x*213+92+5,&drawfx,mobilY+7,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA BAWAH
						
						transformPoints2(ms,x*213+93,&drawfx,mobilY-27,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA KIRI
						
						transformPoints2(ms,x*213+131,&drawfx,mobilY-27,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA KANAN
					}
					// lineDDA(x*213+82, yFactor()*(mobilY+20), x*213+142, yFactor()*(mobilY+20)); //BAWAH LUAR
					// lineDDA(x*213+88, yFactor()*(mobilY+15), x*213+137, yFactor()*(mobilY+15)); //BAWAH DALAM
					// lineDDA(x*213+82, yFactor()*(mobilY-40),x*213+142, yFactor()*(mobilY-40));//ATAS LUAR
					// lineDDA(x*213+87, yFactor()*(mobilY-35), x*213+137, yFactor()*(mobilY-35)); //ATAS DALAM
					// lineDDA(x*213+82, yFactor()*(mobilY+20), x*213+82, yFactor()*(mobilY-40)); //KIRI LUAR
					// lineDDA(x*213+87, yFactor()*(mobilY+15), x*213+87, yFactor()*(mobilY-35)); //KIRI DALAM
					// lineDDA(x*213+142, yFactor()*(mobilY+20), x*213+142, yFactor()*(mobilY-40)); //KANAN LUAR
					// lineDDA(x*213+137, yFactor()*(mobilY+15), x*213+137, yFactor()*(mobilY-35)); //KANAN DALAM
					// lineDDA(x*213+92, yFactor()*(mobilY+15), x*213+137, yFactor()*(mobilY-30));
					// lineDDA(x*213+87, yFactor()*(mobilY+10), x*213+132, yFactor()*(mobilY-35));
					// lineDDA(x*213+132, yFactor()*(mobilY+15), x*213+87, yFactor()*(mobilY-30));
					// lineDDA(x*213+137, yFactor()*(mobilY+10), x*213+92, yFactor()*(mobilY-35));
				}else{

					Matrix3x3 mr;//ROTASI
					Matrix3x3 mt;//TRANSLASI
				
					//TITIK PENGGAMBARAN
					int drawx1;//X1 SETELAH DITRANSFORMASI
					int drawy1;//Y1 SETELAH DITRANSFORMASI
					int drawx2;//X2 SETELAH DITRANSFORMASI
					int drawy2;//Y2 SETELAH DITRANSFORMASI
					int drawfx;//X UNTUK FILL
					int drawfy;//Y UNTUK FILL
					
					// cout << "kiri " << x*213+82 << "\n";
					// cout << "kanan " << x*213+142 << "\n";
					// cout << "atas " << 70+(mobilY-40) << "\n";
					// cout << "bawah " << 70+(mobilY+20) << "\n";
					// cout << "Tengah " << x*213+112 << " " << 70+(mobilY-10) <<"\n";
					
					
					rotate2(22.5*(y-11),x*213+112,70+(mobilY-10),mr);
					translate2((y-11)*(maxx-(x*213))/8,0,mt);
					
					transformPoints2(mr,x*213+82,&drawx1,70+(mobilY+20),&drawy1);
					transformPoints2(mr,x*213+142,&drawx2,70+(mobilY+20),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					ax =drawx1;ay=drawy1;
					dx =drawx2;dy=drawy2;
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //BAWAH LUAR

					transformPoints2(mr,x*213+82,&drawx1,70+(mobilY-40),&drawy1);
					transformPoints2(mr,x*213+142,&drawx2,70+(mobilY-40),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2);//ATAS LUAR
					bx =drawx1;by=drawy1;
					cx =drawx2;cy=drawy2;
					
					
					transformPoints2(mr,x*213+82,&drawx1,70+(mobilY+20),&drawy1);
					transformPoints2(mr,x*213+82,&drawx2,70+(mobilY-40),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KIRI LUAR
					
					
					
					transformPoints2(mr,x*213+142,&drawx1,70+(mobilY+20),&drawy1);
					transformPoints2(mr,x*213+142,&drawx2,70+(mobilY-40),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					//ax =drawx1;ay=drawy1;
					
					//KOTAK DALAM KOTAK
					
					transformPoints2(mr,x*213+92,&drawx1,70+(mobilY+10),&drawy1);
					transformPoints2(mr,x*213+132,&drawx2,70+(mobilY+10),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //BAWAH LUAR
					
					transformPoints2(mr,x*213+92,&drawx1,70+(mobilY-30),&drawy1);
					transformPoints2(mr,x*213+132,&drawx2,70+(mobilY-30),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//ATAS LUAR
					
					transformPoints2(mr,x*213+92,&drawx1,70+(mobilY+10),&drawy1);
					transformPoints2(mr,x*213+92,&drawx2,70+(mobilY-30),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KIRI LUAR
					
					transformPoints2(mr,x*213+132,&drawx1,70+(mobilY+10),&drawy1);
					transformPoints2(mr,x*213+132,&drawx2,70+(mobilY-30),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					
					//SILANG DALAM KOTAK
					
					transformPoints2(mr,x*213+92,&drawx1,70+(mobilY+10),&drawy1);
					transformPoints2(mr,x*213+132,&drawx2,70+(mobilY-30),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); // SILANG KIRI BAWAH KE KANAN ATAS
					
					transformPoints2(mr,x*213+92,&drawx1,70+(mobilY-30),&drawy1);
					transformPoints2(mr,x*213+132,&drawx2,70+(mobilY+10),&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); // SILANG KIRI ATAS KE KANAN BAWAH
					
					DrawKotak1(ax,ay,bx,by,cx,cy,dx,dy);
					
					//AREA FILLNYA
					transformPoints2(mr,x*213+82+5,&drawfx,70+(mobilY-37),&drawfy);
					transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
					boundaryFill4(drawfx,drawfy,BLUE,WHITE);
	
					//AREA FILL DI DALAM KOTAK BRO
					transformPoints2(mr,x*213+92+5,&drawfx,70+(mobilY-27),&drawfy);
					transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
					boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA ATAS
					
					transformPoints2(mr,x*213+92+5,&drawfx,70+(mobilY+7),&drawfy);
					transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
					boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA BAWAH
					
					transformPoints2(mr,x*213+93,&drawfx,70+(mobilY-27),&drawfy);
					transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
					boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA KIRI
					
					transformPoints2(mr,x*213+131,&drawfx,70+(mobilY-27),&drawfy);
					transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
					boundaryFill4(drawfx,drawfy,RED,WHITE); // SEGITIGA KANAN
	
					// lineDDA(x*213+82, 70+(mobilY+20), x*213+142, 70+(mobilY+20)); //BAWAH LUAR
					// lineDDA(x*213+88, 70+(mobilY+15), x*213+137, 70+(mobilY+15)); //BAWAH DALAM
					// lineDDA(x*213+82, 70+(mobilY-40),x*213+142, 70+(mobilY-40));//ATAS LUAR
					// lineDDA(x*213+87, 70+(mobilY+-35), x*213+137, 70+(mobilY-35)); //ATAS DALAM
					// lineDDA(x*213+82, 70+(mobilY+20), x*213+82, 70+(mobilY-40)); //KIRI LUAR
					// lineDDA(x*213+87, 70+(mobilY+15), x*213+87, 70+(mobilY-35)); //KIRI DALAM
					// lineDDA(x*213+142, 70+(mobilY+20), x*213+142, 70+(mobilY-40)); //KANAN LUAR
					//lineDDA(x*213+137, 70+(mobilY+15), x*213+137, 70+(mobilY-35)); //KANAN DALAM
					//lineDDA(x*213+92, 70+(mobilY+15), x*213+137, 70+(mobilY-30));
					//lineDDA(x*213+87, 70+(mobilY+10), x*213+132, 70+(mobilY-35));
					//lineDDA(x*213+132, 70+(mobilY+15), x*213+87, 70+(mobilY-30));
					//lineDDA(x*213+137, 70+(mobilY+10), x*213+92, 70+(mobilY-35));
				}
			}else if(type == 1){//STONE
				//lineDDA(40, 80, 90, 80);
				//lineDDA(40, 80, 50, 60);
				//lineDDA(50, 60, 55, 55);
				//lineDDA(55, 55, 75, 65);
				//lineDDA(75, 65, 90, 80);
				//drawStone(40,80,40,60,90,60,90,80);
				
				
				 if(y<=10){

					 Matrix3x3 ms;//SCALE
					 Matrix3x3 mt;//TRANSLASI


					 // b   c
					// a   d
					//TITIK PENGGAMBARAN
					int drawx1;//X1 SETELAH DITRANSFORMASI
					int drawy1;//Y1 SETELAH DITRANSFORMASI
					int drawx2;//X2 SETELAH DITRANSFORMASI
					int drawy2;//Y2 SETELAH DITRANSFORMASI
					int drawfx;//X UNTUK FILL
					int drawfy;//Y UNTUK FILL

					scale2(0.1*y,0.1*y,x*213+112,mobilY-10,ms);

					translate2(-(x-1)*(213)*(10-y)/10,-(mobilY-40-(maxy+1)/8-1)*(10-y)/10,mt);

					transformPoints2(ms,x*213+82,&drawx1,mobilY+20,&drawy1);
					transformPoints2(ms,x*213+142,&drawx2,mobilY+20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //BAWAH LUAR
					ax =drawx1;ay=drawy1;
					dx = drawx2;dy=drawy2;

					transformPoints2(ms,x*213+82,&drawx1,mobilY-40,&drawy1);
					transformPoints2(ms,x*213+142,&drawx2,mobilY-40,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2);//ATAS LUAR
					bx =drawx1;by=drawy1;
					cx = drawx2;cy=drawy2;
					// transformPoints2(ms,x*213+82,&drawx1,mobilY+20,&drawy1);
					// transformPoints2(ms,x*213+82,&drawx2,mobilY-40,&drawy2);
					// transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					// transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KIRI LUAR
					
					// transformPoints2(ms,x*213+142,&drawx1,mobilY+20,&drawy1);
					// transformPoints2(ms,x*213+142,&drawx2,mobilY-40,&drawy2);
					// transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					// transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					
					
					drawStone(ax,ay,bx,by,cx,cy,dx,dy,false);
					//AREA FILLNYA
					if(y>0){//KALO Y 0 JADI TITIK, GA AMAN BUAT FILL
						transformPoints2(ms,x*213+82,&drawfx,mobilY-40,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						boundaryFill4(drawfx+4+y,drawfy+5,DARKGRAY,WHITE);
					}
				}else{

					Matrix3x3 mr;//ROTASI
					Matrix3x3 mt;//TRANSLASI

					//TITIK PENGGAMBARAN
					int drawx1;//X1 SETELAH DITRANSFORMASI
					int drawy1;//Y1 SETELAH DITRANSFORMASI
					int drawx2;//X2 SETELAH DITRANSFORMASI
					int drawy2;//Y2 SETELAH DITRANSFORMASI
					int drawfx;//X UNTUK FILL
					int drawfy;//Y UNTUK FILL

					rotate2(22.5*(y-11),x*213+70+32,mobilY+40,mr);
					translate2((y-11)*(maxx-(x*213))/8,0,mt);

					transformPoints2(mr,x*213+40+32,&drawx1,mobilY+80,&drawy1);
					transformPoints2(mr,x*213+100+32,&drawx2,mobilY+80,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//BAWAH
					
					transformPoints2(mr,x*213+40+32,&drawx1,mobilY+80,&drawy1);
					transformPoints2(mr,x*213+50+32,&drawx2,mobilY+20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//KIRI BAWAH
					
					transformPoints2(mr,x*213+50+32,&drawx1,mobilY+20,&drawy1);
					transformPoints2(mr,x*213+65+32,&drawx2,mobilY+0,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//KIRI ATAS
					
					transformPoints2(mr,x*213+65+32,&drawx1,mobilY+0,&drawy1);
					transformPoints2(mr,x*213+85+32,&drawx2,mobilY+55,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//KANAN ATAS
					
					transformPoints2(mr,x*213+85+32,&drawx1,mobilY+55,&drawy1);
					transformPoints2(mr,x*213+100+32,&drawx2,mobilY+80,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2);//KANAN BAWAH

					//AREA FILL
					transformPoints2(mr,x*213+40+32+4,&drawfx,mobilY+80-5,&drawfy);
					transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
					boundaryFill4(drawfx,drawfy,DARKGRAY,WHITE);
					
					
					// lineDDA(x*213+40+32, mobilY+80, x*213+100+32, mobilY+80);//BAWAH
					// lineDDA(x*213+40+32, mobilY+80, x*213+50+32, mobilY+20);//KIRI BAWAH
					// lineDDA(x*213+50+32, mobilY+20, x*213+65+32, mobilY+0);//KIRI ATAS
					// lineDDA(x*213+65+32, mobilY+0, x*213+85, mobilY+55);//KANAN ATAS
					// lineDDA(x*213+85+32, mobilY+55, x*213+100, mobilY+80);//KANAN BAWAH

					
				}
			
			}else if(type == 2){
				if(y<=10){

					 Matrix3x3 ms;//SCALE
					 Matrix3x3 mt;//TRANSLASI

					
					 // b   c
					// a   d
					//TITIK PENGGAMBARAN
					int drawx1;//X1 SETELAH DITRANSFORMASI
					int drawy1;//Y1 SETELAH DITRANSFORMASI
					int drawx2;//X2 SETELAH DITRANSFORMASI
					int drawy2;//Y2 SETELAH DITRANSFORMASI
					int drawfx;//X UNTUK FILL
					int drawfy;//Y UNTUK FILL

					scale2(0.1*y,0.1*y,x*213+112,mobilY-10,ms);

					translate2(-(x-1)*(213)*(10-y)/10,-(mobilY-40-(maxy+1)/8-1)*(10-y)/10,mt);


					transformPoints2(ms,x*213+120,&drawx1,mobilY,&drawy1);
					transformPoints2(ms,5,&drawx2,5,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					circleMidPoint(drawx1,drawy1,y*30/10);
					boundaryFill4(drawx1,drawy1,RED,WHITE);
					lineDDA(drawx1, drawy1, drawx1-((y*30/10)-(y*30/10)*0.4), drawy1-((y*30/10)-(y*30/10)*0.4)); //KANAN LUAR
					lineDDA(drawx1, drawy1, drawx1+((y*30/10)-(y*30/10)*0.4), drawy1+((y*30/10)-(y*30/10)*0.4)); //KANAN LUAR
					
					lineDDA(drawx1, drawy1, drawx1-((y*30/10)), drawy1); //KANAN LUAR
					lineDDA(drawx1, drawy1, drawx1+((y*30/10)), drawy1); //KANAN LUAR
					
					lineDDA(drawx1, drawy1, drawx1, drawy1-((y*30/10))); //KANAN LUAR
					lineDDA(drawx1, drawy1, drawx1, drawy1+((y*30/10))); //KANAN LUAR
					
					lineDDA(drawx1, drawy1, drawx1-((y*30/10)-(y*30/10)*0.4), drawy1+((y*30/10)-(y*30/10)*0.4)); //KANAN LUAR
					lineDDA(drawx1, drawy1, drawx1+((y*30/10)-(y*30/10)*0.4), drawy1-((y*30/10)-(y*30/10)*0.4)); //KANAN LUAR
					
					
					circleMidPoint(drawx1,drawy1,(y*30/10)+(y*30/10)*0.4);
					

			//AREA FILLNYA
					if(y>0){//KALO Y 0 JADI TITIK, GA AMAN BUAT FILL
						transformPoints2(ms,x*213+82,&drawfx,mobilY-40,&drawfy);
						transformPoints2(mt,drawfx,&drawfx,drawfy,&drawfy);
						//boundaryFill4(drawfx+2,drawfy+1,BLUE,WHITE);
					}
				}else{

					Matrix3x3 mr;//ROTASI
					Matrix3x3 mt;//TRANSLASI

					//TITIK PENGGAMBARAN
					int drawx1;//X1 SETELAH DITRANSFORMASI
					int drawy1;//Y1 SETELAH DITRANSFORMASI
					int drawx2;//X2 SETELAH DITRANSFORMASI
					int drawy2;//Y2 SETELAH DITRANSFORMASI
					int drawfx;//X UNTUK FILL
					int drawfy;//Y UNTUK FILL

					rotate2(22.5*(y-11),x*213+142,70+(mobilY+20),mr);
					translate2((y-11)*(maxx-(x*213))/8,0,mt);


					transformPoints2(mr,x*213+142,&drawx1,70+(mobilY+20),&drawy1);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);

					//lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					
					circleMidPoint(drawx1,drawy1,33);
					boundaryFill4(drawx1,drawy1,RED,WHITE);
					circleMidPoint(drawx1,drawy1,46);		
					
					int tempx = x*213+142;
					int tempy = 70+(mobilY+20);
					
					//bagian gambar nya
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx-20,&drawx2,tempy-20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx+20,&drawx2,tempy+20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					// lineDDA(drawx1, drawy1, drawx1+20, drawy1+20); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx-33,&drawx2,tempy,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					// lineDDA(drawx1, drawy1, drawx1-33, drawy1); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx+33,&drawx2,tempy,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					// lineDDA(drawx1, drawy1, drawx1+33, drawy1); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx,&drawx2,tempy-33,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					// lineDDA(drawx1, drawy1, drawx1, drawy1-33); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx,&drawx2,tempy+33,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					// lineDDA(drawx1, drawy1, drawx1, drawy1+33); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx-20,&drawx2,tempy+20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR
					// lineDDA(drawx1, drawy1, drawx1-20, drawy1+20); //KANAN LUAR
					
					transformPoints2(mr,tempx,&drawx1,tempy,&drawy1);
					transformPoints2(mr,tempx+20,&drawx2,tempy-20,&drawy2);
					transformPoints2(mt,drawx1,&drawx1,drawy1,&drawy1);
					transformPoints2(mt,drawx2,&drawx2,drawy2,&drawy2);
					lineDDA(drawx1, drawy1, drawx2, drawy2); //KANAN LUAR	
					// lineDDA(drawx1, drawy1, drawx1+20, drawy1-20); //KANAN LUAR
					
					

					//boundaryFill4(drawfx,drawfy,BLUE,WHITE);

				}
			}
		}
		float yFactor(){//MENGHITUNG LETAK PENGGAMBARAN DARI Y
			return 1;
		}
		
		int size(){//MENGHITUNG UKURAN PENGGAMBARAN
			return 0;
		}
};
#endif