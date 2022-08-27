/*
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 30/03/2022

    El siguiente codigo implementa las 
    funciones requeridas a analizar 
    de la practica #3, las cuales, 
    regresan el cociente de una division.

*/

#include <stdio.h>
#include<stdlib.h>
#include <time.h>// Semilla srand()

int div1(int n, int div,int*ct){
    (*ct)++;
    int q=0;

    while (n>=div){
        (*ct)++;
        (*ct)++;
        n=n-div;
        (*ct)++;
        q++;
    }
    (*ct)++;
    (*ct)++;
    int res=n;
    (*ct)++;
    return q;
}
int div2(int n, int div,int*ct){
    (*ct)++;
    int dd=div;
    (*ct)++;
    int q=0;
    (*ct)++;
    int r=n;

    while(dd<=n){
        (*ct)++;
        dd=2*dd;
    }
    (*ct)++;
    while(dd>div)
    {
        (*ct)++;
        (*ct)++;
        dd=dd/2;
        (*ct)++;
        q=2*q;
        (*ct)++;
        if(dd<=r)
        {
            (*ct)++;
            r=r-dd;
            (*ct)++;
            q=q+1;
        }
    }
    (*ct)++;
    return q;
}
int div3(int n, int div,int*ct){
    (*ct)++;
    if (div>n){
        (*ct)++;
        return 0;
    }
        
    else{
        (*ct)++;
        return 1+div3(n-div,div,ct);
    }
        
}

int main(){
    srand(time(0)); // semilla del random
    FILE *pf = fopen("prac3_3.csv","at");//Creamos csv
    int i;
    for(i=0;i<100;i++)
    {
    int *ct,c;      // contador
    c=0;
    ct=&c;
    int n=rand()%100+1;
    int div=n/(rand()%n+1);
    int d1=div3(n,div,ct);
    printf("%d\n",d1);
    
    fprintf(pf,"%d,%d\n",d1, *ct);
    *ct=0;
    }
    

    fclose(pf);
    return 0;
}