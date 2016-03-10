/* There is one more thing to worry about - the definitions and declarations
 * shared among files. As much as possible, we want to centralize this, so that
 * there is only one copy to get and keep right as the program evolves.
 */

#define NUMBER       '0'   /* signal that a number was found */
void push(double);
double pop(void);
int getop(char []);
int  getch(void);
void ungetch(int);
