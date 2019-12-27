// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Word counter
int wordcounter = 0;
node *new_node;
node *next_node;


// Loads dictionary into memory, returning true if successful else false
// With help from https://johnyzaguirre.com/2018/11/07/cs50-week-4/
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
    char word[LENGTH + 1] = {'\0'};

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {

        // If head node points to NULL, malloc space for word and point to new location where word is stored
        if (hashtable[hash(word)] -> next == NULL)
        {
            // Make space for new node, return false if there is no space
            new_node = malloc(sizeof(node));
            if (!new_node)
            {
                printf("Sorry, no space!");
                unload();
                return false;
            }

            // When enough space, place word in new node and point to NULL
            strcpy(new_node -> word, word);
            new_node -> next = NULL;

            hashtable[hash(word)] -> next = new_node;
        }

        // Else, malloc new space for new word. Let new word point to old word. Let head point to new word
        else
        {
            next_node = malloc(sizeof(node));
            if (!next_node)
            {
                printf("Sorry, no space!");
                unload();
                return false;
            }

            strcpy(new_node -> word, word);
            next_node -> next = hashtable[hash(word)] -> next;

            hashtable[hash(word)] -> next = next_node;
        }

        // Add 1 to word counter
        wordcounter ++;
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
    // When the hash of the word points to NULL, word doesn't exist
    if (hashtable[hash(word)] -> next == NULL)
    {
        return false;
    }

    node *trav = hashtable[hash(word)];
    trav = trav -> next;

    while (trav -> next != NULL)
    {
        if (trav -> word == tolower(word))
        {
            return true;
        }

        else
        {
            trav = trav -> next;
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
