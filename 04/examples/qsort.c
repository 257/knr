#include <stdio.h>
#include "qsort.h"

int main()
{
    int v[]   = {9,8,7,6,5,4,3,2,1,0};
    int left  = 0;
    int right = 9;

    printf("v[] = ");
    print_array(v, left, right);
    qsort(v, left, right);
    printf("v[] = ");
    print_array(v, left, right);
    return 0;
}
