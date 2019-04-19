//gcc -fopenmp lab4_main1.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{

	int i,id;
	float c[8], d[8];
    float a[8] = {0,1,2,3,4,5,6,7};
    float b[8]= {0,3,6,9,12,15,18,21};
	#pragma omp parallel shared(a,b,c,d) private(i)
	{

		#pragma omp sections nowait private(id)
		{
			#pragma omp section
			{
				id = omp_get_thread_num();
				printf("First Section executed by thread number %d \n",id);
				for (i = 0; i < 8; i++)
				{
					c[i] = a[i] + b[i];
					printf("Thread %d c[%d] = %f \n", id, i, c[i]);
				}
			}
			#pragma omp section
			{	
				id = omp_get_thread_num();
				printf("Second Section executed by thread number %d \n", id);
				for (i = 0; i < 8; i++)
				{
					d[i] = a[i] * b[i];
					printf("Thread %d d[%d] = %f \n", id, i,d[i]);
				}
			}

		}  

	}  
	return 0;
}