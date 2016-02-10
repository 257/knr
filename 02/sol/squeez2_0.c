/*
  Exercise 2-4. Write an alternative version of squeeze(s1,s2) that
  deletes each character in s1 that matches any character in the string
  s2.
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);
void squeeze_helper(char s[], int c);

/* squeeze: delete all c from s */
void
squeeze_helper(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

void
squeeze(char s1[], char s2[]) {
  int i = 0;
  while (s2[i++] != '\0')
    ;
  while (i>=0)
    squeeze_helper(s1,s2[i--]);
}

int main() {
  char s1[] = "foo uoo coo koo";
  char s2[] = "o ";
  squeeze(s1,s2);
  printf("%s\n", s1);
  return 0;
}
