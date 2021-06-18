# Malloc:
La función "malloc" o "memory allocation" perteneciente a la biblioteca standar [stdlib.h](https://es.wikipedia.org/wiki/Stdlib.h) de C usada para asignar dinámicamente un único gran bloque de memoria de un tamaño específico.

Devuelve un puntero de tipo void que puede ser casteado a un puntero de cualquier forma. 

### Consideraciones:
* __Inicializa cada bloque con el valor basura por defecto.__

* __Si el espacio en memoria es insuficiente, la asignación falla y devuelve un puntero NULL.__

### Syntaxis:
```
puntero = (tipo*) malloc(tamaño);

//Ejemplo:
ptr = (int*) malloc(100 * sizeof(int));
```

### Por cada llamada a "malloc" DEBE existir una llamada a "free" (en caso de que la asignación sea exitosa).
 
## Further reading & more:
* [Referencia de malloc() de Microsoft](https://es.wikipedia.org/wiki/Stdlib.h) (Inglés)

* [_The Cherno_ - "POINTERS in C++" - Video de YT. Explicación concisa de que es un puntero (aunque se use C++ es aplicable a C)](https://www.youtube.com/watch?v=DTxHyVn0ODg&ab_channel=TheCherno) (Inglés)

* [_Labsopa_ - Consulta rápida sobre malloc() y free()](http://labsopa.dis.ulpgc.es/fso/cpp/intro_c/introc75.htm) (Español)

* [_Programación ATS_ (QEPD) - "Memoria Dinámica uso de malloc en C" ](https://www.youtube.com/watch?v=VSbkcFOoWdI&ab_channel=JacquiL%C3%B3pez) (Español)

* [_ChelinTutorials_ - "Tutorial Programacion en C nº41 : Malloc" - explicación con dibujitos](https://www.youtube.com/watch?v=P-LsLQcWQzU&ab_channel=Programaci%C3%B3nATSProgramaci%C3%B3nATSBest%C3%A4tigt) (Español)

* [_Geeksforgeeks_ - (malloc() / alloc() / free() / realloc())](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/) (Inglés)

* [Programiz - Ejemplos](https://www.programiz.com/c-programming/c-dynamic-memory-allocation) (Inglés)

* [Guru99 - Comparación y más ejemplos](https://www.guru99.com/c-dynamic-memory-allocation.html) (Inglés)

* [Stackoverflow - Casteo de malloc()](https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc) (Inglés)


