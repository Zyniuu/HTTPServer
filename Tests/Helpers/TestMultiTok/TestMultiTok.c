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
 * TestMultiTok.c
 */

#include "TestMultiTok.h"

#include <stdlib.h>
#include <string.h>

void test_multi_tok_single_char_delim()
{
    // Testing str_multi_tok for delimiters of single character length
    char input[] = "one,two,three";
    char *delimiter = ",";
    char *save_ptr = NULL;

    char *token = str_multi_tok(input, &save_ptr, delimiter);
    ASSERT_TRUE(token, "one", strlen("one") + 1, "Testing if first token is 'one'");
    token = str_multi_tok(NULL, &save_ptr, delimiter);
    ASSERT_TRUE(token, "two", strlen("two") + 1, "Testing if second token is 'two'");
    token = str_multi_tok(NULL, &save_ptr, delimiter);
    ASSERT_TRUE(token, "three", strlen("three") + 1, "Testing if third token is 'three'");
}

void test_multi_tok_empty_delim()
{
    // Testing str_multi_tok for empty delimiter
    char input[] = "one two three";
    char *delimiter = "";
    char *save_ptr = NULL;

    char *token = str_multi_tok(input, &save_ptr, delimiter);
    ASSERT_TRUE(token, input, strlen(input) + 1, "Testing if token is 'one two three'");
}

void test_multi_tok_delim()
{
    // Testing str_multi_tok for delimiters of multiple characters length
    char input[] = "one\r\ntwo\r\nthree";
    char *delimiter = "\r\n";
    char *save_ptr = NULL;

    char *token = str_multi_tok(input, &save_ptr, delimiter);
    ASSERT_TRUE(token, "one", strlen("one") + 1, "Testing if first token is 'one'");
    token = str_multi_tok(NULL, &save_ptr, delimiter);
    ASSERT_TRUE(token, "two", strlen("two") + 1, "Testing if second token is 'two'");
    token = str_multi_tok(NULL, &save_ptr, delimiter);
    ASSERT_TRUE(token, "three", strlen("three") + 1, "Testing if third token is 'three'");
}

void test_multi_tok()
{
    TEST_SUITE("Tests str_multi_tok For Single Character Delimiter");
    test_multi_tok_single_char_delim();
    TEST_SUITE("Tests str_multi_tok For Empty Delimiter");
    test_multi_tok_empty_delim();
    TEST_SUITE("Tests str_multi_tok For Multiple Characters Delimiter");
    test_multi_tok_delim();
}