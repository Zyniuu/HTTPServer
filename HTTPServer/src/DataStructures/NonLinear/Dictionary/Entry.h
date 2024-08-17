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
 * Entry.h
 */

#ifndef ENTRY_H
#define ENTRY_H

// Structure representing an entry in a dictionary
struct Entry
{
    // Pointer to the key associated with this entry
    void *key;
    // Pointer to the value associated with this entry
    void *value;
};

/**
 * Function to initialize a new entry with a key and value
 * 
 * @param key Pointer to the key data
 * @param key_size Size of the key data to be copied
 * @param value Pointer to the value data
 * @param value_size Size of the value data to be copied
 * 
 * @return A new Entry structure with the key and value initialized
 */
struct Entry entry_init(void *key, unsigned long key_size, void *value, unsigned long value_size);

/**
 * Function to free the memory associated with an entry
 * 
 * @param entry Pointer to the Entry structure to be freed
 */
void entry_free(struct Entry *entry);

#endif // ENTRY_H