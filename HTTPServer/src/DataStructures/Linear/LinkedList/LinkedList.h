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
 * LinkedList.h
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../../Common/Node.h"

// Structure representing a linked list
struct LinkedList
{
    // Pointer to the head (first node) of the list
    struct Node *head;
    // Current length (number of nodes) of the list
    int length;

    /**
     * Function pointer to insert a new node at a specified index
     * 
     * @param linked_list Pointer to the linked list
     * @param index Position at which to insert the new data
     * @param data Pointer to the data to be inserted
     * @param size Size of the data to be copied
     */
    void (*insert)(struct LinkedList *linked_list, int index, void *data, unsigned long size);

    /**
     * Function pointer to remove a node at a specified index
     * 
     * @param linked_list Pointer to the linked list
     * @param index position of the node to be removed
     */
    void (*remove)(struct LinkedList *linked_list, int index);

    /**
     * Function pointer to retrieve data from a node at a specified index
     * 
     * @param linked_list Pointer to the linked list
     * @param index Position of the node whose data is to be retrieved
     * 
     * @return Pointer to the data stored at the specified node
     */
    void *(*get)(struct LinkedList *linked_list, int index);
};

/**
 * Function to initialize a new linked list
 * 
 * @return A new LinkedList structure with default values
 */
struct LinkedList linked_list_init(void);

/**
 * Function to free all resources associated with the linked list
 * 
 * @param linked_list Pointer to the linked list to be freed
 */
void linked_list_free(struct LinkedList *linked_list);

#endif // LINKEDLIST_H