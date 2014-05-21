#include <vector>
#include <string>
#include <iostream>

using namespace std;
class polygonData{
	public :
		//attribut
		int Jenis;
		vector<int> titik;
		int KodeWarna;
		
		polygonData();
		polygonData(int jenis , vector<int> Newtitik , int KW);
		polygonData(int jenis , int KW);
	
	};	
		//constructor
		polygonData::polygonData(){
			Jenis = 1;
			KodeWarna = 0;
		
		}
		polygonData::polygonData(int jenis , int KW){
			Jenis = jenis;
			KodeWarna = KW;
		
		}	
		polygonData::polygonData(int jenis , vector<int> Newtitik , int KW){
			Jenis = jenis;
			titik = Newtitik;
			KodeWarna = KW;
		
		}
		

int main(){

polygonData a(1,2);

cout<<"nilai jenis : "<< a.Jenis;






return 0;
}