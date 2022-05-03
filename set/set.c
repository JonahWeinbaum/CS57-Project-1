/* 
 * set.c - CS50 'set' module
 *
 * This program allows for the creation, deletion,
 * and usage (insertion, printing, etc.) of a set module
 * as described in the lab3-spec.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/*
* Creates a new set with NULL head
* Inputs: None
* Outputs: Pointer to new set (set_t*)
*          or NULL on error
*/
set_t *set_new(void) 
{
    //Create pointer to unitialized keypair list
    set_t *set = (set_t*)malloc(sizeof(set_t));

    //If memory space is invalid
    if (set == NULL) {
        return NULL;
    //If memory space is valid
    } else {
        //Create an empty keypair list
        set->head = NULL;
        return set;
    }
}

/*
* Inserts keypair at head of set
* Inputs: Set pointer (set_t *), key (const char*), item (void*)
* Outputs: Whether or not item was inserted (bool)
*/
bool set_insert(set_t* set, const char* key, void* item)
{
    //Check for NULL parameters
    if (set == NULL || key == NULL || item == NULL) {
        return false;
    }

    //Check if key exists
    if (set_find(set, key) != NULL) {
        return false;
    }

    //Create new keypair for this key
    keypair_t *keypair = (keypair_t*)malloc(sizeof(keypair_t));

    //Check for invalid memory space
    if (keypair == NULL) {
        return false;
    }

    //Create space for key of same length
    keypair->key = (char*)malloc(strlen(key) + 1);

    //Check for invalid memory space
    if (keypair->key == NULL) {
        return false;
    }
        
    //If memory space is valid fill in the new keypair
    strcpy(keypair->key, key);
    keypair->item = item;
    
    //Set is empty
    if (set->head == NULL) {
        keypair->next = NULL;
        set->head = keypair;
    //Counters is non-empty (insert at head of list)
    } else {
        keypair->next = set->head;
        set->head = keypair;
    }

    //Return that value was inserted
    return true;
}

/*
* Locates a key within a set
* Inputs: Set pointer (set_t *), key (const char*)
* Outputs: Pointer to item in found keypair (void*)
*          or NULL when no key is found
*/
void* set_find(set_t* set, const char* key) 
{
    //Parameter is NULL
    if (set == NULL || key == NULL) {
        return NULL;
    }

    //Assume item is not found
    void *found = NULL;

    for (keypair_t *curr = set->head; curr != NULL; curr = curr->next) {
        //If key matches then item is found
        if (strcmp(curr->key, key) == 0) {
            found = curr->item;
        }
    }

    //Return found item
    return found;
}

/*
* Prints a given set
* Inputs: Set pointer (set_t*), Filestream (FILE*), 
*         Print Function (void*) 
* Outputs: None
*/
void set_print(set_t* set, FILE* fp, 
               void (*itemprint)(FILE* fp, const char* key, void* item) )
{
    if (fp == NULL) {
        return;
    }

    if (set == NULL) {
        fprintf(fp, "(null)");
        return;
    }

    if (itemprint == NULL) {
        fprintf(fp, "{}");
        return;
    }

    fprintf(fp, "{");
    for (keypair_t *curr = set->head; curr != NULL; curr = curr->next) {
        (*itemprint)(fp, curr->key, curr->item);
        
        if (curr->next != NULL) {
            fprintf(fp, ", ");
        }
    }
    fprintf(fp, "}");
}

/*
* Iterates through a set and performs a function on each
* item with the given argument
* Inputs: Set pointer (set_t*), Argument (void*), Item Function (void*)
* Outputs: None
*/
void set_iterate(set_t* set, void* arg,
                 void (*itemfunc)(void* arg, const char* key, void* item) )
{
    //Set or itemfnc is NULL
    if (set == NULL || itemfunc == NULL) {
        return;
    }

    //Loop through set and run itemfun on each elt.
    for (keypair_t *curr = set->head; curr != NULL; curr = curr->next) {
        (*itemfunc)(arg, curr->key, curr->item);
    }
}

/*
* Frees memory within the set , as well as the set itself.
* For the items, the user provides a delete function. 
* Inputs: Set pointer (set_t*), Item Delete Function (void*)
* Outputs: None
*/
void set_delete(set_t* set, void (*itemdelete)(void* item) ) 
{
    if (set == NULL) {
        return;
    }

    keypair_t *currnext;
    for (keypair_t *curr = set->head; curr != NULL; curr = currnext) {
        if (itemdelete != NULL) {
            (*itemdelete)(curr->item);
        }

        //Free the key string
        free(curr->key);

        currnext = curr->next; //This must be stored in a variable since once 
                               //Curr is freed, this memory is inaccesible
        
        //Free the keypair
        free(curr);
    }

    //Free the keypair list
    free(set);
}

