#include <stdio.h>
#include <time.h>
#include "Fibonacci.h"  

int main() {
    int n = 400; 
    long long int result;
    clock_t start, end;
    double cpu_time_used;

    printf("Calcul du Fibonacci(%d) :\n\n", n);

    // ---- Fibonacci naive ----
    start = clock(); 
    result = fibonacci_naive(n);
    end = clock();   

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Resultat (naive) : %lld\n", result);
    printf("Temps d'execution (naive) : %.6f secondes\n\n", cpu_time_used);

    // ---- Fibonacci dynamique ----
    long long dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = -1; // initialisation du tableau DP
    }

    start = clock();
    result = fibonacci_dynamic(n, dp);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Resultat (dynamique) : %lld\n", result);
    printf("Temps d'execution (dynamique) : %.6f secondes\n", cpu_time_used);

    return 0;
}