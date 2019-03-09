//gcc -fopenmp hello.c
//./a.out
#include <omp.h>
#include <stdio.h>
#define N 8
int main()
{
        int a[8] = {1,1,1,1,1,1,1,1};
        int b[8] = {1,1,1,1,1,1,1,1};
        int c[8] = {0};
        // Divide for loop to 8/2 = 4 pices 
        int chunk = 2;
         
        omp_set_num_threads(4); 
        #pragma omp parallel
        {
           int id = omp_get_thread_num();
           
           // run time 3.main.c modifivation
           #pragma omp single
           printf("Dynamic Output\n");
           
           #pragma omp for schedule(dynamic,chunk) 
           for(int i = 0; i < N; i++)
           {
              c[i] = a[i] + b[i];
              printf("Thread %d : c[%d] = %d\n",id,i,c[i]);
           }
           
           // run time 4.main.c modifivation
           #pragma omp single
           printf("Guided Output\n");
           
           #pragma omp for schedule(guided,chunk) 
           for(int i = 0; i < N; i++)
           {
              c[i] = a[i] + b[i];
              printf("Thread %d : c[%d] = %d\n",id,i,c[i]);
           }
           
           // run time 5.main.c modifivation
           #pragma omp single
           printf("Run Time Output\n");
           
           #pragma omp for schedule(static,chunk) 
           for(int i = 0; i < N; i++)
           {
              c[i] = a[i] + b[i];
              printf("Thread %d : c[%d] = %d\n",id,i,c[i]);
           }
        
        }
return 0;
}