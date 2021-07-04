#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "slist.h"
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out


// static void imprimir_entero(int dato) {
//   printf("%d ", dato);
// }

int main(void) {
  runTests();
  

  return 0;
}
