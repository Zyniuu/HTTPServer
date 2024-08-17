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
 * Queue.c
 */

#include "Queue.h"

void push_queue(struct Queue *queue, void *data, unsigned long size);
void *peek_queue(struct Queue *queue);
void pop_queue(struct Queue *queue);

struct Queue queue_init()
{
    struct Queue queue;
    // Initialize the underlying linked list
    queue.linked_list = linked_list_init();
    // Set function pointers for queue operations
    queue.push = push_queue;
    queue.peek = peek_queue;
    queue.pop = pop_queue;

    return queue;
}

void queue_free(struct Queue *queue)
{
    if (!queue) return;
    // Free the underlying linked list
    linked_list_free(&queue->linked_list);
}

void push_queue(struct Queue *queue, void *data, unsigned long size)
{
    // Insert the new element at the end of the linked list (enqueue)
    queue->linked_list.insert(&queue->linked_list, queue->linked_list.length, data, size);
}

void *peek_queue(struct Queue *queue)
{
    // Get the element at the front of the linked list (first in queue)
    return queue->linked_list.get(&queue->linked_list, 0);
}

void pop_queue(struct Queue *queue)
{
    // Remove the element at the front of the linked list (dequeue)
    queue->linked_list.remove(&queue->linked_list, 0);
}