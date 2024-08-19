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
 * BST.c
 */

#include "BST.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Helper function to recursively free nodes in the BST
 * 
 * @param current Pointer to the current node being freed
 */
void bst_free_helper(struct Node *current);

/**
 * Helper function to create a new node with given data
 * 
 * @param data Pointer to the data to be stored in the node
 * @param size Size of the data to be copied into the node
 * 
 * @return A pointer to the newly created node
 */
struct Node *create_node_bst(void *data, unsigned long size);

/**
 * Helper function to recursively insert a new node into the BST
 * 
 * @param tree Pointer to the BST
 * @param current Double pointer to the current node being evaluated
 * @param data Pointer to the data to be inserted
 * @param size Size of the data to be copied into the node
 */
void insert_bst_helper(struct BST *tree, struct Node **current, void *data, unsigned long size);

/**
 * Helper function to recursively search for a node in the BST
 * 
 * @param tree Pointer to the BST
 * @param current Pointer to the current node being evaluated
 * @param data Pointer to the data being searched for
 * 
 * @return A pointer to the data if found, otherwise NULL
 */
void *search_bst_helper(struct BST *tree, struct Node *current, void *data);

void insert_bst(struct BST *tree, void *data, unsigned long size);
void *search_bst(struct BST *tree, void *data);

struct BST bst_init(int (*compare)(void *data1, void *data2))
{
    struct BST tree;

    // Initialize the root of the tree to NULL (empty tree)
    tree.head = NULL;
    // Set the comparison function for the BST
    tree.compare = compare;
    // Set function pointers for insertion and searching
    tree.insert = insert_bst;
    tree.search = search_bst;

    return tree;
}

void bst_free_helper(struct Node *current)
{
    if (!current) 
        return;
    if (current->prev)
        bst_free_helper(current->prev);
    if (current->next)
        bst_free_helper(current->next);
    node_free(current);
}

void bst_free(struct BST *tree)
{
    if (!tree) return;
    bst_free_helper(tree->head);
}

int bst_str_compare(void *data1, void *data2)
{
    int result = strcmp(data1, data2);
    if (result > 0)
        return 1;
    if (result < 0)
        return -1;
    return 0;
}

int bst_int_compare(void *data1, void *data2)
{
    int result = memcmp(data1, data2, sizeof(int));
    if (result > 0)
        return 1;
    if (result < 0)
        return -1;
    return 0;
}

int bst_float_compare(void *data1, void *data2)
{
    int result = memcmp(data1, data2, sizeof(float));
    if (result > 0)
        return 1;
    if (result < 0)
        return -1;
    return 0;
}

struct Node *create_node_bst(void *data, unsigned long size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node)
    {
        printf("Error: Failed to allocate memory for new_node.\n");
        exit(1);
    }
    *new_node = node_init(data, size);
    return new_node;
}

void insert_bst_helper(struct BST *tree, struct Node **current, void *data, unsigned long size)
{
    if (*current == NULL)
        *current = create_node_bst(data, size);
    // duplicates will be ignored
    if (tree->compare(data, (*current)->data) == 1)
        insert_bst_helper(tree, &(*current)->next, data, size);
    if (tree->compare(data, (*current)->data) == -1)
        insert_bst_helper(tree, &(*current)->prev, data, size);
}

void insert_bst(struct BST *tree, void *data, unsigned long size)
{
    insert_bst_helper(tree, &tree->head, data, size);
}

void *search_bst_helper(struct BST *tree, struct Node *current, void *data)
{
    if (current == NULL)
        return NULL;
    if (tree->compare(data, current->data) == 0)
        return current->data;
    else if (tree->compare(data, current->data) == 1)
        search_bst_helper(tree, current->next, data);
    else if (tree->compare(data, current->data) == -1)
        search_bst_helper(tree, current->prev, data);
}

void *search_bst(struct BST *tree, void *data)
{
    return search_bst_helper(tree, tree->head, data);
}