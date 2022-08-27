/*
	Instituto Politecnico Nacional
	Escuela Superior de Computo
	Analisis de Algoritmos | 3CV11
	Integrantes del equipo:
		Luis Francisco Renteria Cedillo
		Denzel Omar Vazquez Perez
	Profesor: Benjamin Luna Benoso
	Fecha: 01/03/2022

    El siguiente codigo resuelve el primer
    problema de la practica #1, el cual 
    realiza una busqueda en dos subarreglos
    y se detiene al encontrar la primer
    coincidencia en ambos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 500 // tamano de la muestra

void buscar(int a[], int n, int *ct);
void imprimeArreglo(int a[], int n);

int main(){
    
    FILE *pf = fopen("prac1_1.csv","at");
    srand(time(0)); // semilla del random
    int *ct,c;      // contador
    c=0;
    ct=&c;
    int z;
    for ( z=0;z<TAM;z++ )
    {
        int n,r,i;
        n=(rand() %10) *2;      // n debe ser par
        
        int a[n];
        
        for( i=0;i<n;i++ )
        {
            r=rand() % (3*n);   // random desde 0 a 3n
            a[i]=r;             // rellenamos arreglo
        }

        imprimeArreglo(a,n);
        buscar(a,n,ct);

        //imprimimos n y contador en archivo csv
        fprintf(pf,"%d,%d\n",n, *ct); 
        
        c=0;                    // reseteamos contador
    }
    fclose(pf);    
    return 0;
}

void buscar(int a[], int n, int *ct){
    int i; (*ct)++;
    int j; (*ct)++;

    (*ct)++; // asignacion de i=0
    for( i=0;i<= n/2 -1;i++)
    {
        (*ct)++; // verifica i
        (*ct)++; // asignacion de j=n/2
        for( j=n/2 ;j<= n-1 ;j++)
        {
            (*ct)++; // verifica j
            (*ct)++; // contador if
            if (a[i]==a[j]){
                /* si encuentra coincidencia
                entonces imprime los indices
                y el valor. */
                printf("Valor: %d en [%d] , [%d]\n",a[i],i,j);(*ct)++;
                return;
            }
            (*ct)++; // contador j++
        }
        (*ct)++; // j no es valido
        (*ct)++; // contador i++
    }
    (*ct)++; // i no es valido

    /* Dado que no hubo coincidencias,
    se imprime que no se encontraron
    y el proceso termina*/

    printf("No se encontraron \n");(*ct)++;
    return;
}

/* funcion que imprime todos los
valores del arreglo*/
void imprimeArreglo(int a[], int n){
    int i;
    printf("\n Arreglo A:\n[");
    for( i=0; i<n; i++){
        printf("%d ",a[i]);}
    printf("]\n");
    return;
}