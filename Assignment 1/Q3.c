/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     int temp;
     int i;
     int j;

     for(i = 0; i < n; i++)
     {
         for(j = 0; j < n; j++)
         {
             if(number[i] < number[j])
             {
                 temp = number[i];
                 number[i] = number[j];
                 number[j] = temp;
             }
         }
     }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int* numArray = (int*)malloc(n * sizeof(int));


    /*Fill this array with random numbers, using rand().*/
    
    int i;
    for(i = 0; i < n; i++)
    {
        numArray[i] = rand() % 20;
    }

    /*Print the contents of the array.*/
    printf("Contents of array are: \n");

    for(i = 0; i < n; i++)
    {
        printf("%d\n", numArray[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(numArray, n);


    /*Print the contents of the array.*/
    printf("Contents of array are after sorting are: \n");

     for(i = 0; i < n; i++)
    {
        printf("%d\n", numArray[i]);
    }
    
    printf("\n");
    return 0;
}
