//gcc -fopenmp lab5_main1_Nested.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>

 
int main()
{
  int arr[10] = {1, 3, 5, 6, 7, 9, 3, 4, 2, 8};
  int size = 10;
    
    omp_set_num_threads(4);
    int redundant;

        #pragma omp parallel 
         {
            #pragma omp for collapse(2)
		        for (int i = 0; i < size; i++)
		         {
			        for (int j = 0; j < size; j++)
			        {
				      if (arr[i] == arr[j])
				        {
            		if(i == j ){
                  continue;
                }
                else
                {
                redundant = arr[i];
                }
                        
                }
              }  
		        }
	       }

    printf("the redundant no =  %d \n",redundant);

    return 0;
}


