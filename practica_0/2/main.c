#include <stdio.h>
#include "helpers.h"


void setZero(int[]);
void setOne(int[]);
void setTwo(int[]);
void setThree(int[]);


int main(void) {
    int arr[] = {1, 2, 3, 4};
    PrintIntArr(arr, 4);

    setZero(arr);
    printf("\nAfter Zero function\n");
    PrintIntArr(arr, 4);

    setOne(arr);
    printf("\nAfter One function\n");
    PrintIntArr(arr, 4);

    setTwo(arr);
    printf("\nAfter Two function\n");
    PrintIntArr(arr, 4);

    setThree(arr);
    printf("\nAfter Three function\n");
    PrintIntArr(arr, 4);


    return 0;
}


void setZero(int arr[]){
    arr[0] = 0;
}

void setOne(int* arr){
    arr[1] = 1;
}

void setTwo(int* arr){
    *(arr + 2) = 2;
}

void setThree(int arr[]){
    *(arr + 3) = 3;
}