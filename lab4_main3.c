//gcc -fopenmp lab4_main3.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>
#define n
int main()
{

    long w;
    long a[N];
    long sum = 0, loc_sum = 0;
 
    for (int j = 0; j < N; j++)
    {
        a[j] = j * 2;
    }
 
    omp_set_num_threads(4);
 
    #pragma omp parallel firstprivate(w, loc_sum)  
    {
        #pragma omp for schedule(static, 1)
        for (int i = 0; i < N; i++)
        {
            w = i*i; 
            loc_sum = loc_sum + w*a[i];
            printf("Thread %d: w[%d] = %li & partial sum = %li \n"
                ,omp_get_thread_num()
                ,i
                ,w
                ,loc_sum);
 
        }
 
        #pragma omp critical 
        sum = sum + loc_sum;
 
    }
    printf("The global sum is throughout the team = %li \n", sum);
    return 0;
}