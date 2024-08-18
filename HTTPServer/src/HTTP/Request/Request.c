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

#include <stdlib.h>
#include <string.h>

struct Dictionary extract_request_line(char *request_line);
struct Dictionary extract_header_fields(char *header_fields);
struct Dictionary extract_message_body(char *message_body);

struct Request request_init(char *request_message)
{
    struct Request request;
    char *save_ptr = NULL;

    char *request_line = str_multi_tok(request_message, &save_ptr, "\r\n");
    char *header_fields = str_multi_tok(NULL, &save_ptr, "\r\n\r\n");
    char *message_body = str_multi_tok(NULL, &save_ptr, "");

    request.request_line = extract_request_line(request_line);
    request.header_fields = extract_header_fields(header_fields);
    request.message_body = extract_message_body(message_body);

    return request;
}
