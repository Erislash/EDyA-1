#include <stdio.h>
#include "helpers.h"

void SetInt(int* n);

int main(void) {
    int a = 1, b = 255, c = 1219, d = 0;

    PrintInts((int[]){a, b, c, d}, 4);

    SetInt(&a);
    SetInt(&b);
    SetInt(&c);
    SetInt(&d);
    
    PrintInts((int[]){a, b, c, d}, 4);

    return 0;
}

void SetInt(int* n) {
    *n = (*n != 0) ? 1 : 0;
}
