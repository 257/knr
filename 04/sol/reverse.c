
/* Exercise 4-13. Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <stdio.h>

void reverse(char s[])
{
	static int i = 0, len;

	if (s[i]) {
		int c = s[i++];
		reverse(s);
		s[len-i] = c;
		i--;
	} else {
		len = i;
	}
}

int main()
{
	char s[] = "0123456789";
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	return 0;
}
