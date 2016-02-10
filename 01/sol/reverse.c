#include <stdio.h>
#define MAXLINE 1024          /* maximum input line length */

int getline_knr(char line[], int maxline);
int reverse(char line[], int len);

/* print the longest input line */
int main()
{
  int               len ; /* current line length */
  char    line[MAXLINE] ; /* current input line */

  while ((len = getline_knr(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s\n", line);
  }
  return 0;
}

/* getline_knr: read a line into s, return length                 */
int getline_knr(char s[],int lim)
{
  int c, len;

  for (len=0; len < lim-1 && (c=getchar())!=EOF && c!='\n'; ++len)
    s[len] = c;
  if (c == '\n') {
    s[len] = c;
    ++len;
  }
  s[len] = '\0';
  return len;
}

int reverse(char line[], int len)
{
  int i;
  int vlen = --len;
  /* skip null-pntr */
  --len;
  /* skip newline */
  --len;

  char ch;
 for (i=0; i<len; ++i) {
    ch        = line[i];
    line[i]   = line[len];
    line[len] = ch;
    --len;
  }
 line[vlen] = '\0';
 return 0;
}
