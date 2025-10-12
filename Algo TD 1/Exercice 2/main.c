#include <stdio.h>
#include <time.h>
#include "Premier.h"  

int main() {
    int n = 10000;  
    int result;

    clock_t start, end;
    double cpu_time_used;

    
    // Premier Naive
    start = clock();
    result = premier_naive(n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Resultat (naive) : %d\n", result);
    printf("Temps CPU (naive) : %.6f secondes\n", cpu_time_used);

  
    // Premier Optimisé

    start = clock();
    result = premier_optimized(n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Resultat (optimise) : %d\n", result);
    printf("Temps CPU (optimise) : %.6f secondes\n", cpu_time_used);
    return 0;
}

