/* Exercise 4-11. Modify getop so that it doesn't need to use ungetch.
 * Hint: use an internal static variable.
*/
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i;
    int static c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
	;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
	return c;      /* not a number
			* note that NUMBER is defined char '0' rather than
			* 0 [an int] because c could be '\0' 
		      */
    i = 0;
    if (isdigit(c))    /* collect integer part */
	while (isdigit(s[++i] = c = getch()))
	    ;
    if (c == '.')      /* collect fraction part */
	while (isdigit(s[++i] = c = getch()))
	    ;
    s[i] = '\0';
    if (c != EOF)
	ungetch(c);
    return NUMBER;
}
