/*
   Exercise 2-4. Write an alternative version of squeeze(s1,s2) that
   deletes each character in s1 that matches any character in the string
   s2.
   */

#include <stdio.h>
void
squeeze2(char s[], char t[]) {
  int i, j, k;
  for (k = 0; t[k] != '\0'; k++) {
    for (i = j = 0; s[i] != '\0'; i++)
      if (s[i] != t[k])
        s[j++] = s[i];
    s[j] = '\0';
  }
}
int main() {
  char s1[] = "foo uoo coo koo";
  char s2[] = "o ";
  squeeze2(s1,s2);
  printf("%s\n", s1);
  return 0;
}
