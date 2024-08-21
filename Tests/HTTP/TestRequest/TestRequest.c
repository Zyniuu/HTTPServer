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
 * TestRequest.c
 */

#include "TestRequest.h"

#include <stdlib.h>
#include <string.h>

void test_request_init()
{
    char *request_message = "GET /index.php?name=string&email=string HTTP/1.1\r\nHost: www.example.com\r\nConnection: keep-alive\r\n\r\nbody-data";
    struct Request request = request_init(request_message);

    // Check request line
    char *method = (char *)request.request_line.search(&request.request_line, "Method", strlen("Method") + 1);
    char *uri = (char *)request.request_line.search(&request.request_line, "Uri", strlen("Uri") + 1);
    char *query = (char *)request.request_line.search(&request.request_line, "Query", strlen("Query") + 1);
    char *version_major = (char *)request.request_line.search(&request.request_line, "Version_major", strlen("Version_major") + 1);
    char *version_minor = (char *)request.request_line.search(&request.request_line, "Version_minor", strlen("Version_minor") + 1);

    ASSERT_TRUE(method, "GET", strlen("GET") + 1, "Testing if method is set to 'GET'");
    ASSERT_TRUE(uri, "/index.php", strlen("/index.php") + 1, "Testing if uri is set to '/index.php'");
    ASSERT_TRUE(query, "name=string&email=string", strlen("name=string&email=string") + 1, "Testing if query is set to 'name=string&email=string'");
    ASSERT_TRUE(version_major, "1", strlen("1") + 1, "Testing if major version is set to '1'");
    ASSERT_TRUE(version_minor, "1", strlen("1") + 1, "Testing if minor version is set to '1'");

    // Check header fields
    char *host = (char *)request.header_fields.search(&request.header_fields, "Host", strlen("Host") + 1);
    char *connection = (char *)request.header_fields.search(&request.header_fields, "Connection", strlen("Connection") + 1);

    ASSERT_TRUE(host, "www.example.com", strlen("www.example.com") + 1, "Testing if Host is set to 'www.example.com'");
    ASSERT_TRUE(connection, "keep-alive", strlen("keep-alive") + 1, "Testing if Connection is set to 'keep-alive'");

    // Check message body
    char *body_data = (char *)request.message_body.search(&request.message_body, "Data", strlen("Data") + 1);

    ASSERT_TRUE(body_data, "body-data", strlen("body-data") + 1, "Testing if message body is set to 'body-data'");

    request_free(&request);
}

void test_request()
{
    TEST_SUITE("Http Request Init Tests");
    test_request_init();
}