// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

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
    char word[LENGTH + 1] = {'\0'};

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Make space for new node, return false if there is no space
        new_node = malloc(sizeof(node));

        // Make sure there is enough space
        if (!new_node)
        {
            printf("Sorry, no space!");
            unload();
            return false;
        }

        // When enough space, place word in new node
        strcpy(new_node -> word, word);

        // If index of array hashtable points to NULL, so the index hasn't been accessed
        if (hashtable[hash(word)] -> next != NULL)
        {

        }

        else
        {
            // New node points to NULL
            new_node -> next = NULL;

            // Store the address of the new node in the index of array hashtable
            hashtable[hash(word)] -> next = new_node;

            // Create a temporary node pointer
            node *temp_node_ptr;

            // Store address of originale head node in temporary pointer
            temp_node_ptr -> next = hashtable[hash(word)] -> next;

            // Update index value in array to location new head
            hashtable[hash(word)] -> next = new_node;
            
            // Assign next property new

        }

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
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
