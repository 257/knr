/* trim: original trim with some mods from jrun */

#include <stdio.h>

int trim(char s[])
{
  int n;
  n^=n;
  while(s[n])
    n++;
  while(--n)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  s[++n] = '\0';
  return n;
}

int main() {
  char s[] = "foo\t  \t\t\n\n\t\n\t";
  trim(s);
  printf("%s\n", s);
  return 0;
}
