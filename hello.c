//gcc -fopenmp hello.c
//./a.out
#include <omp.h>
#include <stdio.h>
int main()
{
       omp_set_num_threads(4);
        #pragma omp parallel
        {
       
        printf("Hello World from thread =  %d \n",omp_get_thread_num());
        
        #pragma omp single
        printf("We have %d threads here.\n",omp_get_num_threads());
        
        }
return 0;
}