#include <iostream>

using namespace std;
class POLYGONDATA{
	public :
		//attribut
		int Jenis;
		//vector<int> titik;
		int KodeWarna;
		int x1,x2,x3,y1,y2,y3
		POLYGONDATA();
		//POLYGONDATA(int jenis , vector<int> Newtitik , int KW);
		POLYGONDATA(int jenis , int KW);
	
		//function
		void Draw();
	
	};	
		//constructor
		POLYGONDATA::POLYGONDATA(){
			Jenis = 1;
			KodeWarna = 0;
		
		}
		POLYGONDATA::POLYGONDATA(int jenis , int KW){
			Jenis = jenis;
			KodeWarna = KW;
		
		}	
		// POLYGONDATA::POLYGONDATA(int jenis , vector<int> Newtitik , int KW){
			// Jenis = jenis;
			// titik = Newtitik;
			// KodeWarna = KW;
		
		// }
		
		void POLYGONDATA:: Draw(){
			switch(Jenis){
				case 0 :  //garis
					
					break;
				case 1 : //kotak
					
					break;
				
			
				default  :
					//something
			
			}
		}
		

int main(){

POLYGONDATA a(1,2);

cout<<"nilai jenis : "<< a.Jenis;



return 0;
}