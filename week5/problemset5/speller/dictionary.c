// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int num_of_words = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17579;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *cursor = table[hash_value];
    while(cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // initialize hash value int
    unsigned int hash_value = 0;

    // loop through characters of word, process whole word
    for (int i = 0; i < N && word[i] != '\0'; i++)
    {
        // establish position for characters in word
        hash_value = hash_value * 26 + toupper(word[i]) - 'A';
    }
    // return hash value but make sure within bounds of N (hash table size)
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("file error");
        return false;
    }

    // add buffer for length defined in dictionary.h
    char buffer[LENGTH];

    // read strings and exit when returns EOF to avoid infinite loop
    while(fscanf(file, "%s", buffer) != EOF)
    {
        // create new node for each word
        node *n =  malloc(sizeof(node));

        // hash word to obtain a hash value
        unsigned int hash_value = hash(buffer);

        //insert node into hash table at that location
        strcpy(n->word, buffer);
        n->next = table[hash_value];
        table[hash_value] = n;
        num_of_words++;
    }
    // close file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // return total words calculated by load function
    return num_of_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iteration through table
    for (int i = 0; i < N; i++)
    {
        // video gives tmp and cursor to use
        node *tmp = table[i];
        node *cursor = table[i];

        // free up the linked list
        while(cursor != NULL)
        {
            // move through table until cursor == NULL
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    //return true when succesful
    return true;
}
