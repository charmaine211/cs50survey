// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Word counter
int wordcounter = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // create a temporary node
        node *temp = malloc(sizeof(node));

        strncpy(temp->word, word, sizeof(word));

        // implement hash function to get the index
        int index = hash(word);

        // if the corresponding index in hashtable is empty, assign it to the temp node
        if (hashtable[index] == NULL)
        {
            hashtable[index] = temp;
        }

        // else append temp to the start of the linked list
        else
        {
            temp->next = hashtable[index];
            hashtable[index] = temp;
        }

        wordcounter++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcounter;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len = strlen(word);
    char lword[len + 1];
    for (int i = 0; i < len; i++)
    {
        lword[i] = tolower(word[i]);
    }
    lword[len] = '\0';

    int bucket = hash(lword);
    node *cursor = hashtable[bucket];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lword) != 0)
        {
            cursor = cursor->next;
        }

        else
        {
            return true;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
// Code from https://stackoverflow.com/questions/31336535/fastest-method-for-freeing-up-memory-allocated-to-a-hash-table-in-c
bool unload(void)
{
    node *temp;
    node *crawler;

    for(int n = 0; n < wordcounter; n++)
    {
        if (hashtable[n] != NULL)
        {
            // If only 1 node free it
            crawler = hashtable[n];
            while (crawler != NULL)
            {
                temp = crawler->next;
                free(crawler);
                crawler = temp;
            }

            // free last node in list
            temp = crawler;
            free(temp);
        }
    }

    return true;
}