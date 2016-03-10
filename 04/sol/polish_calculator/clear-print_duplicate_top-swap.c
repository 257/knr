/* Exercise 4-4.
 * Add the commands 
 * to print the top element of the stack without popping, 
 * to duplicate it, and 
 * to swap the top two elements. Add a command 
 * to clear the stack.
 */

#include <stdio.h>
#include <stdlib.h>        /* for    atof() */

#define MAXOP        100   /* max size of operand or operator */
#define NUMBER       '0'   /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void dup_top(void);
void swap(void);
void clear_stack(void);

/* reverse Polish calculator */
int main()
{
    int type;
    int print = 0;
    int swaps = 0;
    double op2;
    unsigned int mod;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
    	switch (type) {
    	case NUMBER:
	    push(atof(s));
	    break;
	case '+':
	    push(pop() + pop());
	    break;
	case '*':
	    push(pop() * pop());
	    break;
	case '-':
	    op2 = pop();
	    push(pop() - op2);
	    break;
	case '%':
	    op2 = pop();
	    if (op2 != 0.0)
		push((unsigned int) pop() % (unsigned int) op2);
	    else
		/* possibly clear the stack here, see 4-6 */
		printf("error: no mod-zero\n");
	    break;
	case '/':
	    op2 = pop();
	    if (op2 != 0.0)
		push(pop() / op2);
	    else
		/* possibly clear the stack here, see 4-6 */
		printf("error: zero divisor\n");
	    break;
	case 'p':
	    print = 1;
	    print_top();
	    break;
	case 'd':
	    dup_top();
	    break;
	case 'c':
	    clear_stack();
	    break;
	case 's':
	    swaps = 1;
	    swap();
	    break;
	case '\n':
	    if (print || swaps)
	    	swaps = print^=print;
	    else 
	    	printf("\t%.8g\n", pop());
	    break;
	default:
	    printf("error: unknown command %s\n", s);
	    break;
	}
    }
    return 0;
}

/* Because + and * are commutative operators, the order in which the popped
 * operands are combined is irrelevant, but for - and / the left and right
 * operand must be distinguished. In
 */

// push(pop() - pop());         /* WRONG */

/* the order in which the two calls of pop are evaluated is not defined. To
 * guarantee the right order, it is necessary to pop the first value into a
 * temporary variable as we did in main.
 */

#define MAXVAL      100    /* maximum depth of val stack */

int sp = 0;                /* next free stack position */
double val[MAXVAL];        /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
	val[sp++] = f;
    else
	printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
	return val[--sp];
    else {
	printf("error: stack empty\n");
	return 0.0;
    }
}
void print_top(void)
{
    if (sp > 0)
    	printf("%.8g\n", val[sp-1]);
    else
	printf("error: stack empty\n");
}
void dup_top(void)
{
    /* don't need to know/check for sp and MAXVAL */
    double top = pop();
    push(top);
    push(top);
}
void swap(void)
{
    double tmp;
    if (sp >= 2) {
    	tmp       = val[sp-1];
    	val[sp-1] = val[sp-2];
    	val[sp-2] = tmp;
    }
    else
    	printf("takes 2 2swap");
}

void clear_stack(void)
{
    while (sp)
    	val[sp--] = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c, sign;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
	;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && c != '+')
	return c;
    //i = (c == '+') ? -1 : 0;
    i    = 0;
    sign = 0;

    if (c == '-' || c == '+') {
    	sign = c;
	/* atof() handles plus sign nicely; otherwise we should be
	 * postfix-incrementing the i here
	 */
	while (isdigit(s[++i] = c = getch()))
	    ;
    }
    if (isdigit(c))
	while (isdigit(s[++i] = c = getch()))
	    ;
    if (c == '.')
	while (isdigit(s[++i] = c = getch()))
	    ;
    s[i] = '\0';
    if (c != EOF)
	ungetch(c);
    /* check for sign first which should faild on majority of cases */
    return ((sign) && (i==1)) ? sign : NUMBER;
}

#define BUFSIZE 100 /* can more than one char be pushed to buf[]? */

char buf[BUFSIZE] ;  /* buffer for ungetch */
int  bufp = 0     ;  /* next free position in buf */

int  getch(void)     /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
    if (bufp >= BUFSIZE)
	printf("ungetch: too many characters\n");
    else
	buf[bufp++] = c;
}
