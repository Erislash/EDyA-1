// By Erik Gimenez
// https://github.com/Erislash
// Creative Commons BY-NC 4.0 (Attribution-NonCommercial 4.0 International)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* GetNewLine(void);

int main(void) {
    char* linea = GetNewLine();

    printf("Linea: %s\n", linea);
    printf("Cantidad de caracteres: %d\n", (int)strlen(linea));

    free(linea);
    return 0;
}

char* GetNewLine(void) {
    char c;
    char* output = malloc(sizeof(char));
    *output = '\0';

    printf("Ingrese una linea de texto: ");
    while((c = fgetc(stdin)) != EOF && c != '\n'){
        void* tmp = realloc(output, strlen(output) + sizeof(char) + 1);
        assert(tmp != NULL);
        output = (char*)tmp;
        output[strlen(output) + 1] = '\0';
        output[strlen(output)] = c;
    }
    return output;
}
