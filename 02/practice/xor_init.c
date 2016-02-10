#include <stdio.h>

int main() {
  int i = 1;
  printf("init i = %d;\n", i);
  i ^= i ;
  printf("i ^= i;\n");
  printf("i = %d\n", i);
}
