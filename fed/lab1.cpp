#include <iostream>
#include <cmath>
using namespace std;

void es1(){
	cout << "ESERCIZIO 1:" << endl<<endl;
	for(int i = 0; i < 7; i++){
		double d0 = 9.0;
		double d1 = 5.0;
		double a = (d0 + 1) * pow(10, i);
		double b = (d1 + 1) * pow(10, 20);
		double c = -b;
		double result = (a + b) + c;
		cout <<"iterazione "<<i<<endl;
		cout<<"- risultato 1: "<< result<<endl ;
		result = a + (b + c);
		cout <<"- risultato 2: "<< result <<endl;
		cout<<endl;
	}
}

double factorial(double N){
	if(N == 0 || N == 1)
		return 1;
	return N * factorial(N-1);
}

double taylor(double x, double N){
	double tot = 0;
	for(int n = 0; n <= N; n++){
		tot = tot + pow(x, n)/factorial(n);
		//cout << tot << endl;
 	}
 	return tot;
}   

/*
void es2(){
	double x = 0.5;
	
	double N = 3.0;
	double ris = taylor(x, N);
	cout << endl << "Risultato: " << ris << endl;
	
	N = 10.0;
	ris = taylor(x, N);
	cout << endl << "Risultato: " << ris << endl;
	
	N = 50.0;
	ris = taylor(x, N);
	cout << endl << "Risultato: " << ris << endl;
	
	N = 100.0;
	ris = taylor(x, N);
	cout << endl << "Risultato: " << ris << endl;
	
	N = 150.0;
	ris = taylor(x, N);
	cout << endl << "Risultato: " << ris << endl;
}
*/

void es2(){
	cout << endl << "ESERCIZIO 2 - algoritmo 1:" << endl;
	double x[] = {0.5, -0.5, 30.0, -30.0};
	double N[] = {3, 10, 50, 100, 150};
	
	double ris = 0;
	//cout << endl << "Risultato: " << ris << endl;
	
	cout<<endl<<"Dato x = "<<x[0]<<": "<<endl;

	cout<<"- e^x = "<<exp(x[0])<<endl;

	cout<<"- Con taylor al variare di N  = [";
	for(int i = 0; i < 5; i++){
		ris = taylor(x[0], N[i]);
		if(i == 4){
			cout<<ris<<"]"<<endl;
		}else{
			cout<<ris<<", ";
		}
	}
	
	cout<<endl<<"Dato x = "<<x[1]<<": "<<endl;

	cout<<"- e^x = "<<exp(x[1])<<endl;

	cout<<"- Con taylor al variare di N  = [";
	for(int i = 0; i < 5; i++){
		ris = taylor(x[1], N[i]);
		if(i == 4){
			cout<<ris<<"]"<<endl;
		}else{
			cout<<ris<<", ";
		}
	}
	
	cout<<endl<<"Dato x = "<<x[2]<<": "<<endl;

	cout<<"- e^x = "<<exp(x[2])<<endl;

	cout<<"- Con taylor al variare di N  = [";
	for(int i = 0; i < 5; i++){
		ris = taylor(x[2], N[i]);
		if(i == 4){
			cout<<ris<<"]"<<endl;
		}else{
			cout<<ris<<", ";
		}
	}
	
	cout<<endl<<"Dato x = "<<x[3]<<": "<<endl;

	cout<<"- e^x = "<<exp(x[3])<<endl;

	cout<<"- Con taylor al variare di N  = [";
	for(int i = 0; i < 5; i++){
		ris = taylor(x[3], N[i]);
		if(i == 4){
			cout<<ris<<"]"<<endl;
		}else{
			cout<<ris<<", ";
		}
	}

	cout << endl << "ESERCIZIO 2 - algoritmo 2:" << endl;

	cout<<endl<<"Dato x = "<<x[0]<<": "<<endl;

	cout<<"e^-x = "<<exp(x[1])<<endl;

	cout<<"il quale si può approssimare calcolando fN(0.5) e facendone il reciproco [";
	for(int i = 0; i < 5; i++){
		ris = taylor(x[0], N[i]);
		if(i == 4){
			cout<<1/ris<<"]"<<endl;
		}else{
			cout<<1/ris<<", ";
		}
	}

	cout<<endl<<"Dato x = "<<x[2]<<": "<<endl;

	cout<<"e^-x = "<<exp(x[3])<<endl;

	cout<<"il quale si può approssimare calcolando fN(30) e facendone il reciproco [";
	for(int i = 0; i < 5; i++){
		ris = taylor(x[2], N[i]);
		if(i == 4){
			cout<<1/ris<<"]"<<endl;
		}else{
			cout<<1/ris<<", ";
		}
	}
}

void es3(){
	cout << endl << "ESERCIZIO 3:" << endl;
	int d = 1;
	float espf = pow(2, -d);
	double espd = pow(2, -d);
	for(;1 + espf > 1; d++){
		espf = pow(2, -d);
	}
	cout << "Con d(float) = " << d << " la disequazione ";
	cout <<"1+2^-d > 1 diventa falsa"<<endl;
	cout <<"eps(float) = " <<espf<<endl;
	
	d = 1;
	for(;1 + espd > 1; d++){
		espd = pow(2, -d);
	}
	cout << "Con d(double) = " << d << " la disequazione ";
	cout <<"1+2^-d > 1 diventa falsa"<<endl;
	cout <<"eps(double) = " <<espd<<endl;
	
}

int main(){
	es1();
	es2();
	es3();
}


