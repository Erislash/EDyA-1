// By Erik Gimenez
// https://github.com/Erislash
// Creative Commons BY-NC 4.0 (Attribution-NonCommercial 4.0 International)
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "helpers.h"

enum _bool {
   false,
   true
};
typedef enum _bool Bool;

typedef struct _uni_matrix{
    int rows;
    int columns;
    float* dir;
} UniMatrix;

int main (void) {
    


    return 0;
}
