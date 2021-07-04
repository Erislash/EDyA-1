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

int string_len(char* str) {
    unsigned int output = 0;
    for (size_t i = 0; str[i] != '\0'; ++output, ++i);
    return output;
}

void test_string_len(void) {
    char* str1 = "Hola"; // len: 4
    char* str2 = "Mundo"; // len: 5
    char* str3 = "A"; // len: 1
    char* str4 = ""; // len: 0
    char* str5 = "Lorem ipsum."; // len: 12

    assert(string_len(str1) == 4);
    assert(string_len(str2) == 5);
    assert(string_len(str3) == 1);
    assert(string_len(str4) == 0);
    // assert(string_len(str4) == 1);  // Esto va a fallar
    // assert(string_len(str4) == -1);  // Esto va a fallar
    assert(string_len(str5) == 12);
    // assert(string_len(str5) == 11);  // Esto va a fallar
    // assert(string_len(str5) == 13);  // Esto va a fallar
    printf("test_string_len Finished\n");
}



void string_reverse(char* str) {
    int len = string_len(str);
    int half = (int)floor(len / 2);
    for (int i = 0; i < half; ++i) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

void test_string_reverse(void) {
    char str1[] = "Hola";
    char str2[] = "Mundo";
    char str3[] = "k";
    char str4[] = "la";
    char str5[] = "";
    char str6[] = "sol";

    string_reverse(str1);
    assert(strcmp(str1, "aloH") == 0);

    string_reverse(str2);
    assert(strcmp(str2, "odnuM") == 0);
    
    string_reverse(str3);
    assert(strcmp(str3, "k") == 0);
    
    string_reverse(str4);
    assert(strcmp(str4, "al") == 0);
    
    string_reverse(str5);
    assert(strcmp(str5, "") == 0);
    
    string_reverse(str6);
    assert(strcmp(str6, "los") == 0);
    printf("test_string_reverse Finished\n");

}



int string_concat(char* str1, char* str2, int max) {
    int start = string_len(str1);
    int i = 0;
    for ( ; i < max && str2[i] != '\0'; ++i){
        str1[start + i] = str2[i];
    }
    str1[start + i] = '\0';
    return i;
}

void test_string_concat(void) {
    const int MAX = 7; 
    char* str1 = malloc(sizeof(char) * MAX);

    str1[0] = '\0';
    // printf("str1: %s\n", str1);
    // printf("Lenght: %d\n", string_len(str1));
    
    int copied = string_concat(str1, "Hola", MAX - 1 - string_len(str1));
    assert(copied == 4);    // Puedo copiar los 4 caracteres porque tengo espacio suficiente
    // printf("N° chars copied: %d\n", copied);
    // printf("New str1: %s\n", str1);
    // printf("Lenght: %d\n", string_len(str1));
    
    copied = string_concat(str1, " Mundooooooooo", MAX - 1 - string_len(str1));
    assert(copied == 2);    // Solo puedo copiar 2 caracteres en este caso, en total tendría 6 caracteres, o 7 (que es el máximo). Ya que limito el máximo a la cantidad de memoria solicitada.


    // printf("N° chars copied: %d\n", copied);
    // printf("New str1: %s\n", str1);
    // printf("Lenght: %d\n", string_len(str1));
    free(str1);

    printf("test_string_concat Finished\n");
}



int string_compare(char* str1, char* str2) {
    int len = (string_len(str1) <= string_len(str2) ? string_len(str1) : string_len(str2));

    for (int i = 0; i < len; ++i) {
        if (str1[i] < str2[i]) {
            return -1;
        }else if (str1[i] > str2[i]) {
            return 1;
        }
    }

    return (string_len(str1) < string_len(str2)) ? -1 : (string_len(str1) > string_len(str2)) ? 1 : 0;
}

void test_string_compare(void) {
    
    assert(string_compare("Hola", "Hola") == strcmp("Hola", "Hola"));
    assert(string_compare("Aola", "Hola") == strcmp("Aola", "Hola"));
    assert(string_compare("aola", "Hola") == strcmp("aola", "Hola"));
    assert(string_compare("Holas", "Hola") == strcmp("Holas", "Hola"));
    assert(string_compare("H", "h") == strcmp("H", "h"));
    assert(string_compare("", "") == strcmp("", ""));
    assert(string_compare("ha", "hA") == strcmp("ha", "hA"));

    printf("test_string_compare Finished\n");
}



int string_subcadena(char* str1, char* str2) {
    int i = 0;
    int str1Len = string_len(str1);
    int str2Len = string_len(str2);

    if (string_compare(str1, str2) == 0) return 0;
    else if (str2Len > str1Len) return -1;
    else {
        while (i < str1Len) {
            if (str1[i] == str2[0]) {
                if (str2Len > str1Len - i) return -1;

                int j = 0;
                int equal = true;

                while ( (i+j) < str1Len && j < str2Len && equal == true ) {
                    if (str1[i + j] != str2[j]) equal = false;
                    ++j;
                }
                
                if (equal == true) return i;
            }
            ++i;
        }   
    }

    return -1;
}

void test_string_subcadena(void) {
    assert(string_subcadena("Hola", "Hola") == 0);
    assert(string_subcadena("Hola", "lana") == -1);
    assert(string_subcadena("Hola", "ola") == 1);
    assert(string_subcadena("Hola", "la") == 2);
    assert(string_subcadena("", "la") == -1);
    assert(string_subcadena("Hola", "") == -1);
    assert(string_subcadena("", "") == 0);
    assert(string_subcadena("Cine", "Mundo") == -1);

    printf("test_string_subcadena Finished\n");
}



void string_unir(char* arregloStrings[], int n, char* sep, char* res) {
    for (int i = 0; i < n; ++i) {
        string_concat(res, arregloStrings[i], string_len(arregloStrings[i]));
        if (i < n - 1) string_concat(res, sep, string_len(sep));
    }
}

void test_string_unir(void) {
    char* arr[] = {"Hola", "Mund", "Hello", "World"};
    char* res = malloc(sizeof(char) * 10);
    res[0] = '\0';
    // printf("Res: %s\n", res);

    string_unir(arr, 2, "-", res);    
    // printf("Res now: %s\n", res);
    assert(string_compare(res, "Hola-Mund") == 0);
    free(res);

    printf("test_string_unir Finished\n");
}


int main(void) {
    test_string_len();
    test_string_reverse();
    test_string_compare();
    test_string_concat();
    test_string_subcadena();
    test_string_unir();

    printf("All Finished\n");
    return 0;
}
