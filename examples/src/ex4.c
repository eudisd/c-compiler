/*--------------------------------------------------------*/
/* Here, I demonstrate while and do-while looping constructs.
 * I do so, by presenting the iterative fibonacci algorithm, 
 * for a very small set of numbers.
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

    a = 10;
    b = 5;

    printf ("Greatest Commond Divisisor");
    do {
        c = a % b;
        a = b;
        b = c;
        printf "FUCK";
    }while( b != 0 );
    
    printf ("The GCD is: ");
    printf(b);










    
}
