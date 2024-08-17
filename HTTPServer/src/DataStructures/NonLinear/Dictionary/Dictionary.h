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
 * Dictionary.h
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Entry.h"
#include "../BST/BST.h"

// Structure representing a Dictionary (key-value store) using a Binary Search Tree (BST) for storage
struct Dictionary
{
    // The underlying BST structure to store dictionary entries
    struct BST bst;

    /**
     * Function pointer to insert a new key-value pair into the dictionary
     * 
     * @param dict Pointer to the Dictionary structure
     * @param key Pointer to the key data
     * @param key_size Size of the key data to be copied
     * @param value Pointer to the value data
     * @param value_size Size of the value data to be copied
     */
    void (*insert)(struct Dictionary *dict, void *key, unsigned long key_size, void *value, unsigned long value_size);

    /**
     * Function pointer to search for a value in the dictionary by its key
     * 
     * @param dict Pointer to the Dictionary structure
     * @param key Pointer to the key data being searched for
     * @param key_size Size of the key data
     * 
     * @return A pointer to the value associated with the key if found, otherwise NULL
     */
    void *(*search)(struct Dictionary *dict, void *key, unsigned long key_size);
};

/**
 * Function to initialize a new Dictionary
 * 
 * @param compare Function pointer for comparing two keys in the dictionary
 * 
 * @return A new Dictionary structure with default values and function pointers initialized
 */
struct Dictionary dictionary_init(int (*compare)(void *data1, void *data2));

/**
 * Function to free all resources associated with the Dictionary
 * 
 * @param dict Pointer to the Dictionary structure to be freed
 */
void dictionary_free(struct Dictionary *dict);

/**
 * Comparison function for comparing two string-based dictionary entries
 * 
 * @param entry1 Pointer to the first dictionary entry
 * @param entry2 Pointer to the second dictionary entry
 * 
 * @return -1 - entry1 < entry2, 0 - entry1 == entry2, 1 - entry1 > entry2
 */
int compare_string_entries(void *entry1, void *entry2);

#endif // DICTIONARY_H