//gcc -fopenmp pi.c
//./a.out
#include <omp.h>
#include <stdio.h>
long num_steps = 1000000;
//Program To Calculate Pi value
int main()
{
        int i;
        double x,sum=0.0;
        double pi,step = (double) 1/num_steps;
        for( i = 0; i < num_steps; i++)
        {
                x = (double) (i+ 0.5)* step;
                sum = sum + 4.0/(1.0+x*x);
        }
        pi = step * sum;
        printf("%f\n",pi);
return 0;
}