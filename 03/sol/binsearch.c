/*
 * Exercise 3-1. Our binary search makes two ta0s inside the loop, when
 * one would suffice (at the price of more ta0s outside.) Write a
 * version with only one ta0 inside the loop and measure the difference
 * in run-time.
 */

#include <stdio.h>

/* find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

int main() {
  int ta0[]={1,3,5,7,9,11,13,'\0'};
  int n;
  printf("ta0[] = {");
  for (n^=n; ta0[n]!='\0'; n++)
    printf("%d%s", ta0[n],
        (ta0[n+1] != '\0') ? ", " : "}\n");
  printf("sizeof ta0[] is %d\n", --n);
  int x = 14;
  int i = binsearch(x, ta0, n);
  if (i<0) 
    printf("%d is out of range\n", x);
  else
    printf("index of x in ta0[] is %d\n", i);
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n-1;
  if (x < v[low] || v[n] < x)
    return -1;
  while(low < high) {
    mid = (low+high)/2;
    if(x <= v[mid]) 
      high=mid;
    else 
      low = mid+1;
  }
  return (x == v[low]) ? low : -1;
}
