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
 * TestRemoveSpaces.c
 */

#include "TestRemoveSpaces.h"

#include <string.h>

void test_remove_spaces_no_spaces()
{
    char input[] = "HelloWorld";
    remove_spaces(input, 0, 0);

    ASSERT_TRUE(input, "HelloWorld", strlen("HelloWorld") + 1, "Testing if resulting string is 'HelloWorld'");
}

void test_remove_spaces_start()
{
    char input[] = "   HelloWorld";
    remove_spaces(input, 0, 0);

    ASSERT_TRUE(input, "HelloWorld", strlen("HelloWorld") + 1, "Testing if resulting string is 'HelloWorld'");
}

void test_remove_spaces_end()
{
    char input[] = "HelloWorld   ";
    remove_spaces(input, 0, 0);

    ASSERT_TRUE(input, "HelloWorld", strlen("HelloWorld") + 1, "Testing if resulting string is 'HelloWorld'");
}

void test_remove_spaces_middle()
{
    char input[] = "Hello  World";
    remove_spaces(input, 0, 0);

    ASSERT_TRUE(input, "HelloWorld", strlen("HelloWorld") + 1, "Testing if resulting string is 'HelloWorld'");
}

void test_remove_spaces_only()
{
    char input[] = "              ";
    remove_spaces(input, 0, 0);

    ASSERT_TRUE(input, "", strlen("") + 1, "Testing if resulting string is ''");
}

void test_remove_spaces_mix()
{
    char input[] = "  Hello World ";
    remove_spaces(input, 0, 0);

    ASSERT_TRUE(input, "HelloWorld", strlen("HelloWorld") + 1, "Testing if resulting string is 'HelloWorld'");
}

void test_remove_spaces()
{
    TEST_SUITE("Testing remove_spaces When There Are No Spaces");
    test_remove_spaces_no_spaces();
    TEST_SUITE("Testing remove_spaces When Spaces Are At The Start");
    test_remove_spaces_start();
    TEST_SUITE("Testing remove_spaces When Spaces Are At The End");
    test_remove_spaces_end();
    TEST_SUITE("Testing remove_spaces When Spaces Are In The Middle");
    test_remove_spaces_middle();
    TEST_SUITE("Testing remove_spaces When There Are Only Spaces");
    test_remove_spaces_only();
    TEST_SUITE("Testing remove_spaces When Spaces Are Mixed In");
    test_remove_spaces_mix();
}