#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct _splitted {
    char** arr;             
    unsigned int tokens;
} Split;


Split* split(char* str, char del);
Split* DestroySplit(Split* splitted);


int main(void) {
    Split* splitted = split("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam ut rhoncus nisl. Proin sed diam porta, commodo libero non, gravida nisi. Cras fringilla ultrices nibh. Nulla mollis arcu nulla, quis vehicula sapien ultrices ornare. Fusce in massa in leo pulvinar auctor eu in lacus. Quisque convallis augue id orci vestibulum, in luctus nulla faucibus. Pellentesque ac elementum ante, id sodales ipsum.", ' ');

    for (int i = 0; i < splitted->tokens; i++)
    {
        printf("%s\n", splitted->arr[i]);
    }
    splitted = DestroySplit(splitted);


    printf("\nLlegué al final\n");
    return 0;
}


Split* split(char* str, char del) {
    Split* splitted = malloc(sizeof(Split)); 
    assert(splitted != NULL);

    int tokens = 1;

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == del) ++tokens;
    }
    splitted->tokens = tokens;
    splitted->arr = malloc(sizeof(char*) * tokens);
    assert(splitted->arr != NULL);

    int start = 0;
    int stop = 0;

    int currentToken = 0;
    while (currentToken < tokens) {
        while (str[stop] != del && str[stop] != '\0') ++stop;
        ++stop;
        int size = stop - start;
        splitted->arr[currentToken] = malloc(sizeof(char) * size);
        assert(splitted->arr[currentToken] != NULL);

        int i = 0;
        for ( ; i < size; i++){
            splitted->arr[currentToken][i] = str[start];
            ++start;
        }
        splitted->arr[currentToken][i - 1] = '\0'; 
        start = stop;
        ++currentToken;
    }
    return splitted;
}


Split* DestroySplit(Split* splitted) {
    for (int i = 0; i < splitted->tokens; i++) {
        free(splitted->arr[i]);
    }
    free(splitted->arr);
    free(splitted);
    return NULL;
}
