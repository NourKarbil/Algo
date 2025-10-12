#include <stdio.h>
#include "Fibonacci.h"
long long int fibonacci_naive( int n ) {
    if (n<= 1){
        return n;
    } 
    return fibonacci_naive(n-1)+fibonacci_naive(n-2);
}
long long int fibonacci_dynamic(int n ,long long int DP[]){
    if (n<= 1){
        return n ;
    }
    if (DP[n]!=-1){
        return DP[n];
    }
    DP[n]= fibonacci_dynamic(n-1, DP)+ fibonacci_dynamic(n-2,DP);
}