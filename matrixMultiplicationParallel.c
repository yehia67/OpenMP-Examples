//gcc -fopenmp matrixMultiplicationParallel.c
//./a.out
#include <stdio.h>
#include <omp.h> 
int main()
{
    int a[2][2] = {1,1,1,1};
    int b[2][2] = {2,2,2,2};
    int c[2][2];
    int sum = 0;
   #pragma omp parallel
   {
   #pragma omp parallel for
   for(int i = 0;  i < 2; i++)
   {
       for(int j = 0; j < 2; j++)
       {
           for(int k = 0; k < 2; k++)
           {
               sum += a[i][k] * b[k][j];
           }

           c[i][j] = sum;
           sum = 0;
       }
       
   }
   }
   for(int i = 0; i < 2; i++)
           {
               for(int j = 0; j < 2; j++)
               {
                   printf("%d \n",c[i][j]);
               }
               
           }
           
  return 0;
}