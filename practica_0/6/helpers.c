#include <stdio.h>

void PrintInts(int* nums, int q){
    printf("=======================\n");
    for (int i = 0; i < q; i++) {
        printf("[%d] -> %d\n", i, nums[i]);
    }
    printf("=======================\n");
}
