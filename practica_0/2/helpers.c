#include "helpers.h"


void PrintIntArr(int arr[], int size){
    printf("==================\n");
    printf("Array of size %d: \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] -> %d \n", i, arr[i]);
    }
    printf("==================\n");
}