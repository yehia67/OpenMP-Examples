//gcc -fopenmp vectorDotProduct.c
//./a.out
#include <omp.h>
#include <stdio.h>
#define N 8
#define noThreads 4
int main()
{
        long  x[8] = {0,1,2,3,4,5,6,7};
        long  y[8] = {0,2,4,6,8,10,12,14};
        long ans = 0;
        omp_set_num_threads(noThreads); 
        #pragma omp parallel
        {
           int id = omp_get_thread_num();
           
         
           #pragma omp for  
           for(int i = 0; i < N; i++)
           {
             printf("Partial result by thread[%d]= %li \n",id,x[i]*y[i]);
              ans += x[i]*y[i];
           }
        #pragma omp single   
        printf("Final result= %li \n",ans);            
        }
return 0;
}