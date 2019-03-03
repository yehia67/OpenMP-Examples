//gcc -fopenmp hello.c
//./a.out
#include <omp.h>
#include <stdio.h>
int main()
{
        int x = omp_get_max_threads();
        printf("omp run with max number of threads = %d \n",x);
        #pragma omp parallel
        {
       
        printf(" yarab = thread num %d \n",omp_get_thread_num());
        }
return 0;
}