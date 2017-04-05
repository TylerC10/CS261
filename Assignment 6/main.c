/***********************************
 * Name: Tyler Cope
 * Date: 3/10/2017
 * Description: This program uses a hash map to check the concordance of a document.
 * It then prints the concordance for each word in the document.
 **********************************/

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);

    clock_t timer = clock();

    HashMap* map = hashMapNew(10);

    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.
    int i;
    FILE *openFile = fopen(fileName, "r");
    char* word = nextWord(openFile);

    while(word != NULL)
    {
        if(hashMapContainsKey(map, word))
        {
            int count = *(hashMapGet(map, word));       //Search for the key to check the count
            hashMapPut(map, word, ++count);             //Put the incremented count associated with the word
        }
        else
        {
            hashMapPut(map, word, 1);                   //If the key isn't found, put one into the slot
        }
        free(word);                                     //Lets us use the next word
        word = nextWord(openFile);
    }

    for(i = 0; i < map -> capacity; i++)
    {
        HashLink* printLink = map -> table[i];          //Iterate through to print the values
        if(printLink != 0)
        {
            while(printLink != 0)
            {
                printf("%s: %d\n", printLink -> key, printLink -> value);
                printLink = printLink -> next;
            }
        }
    }

    fclose(openFile);                                   //We're done with the file so we can close it
    // --- Concordance code ends here ---

    hashMapPrint(map);

    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));

    hashMapDelete(map);
    return 0;
}
