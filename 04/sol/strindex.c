/*
 * Exercise 4-1. Write the function strindex(s,t) which returns the
 * position of the rightmost occurrence of t in s, or -1 if there is
 * none.
*/
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int knr_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main()
{
  char line[MAXLINE];
  int last;
  int found = 0;

  while (knr_getline(line, MAXLINE) > 0) {
    last = strindex(line, pattern);
    if (last>=0) {
      printf(" %s", line);
      found++;
    }
    else
      printf("  %s", line);
    int i = 0;
    while(i++<last+1)
      printf(" ");
    printf("%d\n", last);
  }
  return found;
}

/* knr_getline: get line into s, return length */
int knr_getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;
  int last = -1;

  for (i^=i; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    /* if k=0 && t[0] == '\0' then t must have been empty */
    if (t[k] == '\0')
      last = i;
  }
  return last;
}
