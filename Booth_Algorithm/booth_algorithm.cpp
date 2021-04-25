//
// Created by Usuario on 21/04/2021.
//
#include <iostream>
#include "booth_algorithm.h"
#include <math.h>
using namespace std;
booth_algorithm::booth_algorithm() {
    //construvtor
}
booth_algorithm::~booth_algorithm() {
    //destructoir
}
int booth_algorithm::modulo(int a, int n) {
    int q, r;
    q = a/n;
    r = a-(q*n);
    if (r < 0){
        q = (a/n)-1;
        r = a-(q*n);
    }
    return r;
}
int booth_algorithm::entrada(int a) {
    char variable='M';
    int flag=0;
    if(a==1) variable='Q';

    do{
        cout << "Ingrese valor de: " << variable << ": "; cin >> a; //ingreso de datos
        if(a < 0){
            a *= -1;
            flag = 1;
        }
        if(9 <= a) cout << "ups! solo puede ingresar datos del -9 al 9" << endl; //mensaje de error
    }while(9<=a);

    if(flag) a *= -1;
    return(a);
}
void booth_algorithm::suma(int *a, int *b) {
    int x,t=0;
    for(int i=3;i>=0;i--){
        x=a[i];
        a[i]= t ^ x ^ b[i];  //usando el operador xor binario " ^ "

        if(((t == 1) and (x == 1)) or ((x == 1) and (b[i] == 1)) or ((b[i] == 1) and (t == 1))) t = 1;
        else t = 0;
    }
}
void booth_algorithm::binario(int x, int *arreglo) {
    int p=x, c[4]={0,0,0,1};
    for(int i=0;i< 4; ++i){
        arreglo[i] = 0;
    }
    if(x < 0) x *= -1;

    int i = 3;
    do{
        arreglo[i] = modulo(x,2);
        x /=  2;
        i--;
    }while(x!=0);

    if(p< 0){
        for(int i=0;i< 4;++i) arreglo[i]= 1 - arreglo[i];
        suma(arreglo, c);
    }

    cout << "\n" << p << " en binario es: ";
    for(int i=0;i< 4;++i) cout << arreglo[i];
}
void booth_algorithm::cambiuo(int posX, int *posY) {
    for(int i=3;i>0;i--){
        posY[i] = posY[i - 1];
    }
    posY[0] = posX;
}
void booth_algorithm::tabla(int a, int b, int *Q, int *M) {
    int A[4]={0,0,0,0},C[4]={0,0,0,1},C1[8]={0,0,0,0,0,0,0,1},temp1[4],ans[8]; //declaracion de mis arrays
    int q=0,s=0,z=0,y,x=0,c=0; //declaracion de variables
    cout << "TABLA CON PASOS: \n" << endl;
    cout << " Operacion\t\t A\t Q\tQ(-1)\t M";
	cout << "\n Valores iniciales\t";

	for(int i=0;i< 4;i++){
		cout << A[i];
	}
	cout <<"\t";
	for(int i=0;i< 4;i++){
		cout << Q[i];
	}
	cout <<"\t";
	cout << q << "\t";

	for(int i=0;i< 4;i++) cout << M[i];

    for(int j=0;j< 4;j++){
        if((Q[3]==0) and (q==1)){
            cout <<"\n A =A+M \t\t";
            suma(A, M);
            for(int i=0;i< 4;i++) {
                cout << A[i];
            }
            cout <<"\t";
            for(int i=0;i< 4;i++) {
               cout << Q[i];
            }
            cout << "\t" << q << "\t";
            for(int i=0;i< 4;i++) {
                cout << M[i];
            }
        }
    if((Q[3]==1)&&(q==0)){
        cout << "\n A =A-M \t\t";
        for(int i=0;i< 4;i++) {
            temp1[i] = 1 - M[i];
        }
        suma(temp1, C);
        suma(A, temp1);
        for(int i=0;i< 4;i++) {
            cout << A[i];
        }
        printf("\t");
        for(int i=0;i< 4;i++) {
            cout << Q[i];
        }
        cout << "\t"<< q << "\t";
        for(int i=0;i< 4;i++) {
            cout << M[i];
        }
    }
        cout << "\n Shift \t\t\t";
        y = A[3];
        q = Q[3];
        cambiuo(A[0], A);
        cambiuo(y, Q);
        for(int i=0;i< 4;i++) {
            cout << A[i];
        }
        cout <<"\t";
        for(int i=0;i< 4;i++) {
            cout << Q[i];
        }
        cout <<"\t";
        cout << q << "\t" ;
        for(int i=0;i< 4;i++) {
           cout << M[i];
        }
    }

    cout <<"\n\nResultado en binario: ";
    for(int i=0;i< 4;++i) {
        ans[i] = A[i];
    }
    for(int i=0;i< 4;++i) {
        ans[i + 4] = Q[i];
    }

    if(((a< 0) and (b>0)) or ((a>0) and (b< 0))){
        for(int i=0;i< 8;++i) {
            ans[i] = 1 - ans[i];
        }

        for(int i=7;i>=0;--i){
            x = ans[i];
            ans[i]=c^x^C1[i];

            if(((c==1) and (x==1)) or ((x==1) and (C1[i]==1)) or ((C1[i]==1) and (c==1))) c=1;
            else c=0;
        }
    }
   for(int i=0;i< 8;++i) {
        cout << ans[i];
    }
    for(int i=7;i>=0;i--){
        s = s + (pow(2,z) * ans[i]);
        z = z+1;
    }
   if(((a< 0) and (b>0)) or ((a>0) and (b< 0))) {
        cout << "\nEl resultado en decimal: -" << s << endl;
    }
    else {
        cout << "\nEl resultado en decimal: " << s << endl;
    }
}