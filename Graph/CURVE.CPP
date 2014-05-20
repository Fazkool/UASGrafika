#ifndef CURVE_H
#define CURVE_H
#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#include <dos.h>
float getBx(int x[],int n,float t){
	if(n == 1){
		float xx = (float)x[0];
		free(x);
		return xx;
	}else{
		int* recXKiri;
		int* recXKanan;
		recXKiri = (int*) malloc((n-1)*sizeof (int));
		recXKanan = (int*) malloc((n-1)*sizeof (int));
		for(int i = 0;i<n-1;i++){
			recXKiri[i] = x[i];
			recXKanan[i] = x[i+1];
		}
		//free(x);
		//recursive call
		return (1-t)*getBx(recXKiri,n-1,t)+t*getBx(recXKanan,n-1,t);
	}
}

float bCubic(int x[], float t){
	
}

void draw_curve(int x[],int y[],int n){
	for(float t = 0;t<1;t+=0.01){
		int xnew[50];
		int ynew[50];
		for(int i = 0;i<50;i++){
			xnew[i] = x[i];
			ynew[i] = y[i];
		}
		putpixel(getBx(xnew,n,t),getBx(ynew,n,t),WHITE);
	}
}

void bezier(int x[],int y[],int n){
	int faktorial(int);
	
	int sumx;
	int sumy;
	
	int i;
	float t;
	
	//cout << faktorial(n-i);
	 for(t = 0.01;t<1;t+=0.001){
		//cout << t << endl;
		sumx = 0;
		sumy = 0;
		for(i = 0;i<=n;i++){
			float pangkat;
			if(n-i == 1){
				 pangkat = 1;
			}else{
				pangkat = pow(1-t,n-i);
			}
			sumx += faktorial(n) / faktorial(i) / faktorial(n-i) * pangkat * pow(t,i) * x[i];
			sumy += faktorial(n) / faktorial(i) / faktorial(n-i) * pangkat * pow(t,i) * y[i];
			//cout << x[i] << " " <<faktorial(n) / faktorial(i) / faktorial(n-i) * pangkat * pow(t,i) * y[i] << endl; 
		}
		//cout <<sumx<< " " << sumy;
		putpixel(sumx,sumy,WHITE);
	 }
}

int faktorial(int number){//MENGHITUNG FAKTORIAL
	if(number <1){
		return 1;
	}

	int i;
	int sum = 1;

	for(i = number;i>1;i--){
		sum *= i;
	}
	return sum;
}

#endif