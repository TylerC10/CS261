/* CS261- Assignment 1 - Q.4*/
/* Name: Tyler Cope
 * Date: 1/18/2017
 * Solution description: This program sorts structures, student, by their score in
 * ascending order.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     struct student temp;
     int i;
     int j;

     for(i = 0; i < n; i++)
     {
         for(j = 0; j < n; j++)
         {
             if(students[i].score < students[j].score)
             {
                 temp = students[i];
                 students[i] = students[j];
                 students[j] = temp;
             }
         }
     }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n * sizeof(struct student));

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    int i;
    int list[10];
    for(i = 0; i < 10; i++)
     {
         list[i] = i;
     }
     for(i = 0; i < 10; i++)            //This method of generating random numbers was found on StackOverflow
     {
         int j = i + rand() % (11 - i);
         int temp = list[i];
         list[i] = list[j];
         list[j] = temp;

         students[i].id = list[i];
     }

     for(i = 0; i < 10; i++)
     {
        students[i].score = (rand() % 101);
     }

    /*Print the contents of the array of n students.*/

    for(i = 0; i < 10; i++)
     {
         printf("%d %d\n", students[i]. id, students[i].score);
     }

    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
    printf("Contents after sorting are: \n");
    for(i = 0; i < 10; i++)
     {
         printf("%d %d\n", students[i]. id, students[i].score);
     }

    return 0;
}
