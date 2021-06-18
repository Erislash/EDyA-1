#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _str {
    char* str;
    unsigned int unused;
} Str;

Str* InitStr(char* text){
    unsigned int space = 1 + (int)floor((sizeof(char) * strlen(text) + 1) * 1.5);
    Str *str = malloc(sizeof(Str));
    if(str == NULL) return NULL;
    str->str = malloc(space);
    if(str->str == NULL) return NULL;
    strcpy(str->str, text);

    str->unused = space - strlen(text) - 1;

    // printf("STRING: %s\n", str->str);
    // printf("USED: %d\n", ((int)strlen(str->str) + 1));
    // printf("UNUSED: %d\n", str->unused);
    // printf("ASSIGNED: %d\n", space);
    
    return str;
}

Str* Change(Str* original, char* new){
    
}


int main() {
    Str *txt = NULL;
    txt = InitStr("solosy");
    // char c;
    // char* text = malloc(sizeof(char));
    // text[0] = '\0';

    // while((c = fgetc(stdin)) != EOF && c != '\n'){
    //     void *tmp = realloc(text, strlen(text) + sizeof(char) + 1);
    //     text = (char*)tmp;
    //     text[strlen(text) + 1] = '\0';
    //     text[strlen(text)] = c;
    // }

    // // printf("STRING: %s\n", text);
    // // printf("STRING length: %d\n", (int)strlen(text));

    free(txt->str);
    free(txt);
    return 0;
}