#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

int main() {
  int x;
  x ^= 7;
  printf("%d\n", bitcount(x));
  return 0;
}
