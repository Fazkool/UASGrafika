#ifndef RINTANG_H
#define RINTANG_H
#include <graphics.h>
#include <Graph/DDA.cpp>
#include <Graph/transf2.cpp>
#include <iostream.h>
#include <Graph/recarea.cpp>

class Rintang{
	public :
		//attribut
		int Jenis;
		//vector<int> titik;
		int KodeWarna;
		int x1,x2,x3,x4,y1,y2,y3,y4;
		Rintang()
		{
			Jenis = 1;
			KodeWarna = 0;

		}
		//PDATA(int jenis , vector<int> Newtitik , int KW);
		Rintang(int jenis , int KW){
			Jenis = jenis;
			KodeWarna = KW;

		}
		//function
		void Draw(){
			switch(Jenis){
				case 0 :  //garis
					lineDDA(x1,y1,x2,y2);
					break;
				case 1 : //kotak
					DrawKotak1(x1, y1, x2, y2, x3, y3,x4,y4);
					break;
				case 3: //fill :v
					boundaryFill4(x1,y1,KodeWarna, WHITE);
					break;
			}
		}

};
#endif