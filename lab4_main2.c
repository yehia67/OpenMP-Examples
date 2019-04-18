//gcc -fopenmp lab4_main2.c
//./a.out 
#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{

    int id, nthreads;
    // set number of threads to 5
    omp_set_num_threads(5);
    // start the fork
    #pragma omp parallel private(id)
    {
        // parallel region started
      
        //Obtain thread number
        id = omp_get_thread_num();
        printf("Hello World from thread %d\n", id);
 
        #pragma omp single 
        {
            //Obtain number of threads
            nthreads = omp_get_num_threads();
            printf("There are %d Threads in the team!! \n", nthreads);
        }
 
    }// parallel region ended.
 
	return 0;
}