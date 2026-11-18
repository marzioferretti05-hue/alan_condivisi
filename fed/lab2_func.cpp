#include <vector>
#include <iostream>
#include <cmath>
#include "lab2_func.h"

using namespace std;

vector<vector<float>> flipVector(const vector<vector<float>> &v){
	int v_righe = v.size();
	int v_colonne = v[0].size();
	if(v_righe == 1){
		vector<vector<float>> w(v_colonne, vector<float>(1, 0));
		for(int i = 0; i < v_colonne; i++){
			w[i][0] = v[0][i];
		}
		return w;
	}
	else if(v_colonne == 1){
		vector<vector<float>> w(1, vector<float>(v_righe, 0));
		for(int i = 0; i < v_righe; i++){
			w[0][i] = v[i][0];
		}
		return w;
	}
	else{
		cout<<"errore, la matrice passata non è un vettore"<<endl;
		exit(1);
	}
}

float normaInf(vector<vector<float>> a){
	int a_righe = a.size();
	int a_colonne = a[0].size();
	
	//se è un vettore riga, lo trasforma in colonna
	if(a_righe == 1){
		a = flipVector(a);
		a_righe = a.size();
		a_colonne = a[0].size();
	}
	
	float norma = 0;
	float somma = 0;
	float aux = 0;
	for(int i = 0; i < a_righe; i++){
		somma = 0;
		for(int j = 0; j < a_colonne; j++){
			aux = a[i][j];
			somma = somma + abs(aux);
		}
		if (norma < somma)
			norma = somma;
	}
	return norma;
}

float factorial(float N){
	if(N == 0 || N == 1)
		return 1;
	return N * factorial(N-1);
}

void printMatrix(const vector<vector<float>> &a){
	int righe = a.size();
	int colonne = a[0].size();
	
	if(righe == 1 || colonne == 1){ //se è un vector, stampo orizzontalmente
		cout<<"{ ";
		for(int i = 0; i < righe; i++){
			for(int j = 0; j < colonne; j++){
			cout << a[i][j] << " ";
			}
		}
		cout<<"}"<<endl;
		return;
	}
	//cout << "STAMPA MATRICE:" << endl;
	//def tolta una riga, meglio scriverla dinamicamente nel main
	for(int i = 0; i < righe; i++){
		cout<<"{ ";
		for(int j = 0; j < colonne; j++){
			cout << a[i][j] << " ";
		}
		cout<<"}"<<endl;
	}
	return;
}

vector<vector<float>> pascal(const int &n){
	vector<vector<float>> matrixP(n, vector<float>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matrixP[i][j] = factorial(i+1 + j+1 - 2) / (factorial(i+1 - 1) * factorial(j+1 -1));
		}
	}
	return matrixP;
}

vector<vector<float>> triang(const int &n){
	vector<vector<float>> matrixN(n, vector<float>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				matrixN[i][j] = 2;
			}
			else if(abs(i-j) == 1){
				matrixN[i][j] = -1;
			}
			else{
				matrixN[i][j] = 0;
			}
		}
	}
	return matrixN;
}

//def tolta newMatrix, rindondante

vector<vector<float>> moltMatrix(const vector<vector<float>> &a, const vector<vector<float>> &b){
	int a_righe = a.size();
	int a_colonne = a[0].size();
	int b_righe = b.size();
	int b_colonne = b[0].size();
	
	if(a_colonne != b_righe){
		cout<<"errore, numero di righe e colonne errato"<<endl;
		exit(1);
	}
	
	vector<vector<float>> c(a_righe, vector<float>(b_colonne, 0));
	
	//def tolta una variabile ausiliaria superflua, tolti cout di debug
	for(int i = 0; i < a_righe; i++){
		for(int j = 0; j < b_colonne; j++){
			for(int k = 0; k < b_righe; k++){
				c[i][j] = c[i][j] + (a[i][k]*b[k][j]);
			}
		}
	}
	
	return c;
}

void swap(float &a, float &b){
	float c;
	c = a;
	a = b;
	b = c;
	return;
}

void scambioRighe(vector<vector<float>> &a, int x, int y){
	int a_righe = a.size();
	//def semplificato scambioRighe, aggiunto controllo
	if (x < 0 || y < 0 || x >= a_righe || y >= a_righe){
		cout<<"errore, numero di righe o colonne errato"<<endl;
		exit(1);
	}
	swap(a[x], a[y]);
	return;
}

vector<vector<float>> gauss(vector<vector<float>> a){
	int a_righe = a.size();
	int a_colonne = a[0].size();
	
	int size = 0;
	if (a_righe < a_colonne){
		size = a_righe;
	}
	else{
		size = a_colonne;
	}
	
	float coeff = 0;
	float pivot = 0;
	int rigaPivot = 0;
	for(int x = 0; x < size; x++){
		
		//scelta del pivot
		pivot = 0;
		rigaPivot = x;
		for(int i = x; i < a_righe; i++){
			if(abs(a[i][x])>pivot){
				pivot = abs(a[i][x]);
				rigaPivot = i;
				//def aggiunto un controllo per il valore assoluto, corretta indentazione
			}
		}
		scambioRighe(a, x, rigaPivot);
		
		//gauss
		for(int i = x+1; i < a_righe; i++){
			if(a[i][x]!=0){
				coeff = (-1 * a[i][x]) / a[x][x];
				for(int j = x; j < a_colonne; j++){
					a[i][j] = (a[x][j] * coeff) + a[i][j];
					//printMatrix(a); //debug
				}
			}
		}
	}
	return a;
}
void matrixFuseGauss(vector<vector<float>> &m, vector<vector<float>> &v){
	int m_righe = m.size();
	int m_colonne = m[0].size();
	int v_righe = v.size();
	int v_colonne = v[0].size();
	//controllo che il numero di righe della matrice m e quelle del vettore v sono uguali
	//e controllo che vettore sia di una riga soltanto
	if(m_righe != v_righe || v_colonne != 1){
		cout<<"Grandezza di matrice o vector sbagliata"<<endl;
		exit(1);
	}
	vector<vector<float>> f(m_righe, vector<float>((m_colonne+1), 1));
	
	for(int i = 0; i < m_righe; i++){
		for(int j = 0; j < m_colonne; j++){
			f[i][j] = m[i][j];
		}
		f[i][m_colonne] = v[i][0];
	}
	
	//printMatrix(f); //debug
	f = gauss(f);
	
	for(int i = 0; i < m_righe; i++){
		for(int j = 0; j < m_colonne; j++){
			m[i][j] = f[i][j];
		}
		v[i][0] = f[i][m_colonne];
	}
	return;
}

vector<vector<float>> sostituzioneIndietro(const vector<vector<float>> &m, const vector<vector<float>> &v){
	int m_righe = m.size();
	int m_colonne = m[0].size();
	int v_righe = v.size();
	int v_colonne = v[0].size();

	if(m_righe != m_colonne || v_righe != m_righe || v_colonne != 1){
		cout<<"errore nella sostituzione all'indietro, bisogna passare una matrice e un vettore"<<endl;
		exit(1);
	}
	
	vector<vector<float>> x(m_righe, vector<float>(1, 0));
	
	//calcolo sostituzione
	float aux;
	for(int i = m_righe-1; i >= 0; i--){ //def da vedere perchè c'è anche un uguale
		aux = 0;
		for(int j = i+1; j < m_righe; j++){
			aux = aux + m[i][j] * x[j][0];
		}
		x[i][0] = (v[i][0] - aux) / m[i][i];
	}
	
	return x;
}

void es2(vector<vector<float>> matrixM, char n){
	cout<<endl<<"--Esercizio 2, matrice "<<n<<"--"<<endl<<endl;
	
	int heightM = matrixM[0].size();
	vector<vector<float>> x(heightM, vector<float>(1, 1));
	
	cout<<"data la matrice "<<n<<": "<< endl;
	printMatrix(matrixM);
	cout<<"e il vettore x: "<<endl;
	printMatrix(x);
	
	cout<<"calcoliamo il vettore b dato dal prodotto "<<n<<" * x: "<<endl;
	vector<vector<float>> b = moltMatrix(matrixM, x);
	printMatrix(b);
	
	cout<<"da b, risolviamo in precisione singola il sistema "<<n<<"x = b applicando Gauss alla matrice "<<n<<" U b,"<<endl;
	vector<vector<float>> matrixU = matrixM;
	matrixFuseGauss(matrixU, b);
	
	cout<<"per poi applicare la retro sostituzione, ottenendo un vettore: "<<endl;
	vector<vector<float>> s = sostituzioneIndietro(matrixU, b);
	printMatrix(s);
	cout<<"uguale al vettore di partenza x: "<<endl;
	printMatrix(x);
}

void es3(vector<vector<float>> matrixM, char n){
	cout<<endl<<"--Esercizio 3, matrice "<<n<<"--"<<endl<<endl;
	
	int heightM = matrixM[0].size();
	
	cout<<"Riapplico le stesse procedure sul vettore noto δb, dato da b + il vettore di perturbazioni:"<<endl;
	
	vector<vector<float>> x(heightM, vector<float>(1, 1));
	//def tolta newMatrix, dovremmo fare una funzione che giri il vector se necessario
	
	cout<<"data la matrice "<<n<<": "<< endl;
	printMatrix(matrixM);
	cout<<"e il vettore x: "<<endl;
	printMatrix(x);
	
	cout<<"calcoliamo il vettore b dato dal prodotto "<<n<<" * x: ";
	vector<vector<float>> b = moltMatrix(matrixM, x);
	printMatrix(b);
	
	cout<<"al quale sommiamo il vettore di perturbazioni: ";
	vector<vector<float>> db = b;
	vector<vector<float>> p(heightM, vector<float>(1, 0));
	float pert = -0.01;
	for(unsigned long int i = 0; i < db.size(); i++){
		p[i][0] = p[i][0] + pert;
		pert = pert * -1;
	}
	//printMatrix(p);
	float norma = normaInf(b);
	//cout<<norma<<endl;
	for(unsigned long int i = 0; i < db.size(); i++){
		p[i][0] = (p[i][0] * norma);
	}
	printMatrix(p);
	for(unsigned long int i = 0; i < db.size(); i++){
		db[i][0] = db[i][0] + p[i][0];
	}
	cout<<"con risultato: ";
	printMatrix(db);
	
	
	cout<<"da b, risolviamo in precisione singola il sistema "<<n<<"x = b applicando Gauss alla matrice "<<n<<" U b,"<<endl;
	vector<vector<float>> matrixU = matrixM;
	matrixFuseGauss(matrixU, db);
	
	cout<<"per poi applicare la retro sostituzione, ottenendo un vettore: "<<endl;
	vector<vector<float>> s = sostituzioneIndietro(matrixU, db);
	printMatrix(s);
	cout<<"uguale al vettore di partenza x: "<<endl;
	printMatrix(x);
}