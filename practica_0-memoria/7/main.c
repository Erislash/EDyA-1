#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void Mensaje(char* msg);


int main(void) {
    void* ptr = malloc(100);
    assert(ptr != NULL);
    Mensaje("Memoria solicitada");
    free(ptr);
    Mensaje("Memoria liberada por 1° vez");
    free(ptr);
    Mensaje("¿Memoria liberada por 2° vez?");
    return 0;
}


void Mensaje(char* msg) {
    int msgLen = strlen(msg);
    for(int i = 0; i < msgLen / 4; ++i) {
        printf(" ");
    }
    printf("|@|=====\\#/=====|@|\n");
    printf("|//|  ");
    printf("%s", msg);
    printf("  |\\\\|\n");
    for(int i = 0; i < msgLen / 4; ++i) {
        printf(" ");
    }
    printf("|@|=====\\#/=====|@|\n\n");
}
