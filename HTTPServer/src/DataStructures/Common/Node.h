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
 * Node.h
 */

#ifndef NODE_H
#define NODE_H

// Structure representing a single node
struct Node
{
    // Storing data as a void pointer
    void *data;
    // A pointer to the next node in the chain
    struct Node *next;
    // A pointer to the previous node in the chain
    struct Node *prev;
};

/**
 * Constructor function to create a new node
 * 
 * @param data Pointer to the data to be stored in the node
 * @param size Size of the data to be copied into the node
 * 
 * @return The newly created node
 */
struct Node node_init(void *data, unsigned long size);

/**
 * Destructor function to delete a node
 * 
 * @param node Pointer to the node to be deleted
 */
void node_free(struct Node *node);

#endif // NODE_H