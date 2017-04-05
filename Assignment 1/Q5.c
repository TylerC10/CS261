/* CS261- Assignment 1 - Q.5*/
/* Name: Tyler Cope
 * Date: 1/18/2017
 * Solution description: This program defines a function called sticky, that takes
 * a word as a parameter, and converts it to sticky caps.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     if(ch >= 'a' && ch <= 'z')
        {
          return ch-'a'+'A';
        }
     else
       {
         return ch;
       }
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     if(ch >= 'A' && ch <= 'Z')
     {
       return ch-'A'+'a';
     }
     else
       {
         return ch;
       }
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i;

    for(i = 0; i < strlen(word); i++)
        {
          if(i % 2 == 0)
           {
             word[i] = toUpperCase(word[i]);
           }
            else
            {
              word[i] = toLowerCase(word[i]);
            }
        }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[256];
    char* tester;
    tester = word; //So we can pass it to sticky

    printf("Enter a word to see it in Studly caps.\n");
    scanf("%s", tester);

    /*Call sticky*/
    sticky(tester);

    /*Print the new word*/
    printf("%s\n", tester);

    return 0;
}
