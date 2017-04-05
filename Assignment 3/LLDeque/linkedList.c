#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef TYPE
#define TYPE int
#endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

struct LinkedList;

struct LinkedList* linkedListCreate();
void linkedListDestroy(struct LinkedList* list);
void linkedListPrint(struct LinkedList* list);

// Deque interface

int linkedListIsEmpty(struct LinkedList* list);
void linkedListAddFront(struct LinkedList* list, TYPE value);
void linkedListAddBack(struct LinkedList* list, TYPE value);
TYPE linkedListFront(struct LinkedList* list);
TYPE linkedListBack(struct LinkedList* list);
void linkedListRemoveFront(struct LinkedList* list);
void linkedListRemoveBack(struct LinkedList* list);

// Bag interface

void linkedListAdd(struct LinkedList* list, TYPE value);
int linkedListContains(struct LinkedList* list, TYPE value);
void linkedListRemove(struct LinkedList* list, TYPE value);

#endif

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	assert(list != 0);

	struct Link* front = (struct Link*)malloc(sizeof(struct Link));
	struct Link* back = (struct Link*)malloc(sizeof(struct Link));

	front -> prev = 0;
	front -> next = back;
	front -> value = 0;

    back -> prev = front;
    back -> next = 0;
    back -> value = 0;

    list -> size = 0;
    list -> frontSentinel = front;
    list -> backSentinel = back;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */

static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{	// FIXME: you must write this
    assert(list && link);

    struct Link* addLink = (struct Link*)malloc(sizeof(struct Link));
    assert(addLink);
    addLink -> value = value;

    struct Link* temp = link -> prev;
    temp -> next = addLink;
    addLink -> prev = temp;
    link -> prev = addLink;
    addLink -> next = link;

    list -> size = list -> size + 1;

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{	// FIXME: you must write this
    assert(list -> size != 0 && list);

    (link -> prev) -> next = link -> next;
    (link -> next) -> prev = link -> prev;

    free(link);
    list -> size = list -> size - 1;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{	// FIXME: you must write this
    assert(list);
    addLinkBefore(list, list -> frontSentinel -> next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{	// FIXME: you must write this
    assert(list);
    addLinkBefore(list, list -> backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{	// FIXME: you must write this
    assert(list && (list -> size != 0));
    return list -> frontSentinel -> next -> value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{	// FIXME: you must write this
    assert(list && (list -> size != 0));
    return list -> backSentinel -> prev -> value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{	// FIXME: you must write this
    assert(!linkedListIsEmpty(list));
    removeLink(list, list -> frontSentinel -> next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{	// FIXME: you must write this
    assert(!linkedListIsEmpty(list));
    removeLink(list, list -> backSentinel -> prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{	// FIXME: you must write this
    return list -> size == 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{	// FIXME: you must write this
    assert(!linkedListIsEmpty(list));

    struct Link* temp = list -> frontSentinel -> next;

    do
    {
        printf("%d\n", temp -> value);
        temp = temp -> next;

    } while(temp -> next != 0);

}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{	// FIXME: you must write this
    assert(list != 0);

    struct Link* search = list -> frontSentinel -> next;

    while(search != list -> backSentinel)
    {
        if(search -> value == value)
        {
            return 1;
        }
        search = search -> next;
    }
    return 0;

}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{	// FIXME: you must write this
    assert(list != 0);

    struct Link* remove = list -> frontSentinel -> next;

    while(remove != list -> backSentinel)
    {
        if(remove -> value == value)
        {
            removeLink(list, remove);
        }
        remove = remove -> next;
    }
}



















