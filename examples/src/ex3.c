/*--------------------------------------------------------*/
/* This test demonstrates declaration of variables in different
 * scopes.  In other words, lexical scoping is presented.
 * It also shows the conditional if else construct. 
 */
/*--------------------------------------------------------*/

/*
 * By: Eudis Duran
 * Spring 2011
 */

int main()
{
    int x;
    x = 1;
    printf (x);  /* This x is different from the one below */

    if( x == 1 ){
        int x;
        x = 2;
        printf ("This should execute!");
        printf (x);
    }
    else {
        printf ("This should not!");
    }
}
