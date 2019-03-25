//gcc -fopenmp lab5a.c
//./a.out 1 3 5 
#include <omp.h>
#include <stdio.h>
#include <math.h>
void swap(int* x, int* y){
    int hold;
    hold = *x;
    *x = *y;
    *y = hold;
}
int main()
{
       int i, a[10] = {1,3,5,6,7,9,3,4,2,8};
       omp_set_num_threads(4);
       omp_set_nested(1);
        #pragma omp parallel
        {
            #pragma omp parallel for private(i)
            for( i = 0; i < 10; i++)
            {
               for(int j = i+1; j < 10; j++)
               {
                   if (a[i] == a[j]) {
                    printf("%d is redutant \n",a[i]);

                   }
                       
               }
                   
            }
        }
           

        
      
        
return 0;
}