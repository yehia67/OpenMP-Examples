//gcc -fopenmp lab5_main1_Reduction.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>

 
int main()
{
    int arr[10] = {1, 3, 5, 6, 7, 9, 3, 4, 2, 8};
    int size = 10;
    
    omp_set_num_threads(4);
    int sum = redundant;

    #pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	redundant = sum - 45;
    printf("the redundant no =  %d \n",redundant);

    return 0;
}