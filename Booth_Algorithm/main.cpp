#include <iostream>
#include "booth_algorithm.h"
using namespace std;

int main(){
    cout << "\n\t\t\t\t\tALGORITMO BOOTH (MULTIPLICACION DE BINARIOS COMPLEMENTO-2)" << endl;
    int Q[4],M[4], a, b;
    booth_algorithm algoritmo;
	cout << "\n";
	a = algoritmo.entrada(1);
	b = algoritmo.entrada(0);
	cout << "\nDatos convertidos a binario: " << endl;
    algoritmo.binario(a, M);
    algoritmo.binario(b, Q);
	cout << "\n\n";

	algoritmo.tabla(a,b,M, Q);
}