/* 
 * hashtable.c - CS50 'hashtable' module
 *
 * This program allows for the creation, deletion,
 * and usage (insertion, printing, etc.) of a hashtable module
 * as described in the lab3-spec.
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"



/*
* Creates a new ht with (null) sets
* and size given by user
* Inputs: Number of sets (const int)
* Outputs: Pointer to new ht (hashtable_t*)
*          or NULL on error
*/
hashtable_t* hashtable_new(const int num_slots)
{
    //Create pointer to unitialized hashtable
    hashtable_t *ht = (hashtable_t*)malloc(sizeof(hashtable_t));

    //If memory space is invalid
    if (ht == NULL) {
        return NULL;
    //If memory space is valid
    } else {
        //Create pointer to array (contiguous memory) of set_t with num_slots
        ht->table = (set_t**)calloc(num_slots, sizeof(set_t *));
        ht->num_slots = num_slots;
        return ht;
    }
}

/*
* Inserts keypair at head of set in given hashslot
* Inputs: Ht pointer (hashtable_t *), key (const char*), item (void*)
* Outputs: Whether or not item was inserted (bool)
*/
bool hashtable_insert(hashtable_t* ht, const char* key, void* item)
{
    //Parameter is NULL
    if (ht == NULL || key == NULL || item == NULL) {
        return false;
    }

    //Key is already in hashtable
    if (hashtable_find(ht, key) != NULL) {
        return false;
    }

    //Keyhash is the location of the set that the key is a part of
    int keyhash = hash_jenkins(key, ht->num_slots);

    //Keyhash is out of hashtable range
    if (keyhash >= ht->num_slots) {
        return false;
    }

    //No set is present in this spot
    if (ht->table[keyhash] == NULL) {
        //Create new set and insert the keypair
        set_t *set = set_new();
        set_insert(set, key, item); 

        //Insert new set into hashtable
        ht->table[keyhash] = set;
        return true;
    //Set is present in this spot
    } else {
        //Insert keypair into set at that hashtable location
        set_insert(ht->table[keyhash], key, item);

        return true;
    }
}

/*
* Locates a key within a set in the table
* Inputs: Ht pointer (hashtable_t *), key (const char*)
* Outputs: Pointer to item in found keypair (void*)
*          or NULL when no key is found
*/
void* hashtable_find(hashtable_t* ht, const char* key)
{
    //Parameter is NULL
    if (ht == NULL || key == NULL) {
        return NULL;
    }

    //Keyhash is the location of the set that the key is a part of
    int keyhash = hash_jenkins(key, ht->num_slots);

    //If item is found return it, otherwise function returns NULL
    return set_find(ht->table[keyhash], key);
}

/*
* Prints a given ht
* Inputs: Ht pointer (hashtable_t*), Filestream (FILE*), 
*         Print Function (void*) 
* Outputs: None
*/
void hashtable_print(hashtable_t* ht, FILE* fp, 
                     void (*itemprint)(FILE* fp, const char* key, void* item))
{
    //File is NULL
    if (fp == NULL) {
        return;
    }

    //Hashtable is NULL    
    if (ht == NULL) {
        fprintf(fp, "(null)\n");
        return;
    }

    //Loop through each hashtable slot
    for (int i = 0; i < ht->num_slots; i++) {
        //Print the set in the given slot
        set_print(ht->table[i], fp, itemprint);
        fprintf(fp, "\n");
    }
}

/*
* Iterates through a ht and performs a function on each
* item with the given argument
* Inputs: Ht pointer (hashtable_t*), Argument (void*), Item Function (void*)
* Outputs: None
*/
void hashtable_iterate(hashtable_t* ht, void* arg,
                       void (*itemfunc)(void* arg, const char* key, void* item) )
{
    //Parameter is NULL
    if (ht == NULL || itemfunc == NULL) {
        return;
    }

    //Loop through each hashtable slot
    for (int i = 0; i < ht->num_slots; i++) {
        //Iteratre over the set in the given spot
        set_iterate(ht->table[i], arg, itemfunc);   
    }
}

/*
* Frees memory within each set , as well as the set itself,
* in each slot of the hashtable, as well as the hashtable itself.
* For the items, the user provides a delete function. 
* Inputs: Ht pointer (hashtable_t *), Item Delete Function (void*)
* Outputs: None
*/
void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item) )
{
    //Hastable is NULL
    if (ht == NULL) {
        return;
    } 

    if (itemdelete == NULL) {
        return;
    }

    //Loop through each hashtable slot
    for (int i = 0; i < ht->num_slots; i++) {
        //Delete the set in the given spot
        set_delete(ht->table[i], itemdelete);
    }

    //Free the memory for the table and hashtable
    free(ht->table);
    free(ht);
}