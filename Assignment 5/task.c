/*
 * CS 261 Assignment 5
 * Name: Tyler Cope 
 * Date: 3/3/2017
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
    Task *addTask = malloc(sizeof(Task));   //create a new task
    
    strcpy(addTask->name, name);            //give the task a name with strcpy
    
    addTask->priority = priority;           //assign priority to the task

    return addTask;                         //return the created task
    
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
    // FIXME: implement
    
    Task* leftTask = (Task*) left;
    Task* rightTask = (Task*) right;
    
    
    
    if(leftTask -> priority > rightTask -> priority)
    {
        return 1;
    }
    else if(leftTask -> priority < rightTask -> priority)
    {
        return -1;
    }
    
    return 0;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
