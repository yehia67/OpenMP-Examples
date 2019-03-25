//gcc -fopenmp lab5.c
//./a.out
#include <omp.h>
#include <stdio.h>
int main()
{
       omp_set_num_threads(4);
       omp_set_nested(1);
        #pragma omp parallel
        {
            #pragma omp parallel num_threads(3)
            {
               printf("We have %d threads here.\n",omp_get_thread_num());
      
        
            }
        }
return 0;
}