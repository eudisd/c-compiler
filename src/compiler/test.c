/*--------------------------------------------------------*/
/* This source file demonstrates gotos.  Branching accross
 * scopes is not supported. */
/*--------------------------------------------------------*/

/*
 * By: Eudis Duran
 * Spring 2011
 */



int main()
{
    int x;
    x = 10;

    goto label2;

    printf ("Do not print this");

label2:
   
    x = 5;
    printf(x);
    

}
