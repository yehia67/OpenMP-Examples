#include <omp.h>
#include <stdio.h>
#include <math.h>
//change this to change the number of threads being used
#define NumOfThreads 4

//change this to change the size of the vector being computed
#define SizeOfVector 12
int main(){
	const unsigned short Loops = ceil(log2(SizeOfVector));
	//Only Change Array x's elements!
	short x[SizeOfVector] = {1,2,3,4,4,3,2,1,1,2,3,4};
	short Ans[SizeOfVector] = {0};
	
	omp_set_num_threads(NumOfThreads);
	
	//show current numbers
	printf("Start: %d\n", Loops);
	for(unsigned short Iterator = 0; Iterator < SizeOfVector; Iterator++)
		printf("x[%d] = %d\n", Iterator, x[Iterator]);
	
	#pragma omp parallel
	{
		unsigned short i, j, nthreads, ID, currentPow;
		nthreads = omp_get_num_threads();
		ID = omp_get_thread_num();

		//Algorithm's logic
		for(j=0; j<Loops; j++){
			currentPow = powl(2,j);
			for(i = ID; i < SizeOfVector; i+=NumOfThreads){
				if(i>currentPow-1){
					Ans[i] = x[i] + x[(int)(i-currentPow)];
				}
			}
			
			#pragma omp barrier
			//get ready for next iteration and show current numbers
			if(ID==0){
				printf("Loop%d:\nx[0] = %d\n", j+1, x[0]);
				for(i = 1; i<SizeOfVector; i++){
					x[i] = Ans[i];
					printf("x[%d] = %d\n", i,x[i]);
				}
			}
			#pragma omp barrier
		}
	}
	return 0;
}
