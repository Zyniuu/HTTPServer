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
 * Helpers.h
 */

#ifndef HELPERS_H
#define HELPERS_H

/**
 * Function to tokenize a string using a specified delimiter, 
 * similar to strtok_r, but allows for multi-character delimiters
 * 
 * @param input The string to tokenize; if NULL, continues tokenizing the string passed in the previous call
 * @param save_ptr Pointer to a char* that stores the position in the string between calls
 * @param delimiter The delimiter string used to tokenize the input string
 * 
 * @return A pointer to the next token, or NULL if there are no more tokens
 */
char *str_multi_tok(char *input, char **save_ptr, char *delimiter);

#endif // HELPERS_H