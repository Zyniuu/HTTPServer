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
 * Queue.h
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "../LinkedList/LinkedList.h"

// Structure representing a Queue data structure, implemented using a LinkedList
struct Queue
{
    // The underlying linked list used to store the queue elements
    struct LinkedList linked_list;

    /**
     * Function pointer to push (enqueue) a new element onto the queue
     * 
     * @param queue Pointer to the Queue structure
     * @param data Pointer to the data to be added to the queue
     * @param size Size of the data to be copied into the queue
     */
    void (*push)(struct Queue *queue, void *data, unsigned long size);

    /**
     * Function to peek at the front element of the queue without removing it
     * 
     * @param queue Pointer to the Queue structure
     * 
     * @return A pointer to the data at the front of the queue
     */
    void *(*peek)(struct Queue *queue);

    /**
     * Function pointer to pop (dequeue) the front element from the queue
     * 
     * @param queue Pointer to the Queue structure
     */
    void (*pop)(struct Queue *queue);
};

/**
 * Function to initialize a new Queue
 * 
 * @return A new Queue structure with the underlying linked list initialized and function pointers set
 */
struct Queue queue_init();

/**
 * Function to free all resources associated with the Queue
 * 
 * @param queue Pointer to the Queue structure to be freed
 */
void queue_free(struct Queue *queue);

#endif // QUEUE_H