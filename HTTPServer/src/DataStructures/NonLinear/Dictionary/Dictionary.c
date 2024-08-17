/**
 * HTTP Server in C
 * Copyright (C) 2024 Mateusz Zynek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Dictionary.c
 */

#include "Dictionary.h"

#include <stdlib.h>
#include <string.h>

/**
 * Helper function to recursively free all nodes in the BST used by the dictionary
 * 
 * @param current Pointer to the current node being freed
 */
void dictionary_free_helper(struct Node *current);

void insert_dict(struct Dictionary *dict, void *key, unsigned long key_size, void *value, unsigned long value_size);
void *search_dict(struct Dictionary *dict, void *key, unsigned long key_size);

struct Dictionary dictionary_init(int (*compare)(void *data1, void *data2))
{
    struct Dictionary dict;

    // Initialize the underlying BST with the provided comparison function
    dict.bst = bst_init(compare);

    // Set function pointers for insertion and searching
    dict.insert = insert_dict;
    dict.search = search_dict;

    return dict;
}

void dictionary_free_helper(struct Node *current)
{
    if (!current) return;
    // Recursively travel the nodes
    if (current->prev)
        dictionary_free_helper(current->prev);
    if (current->next)
        dictionary_free_helper(current->next);
    // Free the memory allocated for the entry stored in the node
    entry_free((struct Entry *)current->data);
    // Free the node itself
    free(current);
}

void dictionary_free(struct Dictionary *dict)
{
    dictionary_free_helper(dict->bst.head);
}

void insert_dict(struct Dictionary *dict, void *key, unsigned long key_size, void *value, unsigned long value_size)
{
    // Create a new entry with the provided key and value
    struct Entry entry = entry_init(key, key_size, value, value_size);
    // Insert the entry into the BST
    dict->bst.insert(&dict->bst, &entry, sizeof(entry));
}

void *search_dict(struct Dictionary *dict, void *key, unsigned long key_size)
{
    // Create a temporary entry with the key to search in the BST
    int dummy_val = 0;
    struct Entry temp = entry_init(key, key_size, &dummy_val, sizeof(int));
    void *result = dict->bst.search(&dict->bst, &temp);
    // If the entry is found, return the associated value, otherwise return NULL
    if (result)
        return ((struct Entry *)result)->value;
    return NULL;
}

int compare_string_entries(void *entry1, void *entry2)
{
    if (strcmp((char *)(((struct Entry *)entry1)->key), (char *)(((struct Entry *)entry2)->key)) > 0)
        return 1;
    if (strcmp((char *)(((struct Entry *)entry1)->key), (char *)(((struct Entry *)entry2)->key)) < 0)
        return -1;
    return 0;
}