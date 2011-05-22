/*--------------------------------------------------------*/
/* This source file demonstrates gotos/labels.  Branching accross
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

    /* Goto First, Label Second */
    goto label2;

    printf ("Do not print this");

label2:
   
    x = 5;
    printf("Print this: ");
    printf(x);


    /* Label First, Goto Second */
    
    int counter;
    counter = 0;    

label1:

    printf ("This always gets printed!");

    if( counter < 10 ){
        counter = counter + 1;
        goto label1;
    }
    
    /* Here the loop ends */
    

}
