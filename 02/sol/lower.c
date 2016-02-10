/*
  Exercise 2-10. Rewrite the function lower, which converts upper case
  letters to lower case, with a conditional expression instead of if-else.
  */
#include <stdio.h>

void lower(char s[]);

int main() {
  char s[] = "HelLo WorlD!";
  lower(s);
  printf("%s\n", s);
  return 0;
}

void
lower(char s[]) {
  int c, i;
  c ^= c;
  i ^= i;
  while((c = s[i]) != '\0')
    (c >= 'A' && c <= 'Z') ? s[i++] += 'a' - 'A' : i++ ;
}
