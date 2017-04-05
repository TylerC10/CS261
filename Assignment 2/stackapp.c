/*	stack.c: Stack application. */
/* CS261- Assignment 2 - Balance Check With Stack*/
/* Name: Tyler Cope
 * Date: 1/27/2017
 * Solution description: This program uses a stack to check if a string is balanced
 * or not.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    char c;
    DynArr *holder = newDynArr(8);


    do
        {
        c = nextChar(s);                    //We can use a do/while loop to iterate and use
        switch( c )                         // a switch statement instead of an if statement
            {

            case '[':
                pushDynArr(holder, ']');    //If we find an opening character, we know that we'll
                break;                      //need to match it with a closing character later on
				            //so we can just push the closing character onto the stack
            case '(':
                pushDynArr(holder, ')');
                break;

            case '{':
                pushDynArr( holder, '}');
                break;


            case ']':
                if(!(isEmptyDynArr(holder)) &&(topDynArr(holder) == c))
                    {
                        popDynArr(holder);        //If we get to a closing character, it should
                    }                               //match what's on the stack. If not then we know
                else                                // it's not balanced and we return 0
                    {
                        return 0;
                    }
                break;

            case ')':		
                if(!(isEmptyDynArr(holder)) &&(topDynArr(holder) == c))
                    {
                        popDynArr(holder);		//If the string is balanced and we get to a closing 
                    }					//character, it should match what's on the stack
                else
                    {
                        return 0;
                    }
                break;

            case '}':
                if(!(isEmptyDynArr(holder)) &&(topDynArr(holder) == c))
                    {
                        popDynArr(holder);
                    }
                else
                    {
                        return 0;
                    }
                break;


            default:				//We can just ignore any characters that aren't what we're looking for
                break;
            }
        } while(c != '\0');		//The loop terminates when it gets to the end of the string



    if(!isEmptyDynArr(holder))          //If the stack has any values then we know that the string
        {                               //isn't balanced since we're popping off all the characters
            return 0;
        }

    deleteDynArr(holder);
    return 1;
}

int main(int argc, char* argv[]){
	
	char* s = "()";	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

