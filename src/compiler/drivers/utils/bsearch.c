#include <stdio.h>
#include <stdlib.h>

int bint_comp(const void *a, const void *b);

int bfloat_comp(const void *a, const void *b);

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    double b[10] = {0.1, 0.01, 0.2, 0.022, 0.101, 0.1, 12.3, 10.3, 11.3, 1.1};
    double key = 0.21;
    double *item = bsearch(&key, b, 10, sizeof(double), bfloat_comp);
    if(!item){
        
    }
    else {
        printf("%f\n", *item);
    }
    return 0;
}

int bint_comp(const void *a, const void *b)
{
    if ( *(int*)a > *(int*)b ) return 1;
    if ( *(int*)a == *(int*)b ) return 0;
    if ( *(int*)a < *(int*)b ) return -1;
}

int bfloat_comp(const void *a, const void *b)
{
    if ( *(double*)a > *(double*)b ) return 1;
    if ( *(double*)a == *(double*)b ) return 0;
    if ( *(double*)a < *(double*)b ) return -1;
}
