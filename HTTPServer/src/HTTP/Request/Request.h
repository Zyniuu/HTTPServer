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
 * Request.h
 */

#ifndef REQUEST_H
#define REQUEST_H

#include "../../DataStructures/NonLinear/Dictionary/Dictionary.h"

// Structure representing an HTTP request, with separate dictionaries 
// for the request line, header fields, and message body
struct Request
{
    struct Dictionary request_line;
    struct Dictionary header_fields;
    struct Dictionary message_body;
};

/**
 * Function to initialize a Request structure by parsing an HTTP request message
 * 
 * @param request_message A string containing the full HTTP request message
 * 
 * @return A Request structure with the parsed request line, headers, and body
 */
struct Request request_init(char *request_message);

/**
 * Function to free all resources associated with a Request structure
 * 
 * @param request Pointer to the Request structure to be freed
 */
void request_free(struct Request *request);

#endif // REQUEST_H