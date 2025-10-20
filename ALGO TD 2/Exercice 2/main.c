#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    int n = 10000; 
    int *arr = malloc(n * sizeof(int));
    int *copy = malloc(n * sizeof(int));

    if (!arr || !copy) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    srand(time(NULL)); // initialiser un générateur aléatoire

    // Remplir le tableau de valeurs aléatoires
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // valeurs entre 0 et 99999
    }

    printf("=== Comparaison des algorithmes de tri (%d éléments) ===\n\n", n);

   // Selection Sort 
    copy_array(arr, copy, n);
    clock_t start = clock();
    selection_sort(copy, n);
    clock_t end = clock();

    printf("Selection sort: %.4f sec — %s\n",
           (double)(end - start) / CLOCKS_PER_SEC,
           is_sorted_nondecreasing(copy, n) ? "OK" : "FAILED");

    
    // Insertion Sort
   
    copy_array(arr, copy, n);
    start = clock();
    insertion_sort(copy, n);
    end = clock();

    printf("Insertion sort: %.4f sec — %s\n",
           (double)(end - start) / CLOCKS_PER_SEC,
           is_sorted_nondecreasing(copy, n) ? "OK" : "FAILED");

   
    // Bubble Sort

    copy_array(arr, copy, n);
    start = clock();
    bubble_sort(copy, n);
    end = clock();

    printf("Bubble sort: %.4f sec — %s\n",
           (double)(end - start) / CLOCKS_PER_SEC,
           is_sorted_nondecreasing(copy, n) ? "OK" : "FAILED");

    // Merge Sort
    copy_array(arr, copy, n);
    start = clock();
    merge_sort(copy, n);
    end = clock();

    printf("Merge sort: %.4f sec — %s\n",
           (double)(end - start) / CLOCKS_PER_SEC,
           is_sorted_nondecreasing(copy, n) ? "OK" : "FAILED");

    
    // Quick Sort
    
    copy_array(arr, copy, n);
    start = clock();
    quick_sort(copy, n);
    end = clock();

    printf("Quick sort: %.4f sec — %s\n",
           (double)(end - start) / CLOCKS_PER_SEC,
           is_sorted_nondecreasing(copy, n) ? "OK" : "FAILED");

    // Nettoyage
    free(arr);
    free(copy);

    
    return 0;
}
