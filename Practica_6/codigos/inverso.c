#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    //---------ALGORITMO DE EUCLIDES-----------
    int num = 143, ps = 92, i = 0, j = 0;
    int r[100], q[10];
    r[0] = num;
    r[1] = ps;
    while (i == 0)
    {
        int residuo = r[j] % r[j + 1];
        //SI ES EL PRIMERO
        if(j == 0)
        {
            if (residuo != 0)
            {
                q[j + 1] = r[j] / r[j + 1];
                r[j + 2] = residuo;
                r[j] = (q[j+1] * r[j+1]) + r[j+2];
                j++;
            }else{
                printf("El numero %d NO tiene inverso multiplicativo modulo %d\n", num, ps);
                i++;
                return 0;
            }
        }else{//SI NO ES EL PRIMERO
            if (residuo > 0)
            {
                q[j + 1] = r[j] / r[j + 1];
                r[j + 2] = residuo;
                r[j] = (q[j+1] * r[j+1]) + r[j+2];
                j++;
            }else{
                if(r[j+1] == 1){
                    printf("El numero %d SI tiene inverso multiplicativo modulo %d\n", num, ps);
                }else{
                    printf("El numero %d NO tiene inverso multiplicativo modulo %d\n", num, ps);
                }
                i++;
            }
        }
    }


    //----------------------ALGORITMO INVERSO MULTIPLICATIVO---------------------
    int t[100];

    t[0] = 0;
    t[1] = 1;
    i=0;

    for(i=2; i<j+2; i++){
        t[i] = t[i-2] - (q[i-1] * t[i-1]);
        if(t[i] < 0){
            t[i] = (t[i] % num) + num;
        }else{
            t[i] = t[i] % num;
        }
    }

    printf("El inverso multiplicativo de %d es %d\n\n", ps, t[j+1]);

}