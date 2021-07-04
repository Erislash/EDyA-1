#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef void (*FuncionVisitante)(int); // Así podemos darle un alias a un puntero a función. Por lo general esto va en archivos de cabecera

void Recorre(FuncionVisitante f, int* arr, int size);
void ImprimirEntero(int n);
void ImprimirEnteroSucesor(int n);

int main(void) {
    Recorre(ImprimirEntero, (int[]){1, 2, 3, 4, 100, 200, 500, 1000}, 8);
    printf("====\n");
    Recorre(ImprimirEnteroSucesor, (int[]){1, 2, 3, 4, 100, 200, 500, 1000}, 8);

    return 0;
}

void Recorre(FuncionVisitante f, int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        f(arr[i]);
    }
}

void ImprimirEntero(int n) {
    printf("%d\n", n);
}

void ImprimirEnteroSucesor(int n) {
    printf("%d\n", n + 1);
}
