/*
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 

    El siguiente codigo muestra la implementacion
    del algorimo de Dijkstra en lenguaje c.
*/

#include <stdio.h>
#define x 9
#define n 9
#define infinity 9999
 
typedef int dato;//tipo de definicion de un entero a dato

typedef struct set{//Estructura que asimila un conjunto de datos 
  dato Elem[n];
  int cardinalidad;
}set;

int in(set A, dato d);//operacion de pertenencia de un dato a unconjunto
set insert(set A, dato d);//operacion para insertar un datos a un conjunto
set complement(set A, set B);//operacion para obtener la diferencia de dos conjuntos
int W(int A[], set B);//obtener el indice del menor elemento que este dentro de un conjunto, del arreglo A
int min(int C[x][x], int D[], int i, int j);//obtener el costo minimo hacia un Vertice v
void printS(set S);
void printD(int D[], int inicio);
void printP(int P[], int inicio);
void Dijkstra(int C[x][x], int inicio, set V,int *ct);//algoritmo de Dijkstra
 
int main(){
	int cont=0;
	int h=0;
	set V;
	V.cardinalidad=0;
	dato d0=0;
	dato d1=1;
	dato d2=2;
	dato d3=3;
	dato d4=4;
	dato d5=5;
	dato d6=6;
	dato d7=7;
	dato d8=8;
	
	V=insert(V,d0);
	V=insert(V,d1);
	V=insert(V,d2);
	V=insert(V,d3);
	V=insert(V,d4);
	V=insert(V,d5);
	V=insert(V,d6);
	V=insert(V,d7);
	V=insert(V,d8);
	
	/*int C[n][n]={};*/
	
	/*int C[n][n]={{infinity,3,2,6},
                {infinity,infinity,infinity,9},
                {infinity,infinity,infinity,9},
                {infinity,infinity,infinity,infinity}};*/


	/*int C[n][n]={{infinity,50,infinity,infinity,infinity},
                {infinity,infinity,infinity,20,10},
                {10,infinity,infinity,30,100},
                {infinity,infinity,infinity,infinity,infinity},
                {infinity,infinity,infinity,60,infinity}};*/

	//n=6
	/*int C[n][n]={{infinity,2,4,infinity,infinity,1},
				{infinity,infinity,1,infinity,3,infinity },
				{infinity,infinity,infinity,4,infinity,infinity},
				{1,infinity,infinity,infinity,infinity,4},
				{infinity,infinity,2,1,infinity,3},
				{infinity,infinity,infinity,infinity,2,infinity}};*/

	//n=7
	/*int C[n][n]={{infinity,infinity,infinity,infinity,infinity,infinity,infinity},
                {25,infinity,10,14,infinity,infinity,infinity},
                {5,infinity,infinity,infinity,infinity,16,infinity},
                {infinity,6,18,infinity,infinity,infinity,infinity},
                {infinity,infinity,infinity,infinity,infinity,infinity,infinity},
                {infinity,infinity,infinity,32,42,infinity,14},
                {infinity,infinity,infinity,infinity,infinity,11,infinity}};*/
                 
	//n=8
	/*int C[n][n]={{infinity,6,10,14,infinity,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,15,4,infinity,infinity},
				{infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,8,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,infinity,infinity,infinity,9},
				{infinity,infinity,1,infinity,infinity,infinity,2,4},
				{infinity,infinity,5,infinity,infinity,infinity,infinity,7},
				{infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity}};*/
			
	//n=9
	int C[n][n]={{infinity,10,infinity,0,20,infinity,35,30,infinity},
	        	{infinity,infinity,5,infinity,15,infinity,infinity,25,infinity},
				{infinity,infinity,infinity,infinity,4,1,infinity,6,infinity},
				{infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,2,infinity,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
				{infinity,infinity,infinity,infinity,infinity,infinity,8,infinity,9},
				{infinity,infinity,3,infinity,infinity,infinity,infinity,infinity,infinity}};
				 
	Dijkstra(C, h, V, &cont);
	printf("\tconteo = %d",cont);

	return 0 ;
}

int in(set A, dato d){
	int i;
	for (i = 0; i < A.cardinalidad; i++){
		if (A.Elem[i] == d) 
			return 1;
	}		
	return 0;
}

set insert(set A, dato d){
	if(in(A,d)==0)
		A.Elem[A.cardinalidad++]=d;
	return A;
}

set complement(set A, set B){
  	int i;
  	set C;
  	C.cardinalidad=0;
  	for (i = 0; i < A.cardinalidad; i++){
    	if (in(B, A.Elem[i])==0)
      		C=insert(C, A.Elem[i]);
	}
    return C;
}

int W(int A[], set B){
	int i,k;
	int j=infinity;
	for(i=0; i<n; i++){
		if(in(B,i)==1){
			if(j>=A[i]){
				j=A[i];
				k=i;
			}
		}
	}	
	return k;
}

int min(int C[x][x], int D[], int i, int j){
	if(D[i]<(D[j]+C[j][i]))	
		return D[i];
	else
		return D[j]+C[j][i];	
}

void printS(set S){
	int i;
	printf("\tS : ");
	for(i=0; i<S.cardinalidad; i++)
		printf("|%d|", S.Elem[i]);
	printf("\n");
}
void printD(int D[], int inicio){
	int i;
	printf("\tD : ");
	for(i=0; i<n; i++){
		if(i==inicio)
			printf("|X|");
		else 
			printf("|%d|", D[i]);
	}
	printf("\n");
}
void printP(int P[], int inicio){
	int i;
	printf("\tP : ");
	for(i=0; i<n; i++){
		if(i==inicio)
			printf("|X|");
		else 
			printf("|%d|", P[i]);
	}
	printf("\n");
}
 
void Dijkstra(int C[x][x], int inicio, set V, int *ct){//algoritmo de Dijkstra
	int i, j, w;//se inicializan variables para ciclos for y costos minimos
	//se inicializan los conjuntos S y Aux
	set S;
	S.cardinalidad=0;
	set Aux;
	Aux.cardinalidad=0;
	//se inicializan los conjuntos P y D de tamano n
	int P[n];
	int D[n];
	dato init=inicio;
	dato w1;(*ct)+=11;
	//se inserta el nodo inicial al arreglo S
	S=insert(S,inicio);(*ct)+=n;
	for(i=0;i<V.cardinalidad;i++){//Dado el conjunto de vertices V sin incliuir ala inicial
		if(i!=inicio){
			//se agrega el vertice inicial a los arreglos D y P
			D[i]=C[inicio][i];
			P[i]=inicio;
			(*ct)+=3;
		}
		(*ct)++;
	}
	(*ct)++;
	//operacion de diferencia entre el conjunto V y el conjunto S 
	Aux=complement(V,S);(*ct)+=n;
	while (Aux.cardinalidad!=0){//ciclo while itera hasta que Aux es un conjunto vacio
		(*ct)++;
		w=W(D,Aux);//se encuentra ek vertice cocn menor costo 
		w1=w;(*ct)+=2;
		S=insert(S,w1);(*ct)++;//se inserta w1 en ele arreglo S
		Aux=complement(V,S);//operacion de diferencia entre el conjunto V y el conjunto S
		(*ct)+=n;
		for(j=0; j<Aux.cardinalidad;j++){//ciclo for iterando la cardinalidad de de V-S
			(*ct)++;
			D[Aux.Elem[j]]=min(C,D,Aux.Elem[j],w);//min(D[i],(D[j]+C[j][i]))
			(*ct)++;
			if(D[Aux.Elem[j]]==(D[w]+C[w][Aux.Elem[j]]))//min(D[i],(D[j]+C[j][i]))==(D[j]+C[j][i])
				(*ct)++;
				P[Aux.Elem[j]]=w;//P[v]=w
				(*ct)++;		
		}
	}
	(*ct)++;
	printf("\n");	
	printS(S);
	printD(D,inicio);
	printP(P,inicio);	
}

 
