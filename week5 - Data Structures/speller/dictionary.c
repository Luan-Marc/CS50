// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

unsigned int cont = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //unsigned int pos = hash(word);
    node *cursor = table[hash(word)];

    while (cursor != NULL)
    {

        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
       
        cursor = cursor->next;
       
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
     
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++) 
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("coundt load");
        return 1;
    }

    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) == 1)
    {

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {

            fclose(dict);
            return false;
        }

        // setar valores
        strcpy(n->word, word);
        unsigned int pos = hash(word);

        // adiciona a lista
        n->next = table[pos];
        // faz referencia a primeira posiçao table
        table[pos] = n;
        //printf ("%s \n", table[pos] -> word);
        cont++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // node percorrer hash table

    unsigned int wordc = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            wordc++;
            cursor = cursor->next;
        }
    }

    return wordc;
    return cont;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
    
    }
    
    return true;
}
    
