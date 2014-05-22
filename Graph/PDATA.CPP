#ifndef PDATA_H
#define PDATA_H
#include <iostream.h>
class PDATA{
	public :
		//attribut
		int Jenis;
		//vector<int> titik;
		int KodeWarna;
		int x1,x2,x3,x4,y1,y2,y3,y4;
		//constructor
		PDATA::PDATA(){
			Jenis = 0;
			KodeWarna = 0;
			
		}
		PDATA::PDATA(int jenis , int KW){
			Jenis = jenis;
			KodeWarna = KW;

		}
		//function
		void Draw()
		{
			switch(Jenis){
				case 0 :  //garis
					lineDDA(x1,y1,x2,y2);
					break;
				case 1 : //kotak
					DrawKotak1(x1, y1, x2, y2, x3, y3,x4,y4);
					break;
				case 2 : //elipse
					elips(x1,y1,x2,y2);
					break;
				case 3: //fill :v
					boundaryFill4(x1,y1,KodeWarna, WHITE);
					break;
			}
		}

	};
		
		// PDATA::PDATA(int jenis , vector<int> Newtitik , int KW){
			// Jenis = jenis;
			// titik = Newtitik;
			// KodeWarna = KW;

		// }

		
		
		// void PDATA:: Draw(){
			// switch(Jenis){
				// case 0 :  //garis
					// lineDDA(x1,y1,x2,y2);
					// break;
				// case 1 : //kotak
					// DrawKotak1(x1, y1, x2, y2, x3, y3,x4,y4);
					// break;
				// case 3: //fill :v
					// boundaryFill4(x1,y1,KodeWarna, WHITE);
					// break;
			// }
		// }



#endif