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
#define x 6
#define n 6
#define infinity 9999
 
typedef int dato;

typedef struct set{
  dato Elem[6];
  int cardinalidad;
}set;

int in(set A, dato d);
set insert(set A, dato d);
set complement(set A, set B);
int W(int A[], set B);
int min(int C[x][x], int D[], int i, int j);
void printS(set S);
void printD(int D[]);
void printP(int P[]);
void Dijkstra(int C[x][x], int inicio, set V);
 
int main(){
	int h=0;
	set V;
	V.cardinalidad=0;
	dato d0=0;
	dato d1=1;
	dato d2=2;
	dato d3=3;
	dato d4=4;
	dato d5=5;
	
	V=insert(V,d0);
	V=insert(V,d1);
	V=insert(V,d2);
	V=insert(V,d3);
	V=insert(V,d4);
	V=insert(V,d5);
	
	int C[n][n]={{infinity,2,4,infinity,infinity,1},
				 {infinity,infinity,1,infinity,3,infinity },
				 {infinity,infinity,infinity,4,infinity,infinity},
				 {1,infinity,infinity,infinity,infinity,4},
				 {infinity,infinity,2,1,infinity,3},
				 {infinity,infinity,infinity,infinity,2,infinity}};
				 
	Dijkstra(C, h, V);

	return 0 ;
}

int in(set A, dato d){
	int i;
	for (i = 0; i < A.cardinalidad; i++)
		if (A.Elem[i] == d) 
			return 1;
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
	int j=A[0];
	for(i=0; i<6; i++){
		if(in(B,i)==1){
			if(j>A[i]){
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
	printf("S : ");
	for(i=0; i<S.cardinalidad; i++)
		printf("|%d|", S.Elem[i]);
	printf("\n");
}
void printD(int D[]){
	int i;
	printf("D : ");
	for(i=0; i<n; i++){
		if(i==0)
			printf("|X|");
		else 
			printf("|%d|", D[i]);
	}
	printf("\n");
}
void printP(int P[]){
	int i;
	printf("P : ");
	for(i=0; i<n; i++){
		if(i==0)
			printf("|X|");
		else 
			printf("|%d|", P[i]);
	}
	printf("\n");
}
 
void Dijkstra(int C[x][x], int inicio, set V){
	int i, j, w;
	set S;
	S.cardinalidad=0;
	set Aux;
	Aux.cardinalidad=0;
	int P[n];
	int D[n];
	dato init=inicio;
	dato w1;
	S=insert(S,inicio);
	for(i=1;i<V.cardinalidad;i++){
		D[i]=C[inicio][i];
		P[i]=inicio;		
	}
	Aux=complement(V,S);
	while (Aux.cardinalidad!=0){
		w=W(D,Aux);
		w1=w;
		S=insert(S,w1);
		Aux=complement(V,S);
		for(j=0; j<Aux.cardinalidad;j++){
			D[Aux.Elem[j]]=min(C,D,Aux.Elem[j],w);
			if(D[Aux.Elem[j]]==(D[w]+C[w][Aux.Elem[j]]))
				P[Aux.Elem[j]]=w;		
		}	
	}
		
	printS(S);
	printD(D);
	printP(P);	
}

 
