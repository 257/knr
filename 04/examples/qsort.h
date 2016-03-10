void print_array(int v[], int left, int right)
{
    printf("{");
    while (left<right)
	printf("%d,", v[left++]);
    printf("%d}\n", v[left]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    printf("%5s = %d\n", "left", left);
    printf("%5s = %d\n", "right", right);
    if (left >= right)                  /* do nothing if array contains */
	return;                         /* fewer than two elements */
    printf("move partition elem\n");
    print_array(v, left, right);
    swap(v, left, (left + right)/2);    /* move partition elem */
    print_array(v, left, right);
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
	if (v[i] < v[left]){
	    printf("%5s = %d\n", "last", last+1);
	    printf("%5s = %d\n", "i", i);
	    swap(v, ++last, i);
	    print_array(v, left, right);
	}
    printf("v[%d] = %d <=> v[%d] = %d\n", last, v[last], left, v[left]);
    swap(v, left, last);                /* restore partition elem */
    print_array(v, left, right);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
