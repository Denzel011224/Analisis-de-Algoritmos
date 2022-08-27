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
    problema de la practica #2, el cual 
    muestra los primeros n numeros perfectos,
    en este caso n tiene la restriccion de 
    no ser mayor a 8.
*/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>// setprecision()
#include <time.h>// Semilla srand()
#include <math.h>// pow()


#define ll long long// definimos long long como ll por comodidad
using namespace std;

ll modulo(ll base, ll e, ll mod,int *ct)
{
    ll a = 1;(*ct)++;
    ll b = base;(*ct)++;
    (*ct)++;//Mientras e>0
    while (e > 0)
    {
        (*ct)++;//if
        if (e % 2 == 1)
        {
            a = (a * b) % mod;
            (*ct)++;
        }
        (*ct)++;
        b = (b * b) % mod;
        (*ct)++;
        e = e / 2;
    }
    (*ct)++;//No se cumple el while
    return a % mod;
}
bool Fermat(ll m, int iterations,int *ct)
{
    (*ct)++;//if m==1
    if (m == 1)
    {
        (*ct)++;
        return false;
    }
    for (int j = 0; j < iterations; j++)
    {
        (*ct)++;
        ll x = rand() % (m - 1) + 1;
        (*ct)++;
        if (modulo(x, m - 1, m,ct) != 1)
        {
            (*ct)++;
            return false;
        }
    }
    (*ct)++;//No se cumple condicion For
    return true;
}

void mostrarPerfectos(int n,int *ct)
{
    FILE *pf = fopen("prac2_2.csv","at");//Creamos csv
    int k = 20, i = 1,temp=n;(*ct)++;(*ct)++;(*ct)++;
    cout << fixed << setprecision(0);(*ct)++;//Mayor precision al imprimir
    (*ct)++;//mientras n diferente de 0
    while (n)
    {
        (*ct)++;
        if (Fermat(i, k,ct))
        {
            (*ct)++;
            if (Fermat(pow(2, i) - 1, k,ct))
            {
                (*ct)++;
                cout << pow(2, i - 1) * (pow(2, i) - 1);
                (*ct)++;
                cout << " es Perfecto\n";
                (*ct)++;
                fprintf(pf,"%d,%d\n",abs(n-temp-1), *ct);
                n--;
            }
        }
        i++;(*ct)++;
    }
    (*ct)++;//No se cumple el while
    fclose(pf);
}

int main()
{
  
    srand(time(0)); // semilla del random
    int *ct,c;      // contador
    c=0;
    ct=&c;
    int n = 8;
    mostrarPerfectos(n,ct);//funcion del problema
    return 0;
}