//gcc -fopenmp lab4_main4.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{

    long w;
    long A[5] ={0,2,4,6,8};
    long sum = 0, loc_sum = 0;
 
 
    omp_set_num_threads(4);
 
    #pragma omp parallel firstprivate(w, loc_sum)  
    {
        #pragma omp for schedule(static, 1)
        for (int i = 0; i < 5; i++)
        {
            w = i*i; 
            loc_sum = loc_sum + w*A[i];
            printf("Thread %d: w[%d] = %li & partial sum = %li \n",omp_get_thread_num(),i,w,loc_sum);
 
        }
 
        #pragma omp critical 
        sum = sum + loc_sum;
 
    }
    printf("The global sum is throughout the team = %li \n", sum);
    return 0;
}