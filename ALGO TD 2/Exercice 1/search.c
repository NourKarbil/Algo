#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{ for (int i =0 ; i<=n-1; i++) {
    if (arr[i]== target ){
        return i;
    }

}
    return -1;
}

int jump_search(int *arr, int n, int target)
{   int m = (int)sqrt(n);
    int prev = 0;

 
    while (arr[min_int(m, n) - 1] < target) {
        prev = m;
        m += (int)sqrt(n);
        if (prev >= n)
            return -1;
    }

    
    for (int i = prev; i < min_int(m, n); i++) {
        if (arr[i] == target)
            return i;
    }

    
    return -1;
}  

int binary_search(int *arr, int n, int target)
{   int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + high  / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }

    return -1;
}
