/*
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 14/03/2022

    El siguiente codigo resuelve el primer
    problema de la practica #2, muestra la sucesion de Fibonacci
    apartir de un enfoque iterativo y recursivo
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 30
unsigned int sucesion_fibonacci(unsigned int n, int *cont);//Declaracion de la funcion para crear la sucecion de fibinacci
unsigned int sucesion_fibonacci_R(unsigned int n, int *cont);//Declaracion de la funcion recursiva para obtener la sucecion de fibonacci de un numero n

int main() {
	unsigned int i, r, m, n;
	int cont;
	FILE *pf = fopen("prac2_1.csv","at");// abrir un archivo .csv
	FILE *pf1 = fopen("prac2_2.csv","at");// abrir un archivo .csv  
	for(i=0; i<TAM; i++){//Tamano de la muestra
		cont = 0;
		m = sucesion_fibonacci(i, &cont);
		printf("%u\t%d\n",i, cont );// imprimir en consola
		fprintf(pf,"%u, %d\n",i, cont);//imprimir en el archivo .csv
	}	
	fclose(pf);// cerrar archico .csv
	for(i=0; i<TAM; i++){//Tamano de la muestra
		cont = 0;
		n = sucesion_fibonacci_R(i, &cont);
		printf("%u\t%d\n",i, cont );// imprimir en consola
		fprintf(pf1,"%u, %d\n",i, cont);//imprimir en el archivo .csv
	}	
	fclose(pf1);// cerrar archico .csv
	return 0;
}

unsigned int sucesion_fibonacci(unsigned int n, int *cont){
	(*cont)++;
	(*cont)++;
	(*cont)++;
	(*cont)++;
	(*cont)++;
	unsigned int  i;//Varible para recorrer el for
	unsigned int x1 = 1;//X(1) de la sucesion de fibonacci
	unsigned int x2 = 0;//X(0) de la sucesion de fibonacci 
	(*cont)++;
	for(i=1; i<=n; i++){
		(*cont)++;
		(*cont)++;
		(*cont)++;
		x2=x1+x2;//se asigna la suma de las varibleas al primer digito de la sucesion
		(*cont)++;
		(*cont)++;// se suma dos numeros consecutivos para la sucesion
		x1=x2-x1;//se asigna a x1 el valor de la resta de X2 con x1
		(*cont)++;
	}
	(*cont)++;
	(*cont)++;
	return x2;//Se devuelve x2
}

unsigned int sucesion_fibonacci_R(unsigned int n, int *cont){
	if(n < 2){//condicionpara numero menores a 2
		(*cont)++;
		(*cont)++;
		return n;//se debuelven los dos primeros nuemros de la sucesion de Fibonacci
	}	
	else{
		(*cont)++;
		(*cont)++;
		(*cont)++;
		(*cont)++;
		return (sucesion_fibonacci_R(n-1, cont) + sucesion_fibonacci_R(n-2, cont));//Imprementacion de un arbol para encontatar la la solucion apartir de recursividad
	}		
}

