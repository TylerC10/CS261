/************************************************
 * Name: Tyler Cope
 * Date: 2/3/2017
 * Description: The implementation file for the circularList.h file.
 * It contains the functions for a circular linked list.'
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list != 0);
    list -> sentinel = (struct Link*)malloc(sizeof(struct Link));
    assert(list -> sentinel != 0);

    list -> sentinel -> next = list -> sentinel;
    list -> sentinel -> prev = list -> sentinel;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
	assert(newLink);
	newLink -> value = value;
	newLink -> next = 0;
	newLink -> prev = 0;

	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    assert(list && link);
    assert(link -> next != 0 && link -> prev != 0);

    struct Link* temp = createLink(value);
    link -> next -> prev = temp;
    temp -> next = link -> next;
    link -> next = temp;
    temp -> prev = link;

    list -> size = list -> size + 1;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
    assert(list && link);

    link -> prev -> next = link -> next;
    link -> next -> prev = link -> prev;

    free(link);

    list -> size = list -> size - 1;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */

void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list);

    while(list -> size > 0)
    {
        circularListRemoveFront(list);
    }

    free(list -> sentinel);
    list -> sentinel = 0;
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list);
    addLinkAfter(list, list -> sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list);
	addLinkAfter(list, list -> sentinel -> prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list);
	return list -> sentinel -> next -> value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list);
	return list -> sentinel -> prev -> value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list);
    removeLink(list, list -> sentinel -> next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list);
    removeLink(list, list -> sentinel -> prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list);
	if(list -> size == 0)
    {
        return 0;
    }
	return 1;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list);
    //assert(!circularListIsEmpty(list));
    struct Link* temp = list -> sentinel -> next;

    while(temp != list -> sentinel)
    {
        printf("%f", temp -> value);
        temp = temp -> next;
    }

}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    assert(list);
    //assert(!circularListIsEmpty(list));

    struct Link* search = list -> sentinel -> next;
    struct Link* temp;
    list -> sentinel -> prev = search;

    do
    {
        temp = search -> next;
        if(temp -> next == list -> sentinel)
        {
            list -> sentinel -> next = temp;
        }

        search -> next = search -> prev;
        search -> prev = temp;
        search = temp;
    }while(search != list -> sentinel);
}















