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
 * BST.h
 */

#ifndef BST_H
#define BST_H

#include "../../Common/Node.h"

// Structure representing a Binary Search Tree (BST)
struct BST
{
    // Pointer to the root node of the tree
    struct Node *head;

    /**
     * Function pointer for comparing two data elements
     * 
     * @param data1 Pointer to the first data element
     * @param data2 Pointer to the second data element
     * 
     * @return -1 - data1 < data2, 0 - data1 == data2, 1 - data1 > data2
     */
    int (*compare)(void *data1, void *data2);

    /**
     * Function pointer to insert a new node into the BST
     * 
     * @param tree Pointer to the BST
     * @param data Pointer to the data to be stored in the new node
     * @param size Size of the data to be copied into the node
     */
    void (*insert)(struct BST *tree, void *data, unsigned long size);

    /**
     * Function pointer to search for a node in the BST
     * 
     * @param tree Pointer to the BST
     * @param data Pointer to the data to be searched for
     */
    void *(*search)(struct BST *tree, void *data);
};

/**
 * Function to initialize a new Binary Search Tree (BST)
 * 
 * @param compare Function pointer for comparing two data elements in the tree
 * 
 * @return A new BST structure with default values and function pointers initialized
 */
struct BST bst_init(int (*compare)(void *data1, void *data2));

/**
 * Function to free all resources associated with the BST
 * 
 * @param tree Pointer to the BST to be freed
 */
void bst_free(struct BST *tree);

/**
 * Function to compare two strings for the BST
 * 
 * @param data1 Pointer to the first string
 * @param data2 Pointer to the second string
 * 
 * @return -1 - data1 < data2, 0 - data1 == data2, 1 - data1 > data2
 */
int bst_str_compare(void *data1, void *data2);

/**
 * Function to compare two integers for the BST
 * 
 * @param data1 Pointer to the first integer
 * @param data2 Pointer to the second integer
 * 
 * @return -1 - data1 < data2, 0 - data1 == data2, 1 - data1 > data2
 */
int bst_int_compare(void *data1, void *data2);

/**
 * Function to compare two floats for the BST
 * 
 * @param data1 Pointer to the first float
 * @param data2 Pointer to the second float
 * 
 * @return -1 - data1 < data2, 0 - data1 == data2, 1 - data1 > data2
 */
int bst_float_compare(void *data1, void *data2);

#endif // BST_H