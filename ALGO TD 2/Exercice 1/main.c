#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
   int arr[100] = {
        2, 5, 9, 15, 22, 30, 33, 37, 42, 48,
        51, 56, 60, 66, 72, 77, 81, 85, 90, 96,
        100, 105, 111, 118, 122, 128, 133, 139, 144, 150,
        155, 161, 167, 172, 178, 184, 190, 195, 201, 208,
        212, 218, 224, 230, 235, 241, 247, 252, 258, 264,
        270, 275, 281, 287, 293, 298, 304, 310, 316, 322,
        327, 333, 339, 345, 350, 356, 362, 368, 374, 380,
        385, 391, 397, 403, 409, 415, 421, 426, 432, 438,
        444, 450, 455, 461, 467, 473, 479, 485, 491, 497,
        503, 509, 515, 521, 527, 533, 539, 545, 551, 557
    };
    int n = 100;

    if (!is_sorted_nondecreasing(arr, n)) {
        return -1; 
    } else {
        int target = 233; 

        // Linear search
        clock_t start = clock();
        int index_linear = linear_search(arr, n, target);
        clock_t end = clock();
        double time_linear = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Jump search
        start = clock();
        int index_jump = jump_search(arr, n, target);
        end = clock();
        double time_jump = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Binary search
        start = clock();
        int index_binary = binary_search(arr, n, target);
        end = clock();
        double time_binary = ((double)(end - start)) / CLOCKS_PER_SEC;

        //les résultats
        printf("Résultats de recherche :\n");
        printf("Linear search : index = %d, temps = %f secondes\n", index_linear, time_linear);
        printf("Jump search : index = %d, temps = %f secondes\n", index_jump, time_jump);
        printf("Binary search : index = %d, temps = %f secondes\n", index_binary, time_binary);
    }
    return 0;
}
