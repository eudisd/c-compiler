/*--------------------------------------------------------*/
/* Here, I demonstrate while and do-while looping constructs.
 * I do so, by presenting the iterative fibonacci algorithm, 
 * and the GCD algorithm for a very small set of numbers.
 */
/*--------------------------------------------------------*/

/*
 * By: Eudis Duran
 * Spring 2011
 */



int main()
{
    int fib_total;

    fib_total = 20;
    
    int i, j, fib;

    i = 0;
    j = 1;
    
    /* f(n) = f(n - 1) + f(n - 2) */
    printf ("Fibonacci Sequence");
    while( fib < fib_total ){
        fib = i  + j;
        j = i;
        i = fib;
        printf (fib);
    }

    int a, b, c, d;

    a = 6;
    b = 6;

    printf ("Greatest Commond Divisisor");
    do {
        c = a % b;
        a = b;
        b = c;
    }while( b > 0 );
    
    printf ("The GCD is: ");
    printf(a);
   
}
