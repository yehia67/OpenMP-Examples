//gcc -fopenmp prefixSumParallelWithoutForLoop.c
//./a.out
#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4
#define n 4

int main()
{
  int arr[n] ={2,3,7,5};// 2 5 12 17
  int prefix[n] = {0};
  int hold[n] = {0};
 
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel 
  {
      int id = omp_get_thread_num();
      int nthrds = omp_get_num_threads();
      int i;
    	hold[0] = arr[0];
      for (int i = id; i < n-1; i += nthrds) 
		      {
          hold[i + 1] = arr[i] + arr[i + 1];
          }
       #pragma omp barrier
      
      prefix[0] = hold[0];
      for (int i = id; i < n-2; i += nthrds)
        {
            prefix[i + 2] = hold[i] + hold[i + 2];
            if (i < 2)
              {
              prefix[i] = hold[i];
              }
        }           
  }
  
  for(int i = 0; i < n; i++)
  {
    printf("%d  ",prefix[i]);
  }
  printf("\n");
  return 0;
}