#include <stdio.h>
#include <stdlib.h>
#include "Premier.h"
int premier_naive(int n){
    int c=0;
    int m=0;
    for (int i=2;i<n;i++) {
        for (int j=1;j<=i;j++) {
            if (i%j==0){
                m=m+1;
            }

        }
        if (m==2){
            c=c+1;
        }
        m=0;


    }
   return c;
}
int premier_optimized(int n) {
    int count = 0;
    int* is_prime = malloc((n+1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        is_prime[i] = 1; 
    }
    is_prime[0] = is_prime[1] = 0;

    for (int p = 2; p*p <= n; p++) {
        if (is_prime[p]==1) { 
            for (int multiple = p*p; multiple <= n; multiple += p) {
                is_prime[multiple] = 0; 
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) count++;
    }
    free(is_prime);
    return count;

    free(is_prime);
    return count;
