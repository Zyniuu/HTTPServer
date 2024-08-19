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
 * Request.c
 */

#include "Request.h"
#include "../../Helpers/Helpers.h"
#include "../../DataStructures/Linear/Queue/Queue.h"

#include <stdlib.h>
#include <string.h>

/**
 * Helper function to extract and parse the request line from an HTTP request
 * 
 * @param request_line String containing the request line of the HTTP request
 * 
 * @return A Dictionary with the parsed components of the request line (e.g., method, URI, version)
 */
struct Dictionary extract_request_line(char *request_line);

/**
 * Helper function to extract and parse the header fields from an HTTP request
 * 
 * @param header_fields String containing the HTTP header fields
 * 
 * @return A Dictionary with the parsed header fields (key-value pairs)
 */
struct Dictionary extract_header_fields(char *header_fields);

/**
 * Helper function to extract and parse the message body from an HTTP request
 * 
 * @param message_body String containing the message body of the HTTP request
 * 
 * @return A Dictionary with the message body data (if present)
 */
struct Dictionary extract_message_body(char *message_body);

struct Request request_init(char *request_message)
{
    struct Request request;
    // Create a copy of the request message to avoid modifying the original string
    char request_message_copy[strlen(request_message) + 1];
    strcpy(request_message_copy, request_message);
    char *save_ptr = NULL;

    // Parse the request line, headers, and body using the str_multi_tok function
    char *request_line = str_multi_tok(request_message_copy, &save_ptr, "\r\n");
    char *header_fields = str_multi_tok(NULL, &save_ptr, "\r\n\r\n");
    char *message_body = str_multi_tok(NULL, &save_ptr, "ð");

    // Extract the parsed data into dictionaries
    request.request_line = extract_request_line(request_line);
    request.header_fields = extract_header_fields(header_fields);
    request.message_body = extract_message_body(message_body);

    return request;
}

void request_free(struct Request *request)
{
    dictionary_free(&request->request_line);
    dictionary_free(&request->header_fields);
    dictionary_free(&request->message_body);
}

struct Dictionary extract_request_line(char *request_line)
{
    struct Dictionary dict = dictionary_init(compare_string_entries);
    char request_line_copy[strlen(request_line) + 1];
    strcpy(request_line_copy, request_line);
    char *save_ptr = NULL;

    // Tokenize the request line to extract the method, URI, and HTTP version
    char *request_method = str_multi_tok(request_line_copy, &save_ptr, " ");
    char *request_uri = str_multi_tok(NULL, &save_ptr, " ");
    str_multi_tok(NULL, &save_ptr, "/"); // Skip the "HTTP/" prefix
    char *http_major_version = str_multi_tok(NULL, &save_ptr, ".");
    char *http_minor_version = str_multi_tok(NULL, &save_ptr, "ð");

    // Insert the parsed components into the dictionary
    dict.insert(&dict, "Method", strlen("Method") + 1, request_method, strlen(request_method) + 1);
    dict.insert(&dict, "Uri", strlen("Uri") + 1, request_uri, strlen(request_uri) + 1);
    dict.insert(&dict, "Version_major", strlen("Version_major") + 1, http_major_version, strlen(http_major_version) + 1);
    dict.insert(&dict, "Version_minor", strlen("Version_minor") + 1, http_minor_version, strlen(http_minor_version) + 1);

    return dict;
}

struct Dictionary extract_header_fields(char *header_fields)
{
    struct Dictionary dict = dictionary_init(compare_string_entries);
    char header_fields_copy[strlen(header_fields) + 1];
    strcpy(header_fields_copy, header_fields);
    char *save_ptr = NULL;

    // Queue to hold each line of header fields
    struct Queue queue = queue_init();

    // Tokenize the header fields line by line
    char *header_fields_line = str_multi_tok(header_fields_copy, &save_ptr, "\r\n");
    while (header_fields_line)
    {
        queue.push(&queue, header_fields_line, strlen(header_fields_line) + 1);
        header_fields_line = str_multi_tok(NULL, &save_ptr, "\r\n");
    }

    // Process each line and extract key-value pairs
    char *field = (char *)queue.peek(&queue);
    while (field)
    {
        char *key = str_multi_tok(field, &save_ptr, ": ");
        char *val = str_multi_tok(NULL, &save_ptr, "ð");

        if (val)
            dict.insert(&dict, key, strlen(key) + 1, val, strlen(val) + 1);

        queue.pop(&queue);
        field = (char *)queue.peek(&queue);
    }

    queue_free(&queue);
    return dict;
}

struct Dictionary extract_message_body(char *message_body)
{
    struct Dictionary dict = dictionary_init(compare_string_entries);;

    if (message_body)
        dict.insert(&dict, "Data", strlen("Data") + 1, message_body, strlen(message_body) + 1);

    return dict;
}