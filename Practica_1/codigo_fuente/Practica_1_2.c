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
    problema de la practica #2, el cual 
    encuentra el mcd de dos numeros enteros, 
	se da de entrada la sucecion de Fibonacci
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 40
unsigned int sucesion_fibonacci(unsigned int n);//Declaracion de la funcion para crear la sucecion de fibinacci
unsigned int sucesion_fibonacci_R(unsigned int n);//Declaracion de la funcion recursiva para obtener la sucecion de fibonacci de un numero n
unsigned long int primo_n(unsigned long int n);
int perfecto(long double n);

int main() {
	unsigned int i;
	unsigned long int r, m, n;
	m = primo_n(4);
	printf("%u\n", m );
	return 0;
}

unsigned int sucesion_fibonacci(unsigned int n){
	unsigned int  i, x1=1, x2=0;//declaracion de variables 
	for(i=1; i<=n; i++){
		x2=x1+x2;// se suma dos numeros consecutivos para la sucesion
		x1=x2-x1;//se asigna un valor posterior a X2
	}
	return x2;
}

unsigned int sucesion_fibonacci_R(unsigned int n){
	if(n < 2)
		return n;
	else
		return sucesion_fibonacci_R(n-1)+sucesion_fibonacci_R(n-2);
}

unsigned long int primo_n(unsigned long int n){
	unsigned long int r;
	r = (pow(2,n)) - 1;
	return r;	
}

int perfecto(long double n){
	long double r=0, i;
	for(i=1; i<n; i++){
		if((int)n%(int)i==0)
			r = r + i;	
	}
	if(n==r)
		return 1;
	else
		return -1;
}

