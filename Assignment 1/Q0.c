/* CS261- Assignment 1 - Q. 0*/
/* Name: Tyler Cope
 * Date: 1/18/2017
 * Solution description: This program creates a function that takes
 * a pointer to an int as a parameter and prints the values of that
 * pointer, the address it's pointing to, and the actual address.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
        printf("The value of iptr is: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
        printf("The address iptr is pointing to is %p\n",iptr);

     /*Print the address of iptr itself*/
        printf("The address of iptr is %p\n", (void *) &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 5;

    /*print the address of x*/
    printf("%p\n",(void*)&x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("The value of x is: %d\n", x);

    return 0;
}
