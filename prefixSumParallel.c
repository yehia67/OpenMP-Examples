//gcc -fopenmp prefixSumParallel.c
//./a.out
#include <stdio.h>
#include <omp.h> 
int main()
{
  int arr[4] ={2,3,7,5};
  int prefix[4];
  prefix[0] = arr[0];
  #pragma omp parallel
  {
  #pragma omp parallel for
  for(int i = 1; i < 4; i++)
  {
     prefix[i] = arr[i] + prefix[i-1];
  }
  }
  
  for(size_t i = 0; i < 4; i++)
  {
   printf("%d \n",prefix[i]);  
  }
  
  
  return 0;
}