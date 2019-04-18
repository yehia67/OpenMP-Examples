//gcc -fopenmp lab4_main5.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>
#define N 5
 

int main()
{
int i;
int a[N] = {0,7,14,21,28};
int b[N];
int c[N];
 
//Initialize the or compute the elements of a 
    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0)
        {
            for (int i = 0; i < N; i++)
            {
                b[i] = a[i] * 2;
                printf("Thread %d : b[%d] = %d \n", omp_get_thread_num(), i, b[i]);
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                c[i] = (int)pow((float)a[i], 0.5f);
                printf("Thread %d : c[%d] = %d \n", omp_get_thread_num(), i, c[i]);
            }
        }
 
        #pragma omp barrier 
        printf("Last C is %d\n", c[N - 1]);
 
    }
 

    return 0;
}