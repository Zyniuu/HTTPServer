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
 * Node.c
 */

#include "Node.h"

#include <stdlib.h>
#include <string.h>

struct Node node_init(void *data, unsigned long size)
{
    struct Node node;
    // Allocate memory for the data in the node
    node.data = malloc(size);
    // Copy the data into the allocated memory
    memcpy(node.data, data, size);
    // Initialize the next pointer to NULL (no next node yet)
    node.next = NULL;
    // Initialize the prev pointer to NULL
    node.prev = NULL;

    return node;
}

void node_free(struct Node *node)
{
    // Make sure there is memory to be freed
    if (!node) return;
    // Free the memory allocated for the data
    free(node->data);
    // Free the memory allocated for the node itself
    free(node);
}