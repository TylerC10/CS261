/*
 * CS 261 Assignment 5
 * Name: Tyler Cope
 * Date: 3/3/2017
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);

    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    int i;
    for (i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
    int priority;                                   //Used to save the integer when user puts the priority
    char* filename = malloc(sizeof(char) * 256);    //Two variables to hold the name and task description
    char* description = malloc(sizeof(char) * 256);

    switch(command)
    {
    case 'l':
        printf("Please enter the filename: ");
        fgets(filename, 150, stdin);                //Get the name of the file from the user

        FILE* fileRead = fopen(filename, "r");      //Open the file and assign it to a variable; used r for read
        listLoad(list, fileRead);                   //Load the list using the variable we just created
        printf("The list has been loaded from file successfully.\n\n");   //Let user know file is uploaded
        fclose(fileRead);
        break;

    case 's':
        printf("Please enter the filename: ");
        fgets(filename, 150, stdin);            //Similar logic of getting file from user
        FILE* fileSave = fopen(filename, "w");  //Put the fopen in a variable, used w for write
        listSave(list, fileSave);               //Call the listSave function to save the list
        printf("The list has been saved into the file successfully.\n");
        fclose(fileSave);
        break;

    case 'a':
        printf("Please enter the task description: ");
        fgets(description, 150, stdin);                 //Get the task from the user
        printf("Please enter the task priority (0-999): ");
        scanf("%d", &priority);                         //Get priority from user
        Task* addTask = taskNew(priority, description); //Create a new task passing it priority and description
        dyHeapAdd(list, addTask, taskCompare);        //Compare priority of task to know where it goes
        printf("The task '%s' has been added to your to-do list.\n\n", description);
        break;

    case 'g':
        if(dySize(list) == 0)
        {
            printf("You need to add a task first.\n\n");
        }
        else
        {
            printf("Your first task is: '%s'\n", ((struct Task *)dyHeapGetMin(list))->name);
            printf("\n");
        }
        break;

    case 'r':
        if(dySize(list) == 0)
        {
            printf("Your list is already empty.\n");
        }
        else
        {
            struct Task* temp =(struct Task*)dyHeapGetMin(list);    //Set a temp task to delete
            printf("Your first task '%s' has been removed from the list.\n\n",temp -> name);  //Need to print the statement before deleting
            dyHeapRemoveMin(list, taskCompare);                     //Remove it
            taskDelete(temp);                                       //Delete temporary task
        }
        break;

    case 'p':
        if(dySize(list) == 0)
        {
            printf("Your list is already empty.\n\n");
        }
        else
        {
            listPrint(list);                //Make use of the function to print
        }
        break;

    case 'e':
        printf("Program closing. Goodbye.\n\n");
        break;
    }

    free(filename);         //Avoid memory leaks since we used malloc to create these
    free(description);
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */

    dyDelete(list);
    return 0;
}
