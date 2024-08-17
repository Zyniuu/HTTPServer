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
 * UnitTests.h
 */

#ifndef UNITTESTS_H
#define UNITTESTS_H

// Global variables for storing tests counters
extern int tests_passed;
extern int tests_failed;

/**
 * Assert if the provided values are equal
 * 
 * @param val1 Void pointer to the first value
 * @param val2 Void pointer to the second value
 * @param size Size of the data to compare
 * @param title Character pointer with the title of the test
 */
void ASSERT_TRUE(void *val1, void *val2, unsigned long size, char *title);

/**
 * Assert if the provided pointers are equal
 * 
 * @param ptr1 First pointer
 * @param ptr2 Second pointer
 * @param title Character pointer with the title of the test
 */
void ASSERT_PTR_TRUE(void *ptr1, void *ptr2, char *title);

/**
 * Assert if the provided values are NOT equal
 * 
 * @param val1 Void pointer to the first value
 * @param val2 Void pointer to the second value
 * @param size Size of the data to compare
 * @param title Character pointer with the title of the test
 */
void ASSERT_FALSE(void *val1, void *val2, unsigned long size, char *title);

/**
 * Assert if the provided pointers are NOT equal
 * 
 * @param ptr1 First pointer
 * @param ptr2 Second pointer
 * @param title Character pointer with the title of the test
 */
void ASSERT_PTR_FALSE(void *ptr1, void *ptr2, char *title);

/**
 * Print out the test register title
 * 
 * @param title The title of the test register
 */
void TEST_REGISTER(char *title);

/**
 * Print out the test suite title
 * 
 * @param title The title of the test suite
 */
void TEST_SUITE(char *title);

#endif // UNITTESTS_H