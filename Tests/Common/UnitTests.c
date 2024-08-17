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
 * UnitTests.c
 */

#include "UnitTests.h"

#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

int tests_passed = 0;
int tests_failed = 0;

// Helper functions

/**
 * Register a passing assertion
 * 
 * @param title Character pointer with the title of the test 
 */
void ASSERT_PASS(char *title)
{
    tests_passed += 1;

    // for linux
    #ifdef __unix__
    printf("\t\033[32m[PASS]\033[0m\t%s\n", title);
    #endif

    // for windows
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\t[PASS] ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("\t%s\n", title);
    #endif
}

/**
 * Register a failed assertion
 * 
 * @param title Character pointer with the title of the test 
 */
void ASSERT_FAIL(char *title)
{
    tests_failed += 1;

    // for linux
    #ifdef __unix__
    printf("\t\033[31m[FAIL]\033[0m\t%s\n", title);
    #endif

    // for windows
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("\t[FAIL] ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("\t%s\n", title);
    #endif
}

// ----------------

void ASSERT_TRUE(void *val1, void *val2, unsigned long size, char *title)
{
    if (memcmp(val1, val2, size) == 0)
        ASSERT_PASS(title);
    else
        ASSERT_FAIL(title);
}

void ASSERT_PTR_TRUE(void *ptr1, void *ptr2, char *title)
{
    if (ptr1 == ptr2)
        ASSERT_PASS(title);
    else
        ASSERT_FAIL(title);
}

void ASSERT_FALSE(void *val1, void *val2, unsigned long size, char *title)
{
    if (memcmp(val1, val2, size) != 0)
        ASSERT_PASS(title);
    else
        ASSERT_FAIL(title);
}

void ASSERT_PTR_FALSE(void *ptr1, void *ptr2, char *title)
{
    if (ptr1 != ptr2)
        ASSERT_PASS(title);
    else
        ASSERT_FAIL(title);
}

void TEST_REGISTER(char *title)
{
    printf("%s\n", title);
}

void TEST_SUITE(char *title)
{
    printf("\n\t%s\n\n", title);
}