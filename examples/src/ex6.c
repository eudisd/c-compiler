/*--------------------------------------------------------*/
/* This source file demonstrates integer array declaration and 
   use. */
/*--------------------------------------------------------*/

/*
 * By: Eudis Duran
 * Spring 2011
 */

int main()
{
    int x, sorted;
    x = 20;

    int a[5];
    a[0] = 10;

    /* First we print the original x */

    printf(x);

    /* Next, we print the newly assigned x */

    x = a[0];    
    printf (x);

}
