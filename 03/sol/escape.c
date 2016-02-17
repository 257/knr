/* Exercise 3-2. Write a function escape(s,t) that converts characters
 * like newline and tab into visible escape sequences like \n and \t as
 * it copies the string t to s. Use a switch. Write a function for the
 * other direction as well, converting escape sequences into the real characters.
 */
#include <stdio.h>

void escape(char s[], char t[]);

int main(){
  char t[] = "hello\t\t\vworld!\n";
  char s[20];
  escape(s,t);
  printf("%s\n", t);
  printf("%s\n", s);
  return 0;
}
void
escape(char s[], char t[]){
  int i, j;
  i^=i;
  j^=j;
  while (t[i]) {
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        i++;
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        i++;
        break;
      case '\v':
        s[j++] = '\\';
        s[j++] = 'v';
        i++;
        break;
      default:
        s[j++] = t[i++];
        break;
    }
    s[j] = t[i];
  }
}
