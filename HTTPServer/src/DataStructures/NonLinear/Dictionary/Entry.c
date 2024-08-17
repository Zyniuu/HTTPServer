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
 * Entry.c
 */

#include "Entry.h"

#include <stdlib.h>
#include <string.h>

struct Entry entry_init(void *key, unsigned long key_size, void *value, unsigned long value_size)
{
    struct Entry entry;

    // Allocate memory for the key and value
    entry.key = malloc(key_size);
    entry.value = malloc(value_size);

    // Copy the key and value data into the allocated memory
    memcpy(entry.key, key, key_size);
    memcpy(entry.value, value, value_size);

    return entry;
}

void entry_free(struct Entry *entry)
{
    if (!entry) return;
    // Free the memory allocated for the key and value
    free(entry->key);
    free(entry->value);
    // Free the memory allocated for the Entry structure itself
    free(entry);
}