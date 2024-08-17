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
 * LinkedList.c
 */

#include "LinkedList.h"

#include <stdlib.h>

/**
 * Helper function to create a new node with given data
 * 
 * @param data Pointer to the data to be stored in the node
 * @param size Size of the data to be copied into the node
 * 
 * @return A pointer to the newly created node
 */
struct Node *create_node_ll(void *data, unsigned long size);

/**
 * Helper function to traverse the linked list to a specific index
 * 
 * @param linked_list Pointer to the linked list
 * @param index Index to which the traversal should occur
 * 
 * @return A pointer to the node at the specified index, or NULL if the index is out of bounds
 */
struct Node *travel_ll(struct LinkedList *linked_list, int index);

void insert_ll(struct LinkedList *linked_list, int index, void *data, unsigned long size);
void remove_ll(struct LinkedList *linked_list, int index);
void *get_ll(struct LinkedList *linked_list, int index);

struct LinkedList linked_list_init()
{
    struct LinkedList new_list;

    // Initialize the head of the list to NULL (empty list)
    new_list.head = NULL;
    new_list.length = 0;

    // Set function pointers to the corresponding linked list operations
    new_list.insert = insert_ll;
    new_list.remove = remove_ll;
    new_list.get = get_ll;

    return new_list;
}

void linked_list_free(struct LinkedList *linked_list)
{
    if (!linked_list) return;
    // Loop through the list and remove each node from the head
    for (int i = 0; i < linked_list->length; i++)
        linked_list->remove(linked_list, 0);
}

struct Node *create_node_ll(void *data, unsigned long size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    *new_node = node_init(data, size);
    return new_node;
}

struct Node *travel_ll(struct LinkedList *linked_list, int index)
{
    
    if (index < 0 || index >= linked_list->length)
        return NULL;

    struct Node *current = linked_list->head;

    for (int i = 0; i < index; i++)
        current = current->next;

    return current;
}

void insert_ll(struct LinkedList *linked_list, int index, void *data, unsigned long size)
{
    struct Node *new_node = create_node_ll(data, size);

    if (index == 0)
    {
        // Insert at the head of the list
        new_node->next = linked_list->head;
        linked_list->head = new_node;
    }
    else
    {
        // Insert at a position other than the head
        struct Node *prev_elem = travel_ll(linked_list, index - 1);
        new_node->next = prev_elem->next;
        prev_elem->next = new_node;
    }

    linked_list->length += 1;
}

void remove_ll(struct LinkedList *linked_list, int index)
{
    if (index == 0)
    {
        // Remove the head of the list
        struct Node *node_to_remove = linked_list->head;
        if (node_to_remove)
        {
            linked_list->head = node_to_remove->next;
            node_free(node_to_remove);
        }
    }
    else
    {
        // Remove a node at a position other than the head
        struct Node *prev_elem = travel_ll(linked_list, index - 1);
        struct Node *node_to_remove = prev_elem->next;
        prev_elem->next = node_to_remove->next;
        node_free(node_to_remove);
    }

    linked_list->length -= 1;
}

void *get_ll(struct LinkedList *linked_list, int index)
{
    struct Node *current = travel_ll(linked_list, index);
    if (current)
        return current->data;
    return NULL;
}