/*
 * Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalen1t complete list
 * abc...xyz in s2. Allow for letters of either case and digits, and be
 * prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that
 * a leading or trailing - is taken literally.
*/

#define MAX_RANGE 1024

#include <stdio.h>

void expand(char [], char []);
int isdigit(char);
int islower(char);
int isupper(char);
int isalpha(char);

int isdigit(char c){
  return ('0' <= c && c <= '9') ? 1 : 0;
}
int islower(char c){
  return ('a' <= c && c <= 'z') ? 1 : 0;
}
int isupper(char c){
  return ('A' <= c && c <= 'Z') ? 1 : 0;
}
int isalpha(char c){
  return (isupper(c)) ? 3 : islower(c);
}

void expand(char s1[], char s2[]){
  int beg, end, len1, len2;
  beg = end = len1 = len2 = 0;
  while (s1[len1++] == '-')
    ;
  int c, d;
  while ((c = s1[len1++])) 
    if (c == '-') {
      beg = s1[len1-2];
      (beg == end) ? beg++ : beg;
      end = s1[len1];
      d = isalpha(beg) + isalpha(end);
      switch (d) {
        case 0: /* range might be digits */
          if(isdigit(beg) && isdigit(end))
            while (beg <= end)
              s2[len2++] = beg++;
          break;
        case 6: case 2: /* both upper OR both lower */
          while(beg <= end)
            s2[len2++] = beg++;
          break;
        case 4:
          while (beg <= 'z')
            s2[len2++] = beg++;
          beg = 'A';
          while (beg <= end)
            s2[len2++] = beg++;
          break;
        case 3: case 1: /* got rubbish */
          break;
        default:
          break;
      }
    }
  s2[len2] = '\0';
}

int main() {
  char s1[] = "a-Z0-9";
  char s2[MAX_RANGE] = "got rubbish!";
  expand(s1,s2);
  printf("%s\n", s2);
  return 0;
}
