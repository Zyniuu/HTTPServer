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
 * Helpers.c
 */

#include "Helpers.h"

#include <stdlib.h>
#include <string.h>

char *str_multi_tok(char *input, char **save_ptr, char *delimiter)
{
    // If a new string is provided, update the save_ptr to point to it
    if (input != NULL)
        *save_ptr = input;
    // If save_ptr is NULL, return NULL (no more tokens)
    if (*save_ptr == NULL)
        return *save_ptr;
    // Find the next occurrence of the delimiter in the string
    char *end = strstr(*save_ptr, delimiter);
    // If no delimiter is found, return the remainder of the string
    if (end == NULL)
    {
        char *temp = *save_ptr;
        *save_ptr = NULL;
        return temp;
    }
    // Save the current position as the next token
    char *temp = *save_ptr;
    // Null-terminate the token and update save_ptr to point past the delimiter
    *end = '\0';
    *save_ptr = end + strlen(delimiter);
    // Return the current token
    return temp;
}