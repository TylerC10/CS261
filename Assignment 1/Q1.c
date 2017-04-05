/* CS261- Assignment 1 - Q.1*/
/* Name: Tyler Cope
 * Date: 1/18/2017
 * Solution description: This program creates ten student structs, gives them
 * values for ID and score, displays their information, prints the min, max, and average,
 * and deallocates the memory at the end.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* stud = malloc(10 * sizeof(struct student));

     /*return the pointer*/
     return stud;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
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

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i]. id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = 100;
     float avg;
     int max = 0;
     int total = 0;
     int i;

     for(i = 0; i < 10; i++)
     {
         total += students[i].score;
     }

     avg = total / 10.0;

     for(i = 0; i < 10; i++)
     {
         if(students[i].score < min)
         {
             min = students[i].score;
         }
     }

     for(i = 0; i < 10; i++)
     {
         if(students[i].score > max)
         {
             max = students[i].score;
         }
     }

      printf("Minimum Score: %d\n", min);
      printf("Maximum Score: %d\n", max);
      printf("Average Score: %.2f\n", avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if(stud != NULL)
     {
         free(stud);
         stud = 0;
     }
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate(stud);

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
