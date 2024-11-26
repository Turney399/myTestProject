/**********************************************
*  Filename: dft.c
*  Description: Try simple use of Complex Numbers
*  gcc -o exename Complex_numbers.c -lm
*  Author: Bob Turney
*  Date: 4/9/2024
***********************************************/ 
#include <stdio.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES
#define DFT_SIZE 65536

int main (void)
{
    float mypi = M_PI;
    float complex *xn = malloc(DFT_SIZE*sizeof(float)*2);
    float complex *xk = malloc(DFT_SIZE*sizeof(float)*2);

   // Set xn to constant
    for (int i=0; i<DFT_SIZE; i++)
    {
        xn[i] = 32.0 + I*0.0;
    }
    printf("\n");
    // Discrete Fourier Transform calculation
    for (int k=0; k<DFT_SIZE; k++)
        {
            xk[k]=0.0;
        for (int n=0;n<DFT_SIZE; n++)
            {
            xk[k] = xk[k] + xn[n]*cexp(-I*2*M_PI*(k)*n/DFT_SIZE); 
            }
        }
    // Print out the Resulting Xk
    for (int i=0; i<10; i++)
    {
        printf("The value of xk[%d] is %f + j%f\n", i, creal(xk[i]), cimag(xk[i]));
    }
    
    free(xn);
    free(xk);
    return 0;
}
