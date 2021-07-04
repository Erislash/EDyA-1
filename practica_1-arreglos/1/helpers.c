#include "helpers.h"

// Recursos recomendados (en orden descencente)
// https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_algorithm.htm
// https://www.programiz.com/dsa/bubble-sort
// https://www.geeksforgeeks.org/bubble-sort/


void bubbleSort(float arr[], int len){
    boolean swap = false;
    int swapped = 0;
    do {
        swap = false;
        for (int i = 0; i < len - 1 - swapped; ++i) {
           if (arr[i] > arr[i + 1]) {
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp; 
                swap = true;
           }
       }
       ++swapped;
    } while (swap != false);
}