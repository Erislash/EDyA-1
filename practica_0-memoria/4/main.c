// By Erik Gimenez
// https://github.com/Erislash
// Creative Commons BY-NC 4.0 (Attribution-NonCommercial 4.0 International)
#include <stdio.h>
#include "helpers.h"
#include <assert.h>

void Swap(int* n, int* m);

int main(void) {
    int a = 1, b = 255;
    assert(a == 1 && b == 255);

    PrintInts((int[]){a, b}, 2);

    Swap(&a, &b);
    assert(a == 255 && b == 1);

    PrintInts((int[]){a, b}, 2);

    return 0;
}

void Swap(int* n, int* m) {
    *n += *m;
    *m = *n - *m;

    /*
    int tmp = *n;
    *n = *m;
    *m = tmp;
    */
}
