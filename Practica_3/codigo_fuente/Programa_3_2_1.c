/*
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 14/03/2022

    El siguiente codigo resuelve el segundo
    problema de la practica #3, don de se hace
    la busqueda de un numero K en un arreglo A[]
    de tamano n, que es dividido en tres bloques,
    version iterativa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void Generate_array(int A[], int TAM);//Declaracion de una funcion para generara un arreglo de tamano n 
void print_array(int A[], int TAM);//Declaracion de la funcion para mostrar el arrglo en pantalla
int search_num(int A[], int n, int incio, int final, int *cont);//Declaracion de la funcion para hacer la busqueda de un elemento en un arreglo dada su division en trees bloques

int main (){
	int i, num;
	int cont;
	FILE *pf = fopen("prac3_2_1.csv","at");// abrir un archivo .csv
	for(i=10; i<=MAX; i=i+100){//Los casos prueba tiene un tamano de problema dentro de un rango de 10 a 10000
		int A[i];
		int TAM = sizeof(A)/sizeof(A[0]);//Se obtiene el tamano del arreglo
		srand(time(NULL));
		num = rand()%(TAM+TAM);//generacion aleatoria de los casos prueba
		printf("%d\n",num);
		Generate_array(A,TAM);
		print_array(A,TAM);
		printf("%d\t%d\n\n", search_num(A,num,0,TAM-1, &cont), num);
		fprintf(pf,"%d,%d\n",TAM, cont);//imprimir en el archivo .csv
		cont=0;
	}
	fclose(pf);// cerrar archico .csv
	return 0;
}

//Funcion para generara un arreglo de tamano n 
void Generate_array(int A[], int TAM){
	int i;
	A[0]=0;
	for(i=1; i<TAM; i++){//Se llena el arreglo dado la sucesion del for
		A[i] = i;
	}
}

//Funcion para mostrar el arrglo en pantalla
void print_array(int A[], int TAM){
	int i;
	for(i=0;i<TAM;i++)//Se recorre el arreglo de elemento a elemnto para mostrarlo en pantalla
		printf("[%d] ", A[i]);
	printf("\n");
}

//Funcion para hacer la busqueda de un elemento en un arreglo dada su division en trees bloques
int search_num(int A[], int n, int inicio, int final, int *cont){
	int i, j;
	(*cont)++;
	(*cont)++;
	while(inicio<=final){//Si el valor del elemento inicial es mayor al elemento final el programa termina 
		(*cont)++;
		(*cont)+=10;
		i = inicio + ((final-inicio)/3);//Se obtiene el elemento ubicado justo al final del primer bloque del arreglo
		j = inicio + (2*((final-inicio)/3))+1;//Se obtiene el elemento ubicado justo al final del segundo bloque del arreglo
		if(n==A[i]){//Se regresa el valor en la posicion i
			(*cont)++;
			(*cont)++;
			return i;
		}
		if(n==A[j]){//Se regresa el valor en la posicion j
			(*cont)++;
			(*cont)++;
			return j;
		}	
		if(n<A[i]){//Se ve si el elemento que se busca es menor a el valor del elemento de la posicion i
			(*cont)++;
			(*cont)++;
			final = i-1;
		}	
		if(n>A[j]){//Se ve si el elemento que se busca es mayor a el valor del elemento de la posicion j
			(*cont)++;
			(*cont)++;
			inicio = j+1;
		}
		if((n>A[i]) && (n<A[j])){//Se ve si el elemento que se busca es mayor a el valor del elemento de la posicion i y menor a el valor del elemento de la posicion j
			(*cont)++;
			(*cont)++;
			(*cont)++;
			final = j-1;
			inicio = i+1;
		}
	}
	(*cont)++;
	(*cont)++;
	return -1;
}
