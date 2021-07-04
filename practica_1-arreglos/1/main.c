// By Erik Gimenez
// https://github.com/Erislash
// Creative Commons BY-NC 4.0 (Attribution-NonCommercial 4.0 International)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "helpers.h"

float mediana (float arr[], int len) {
    float output = 0.0;
    float* tmp = malloc(sizeof(float) * len);
    for (int i = 0; i < len; i++){
        tmp[i] = arr[i];
    }
    

    bubbleSort(tmp, len);

    if (len % 2 != 0) output = tmp[len/2];
    else output = ((tmp[(int)floor(len/2)] + tmp[(int)floor(len/2) - 1]) / 2);
    free(tmp);
    return output;
}


int main(void) {
    float one = mediana((float[]){-1.0, 2.2, 2.9, 3.1, 3.5}, 5);
    float two = mediana((float[]){-1.0, 2.2, 2.9, 3.1}, 4);
    printf("One: %.2f\nTwo: %.2f\n", one, two);

    return 0;
}
