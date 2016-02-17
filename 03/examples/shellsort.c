#include <stdio.h>
/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
  int gap, i, j, temp;
  int k;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i <= n; i++)
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
        temp     = v[j];
        v[j]     = v[j+gap];
        v[j+gap] = temp;
        k^=k;
        while (k<=n)
          printf("%d ", v[k++]);
        printf("\n");
      }
}

int main(){
  int v[] = {41,52,63,14,25,36,0,-1};
  int n;
  n^=n;
  while (v[n]>=0)
    printf("%d ", v[n++]);
  printf("\n");
  printf("sizeof v[] = %d\n", --n);
  shellsort(v,n);
  int m;
  for (m^=m; m<=n; m++)
    printf("%d ", v[m]);
  printf("\n");
  return 0; 
}
