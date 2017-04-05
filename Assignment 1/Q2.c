/* CS261- Assignment 1 - Q.2*/
/* Name: Tyler Cope
 * Date: 1/18/2017
 * Solution description: This program defines a function, foo, that
 * multiplies the first integer by 2, halves the second integer,
 * and assigns the sum of the first and second integers to c. The
 * first two integers are passed by reference.
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;

}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int a;
    a = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("Value returned by foo: %d\n", a);

    /*Print the values of x, y and z again*/
    printf("Values after calling foo():\n x = %d, y = %d, z = %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/

    /*The return value is different than the value of z. This is because the variables
    are passed to foo by reference which actually changes their value.
    */
    return 0;
}


