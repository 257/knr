/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of
 * itoa; that is, convert an integer into a string by calling a recursive
 * routine.
 */

#include <stdio.h>
#include <limits.h>
#define MAXSLEN 1024

void ritoa(int n, char s[])
{
    static int i = 0;
    if (n < 0) {
    	s[i++] = '-';
    	n = -n;
    }
    if (n / 10)
	ritoa(n / 10, s);
    s[i++] = (n%10) + '0';
    s[i] = '\0';
}

int main() {
    int n = INT_MIN + 1;
    char s[MAXSLEN];
    ritoa(n, s);
    printf("%s\n", s);
    return 0;
}
