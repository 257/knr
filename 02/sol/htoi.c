/* 
  Exercise 2-3. Write a function htoi(s), which converts a string of
  hexadecimal digits (including an optional 0x or 0X) into its
  equivalent integer value. The allowable digits are 0 through 9, a
  through f, and A through F.
*/

#include <stdio.h>

unsigned long htoi(const char s[]);

int main(void)
{
  printf("%12s %ld\n", "0x10", htoi("0x10"));
  printf("%12s %ld\n", "0xf", htoi("0xf"));
  printf("%12s %ld\n", "0XF", htoi("0XF"));
  printf("%12s %ld\n", "0xABADBABE", htoi("0xABADBABE"));
  printf("%12s %ld\n", "0xDeaDBeef", htoi("0xDeaDBeef"));
  printf("%12s %ld\n", "0xDeaDbEEF", htoi("0xDeaDbEEF"));
  //printf("%12s %ld\n", "0xDeaDbggF", htoi("0xDeaDbggF"));
  return 0;
}

unsigned long
htoi(const char s[])
{
  unsigned long n = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    char c = s[i];
    if (c == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
      i++;
    else if (c >= '0' && c <= '9')
      n = 16 * n + (c - '0');
    else if (c >= 'a' && c <= 'f')
      n = 16 * n + (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
      n = 16 * n + (c - 'A' + 10);
  }
  return n;
}
