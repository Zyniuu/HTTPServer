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
 * TestDictionary.c
 */

#include "TestDictionary.h"

#include <stdlib.h>
#include <string.h>

void test_entry_init()
{
    // tests for integers
    int int_key = 42;
    int int_value = 100;

    struct Entry *int_entry = (struct Entry *)malloc(sizeof(struct Entry));
    *int_entry = entry_init(&int_key, sizeof(int), &int_value, sizeof(int));

    ASSERT_TRUE(int_entry->key, &int_key, sizeof(int), "Testing if key is set to 42");
    ASSERT_TRUE(int_entry->value, &int_value, sizeof(int), "Testing if value is set to 100");

    entry_free(int_entry);

    // tests for strings
    char *str_key = "test_key";
    char *str_value = "test_value";

    struct Entry *str_entry = (struct Entry *)malloc(sizeof(struct Entry));
    *str_entry = entry_init(str_key, strlen(str_key) + 1, str_value, strlen(str_value) + 1);

    ASSERT_TRUE(str_entry->key, str_key, strlen(str_key) + 1, "Testing if key is set to 'test_key'");
    ASSERT_TRUE(str_entry->value, str_value, strlen(str_value) + 1, "Testing if value is set to 'test_value'");

    entry_free(str_entry);
}

void test_dict_init()
{
    struct Dictionary dict = dictionary_init(compare_string_entries);

    ASSERT_PTR_FALSE(dict.insert, NULL, "Testing if pointer function for insert is set");
    ASSERT_PTR_FALSE(dict.search, NULL, "Testing if pointer function for search is set");
    ASSERT_PTR_TRUE(dict.bst.compare, compare_string_entries, "Testing if pointer for compare function is set in bst");

    dictionary_free(&dict);
}

void test_dict_insert()
{
    struct Dictionary dict = dictionary_init(compare_string_entries);
    char *key1 = "name";
    char *value1 = "John";
    char *key2 = "last_name";
    char *value2 = "Doe";

    dict.insert(&dict, key1, strlen(key1) + 1, value1, strlen(value1) + 1);
    dict.insert(&dict, key2, strlen(key2) + 1, value2, strlen(value2) + 1);

    struct Entry *head_entry = (struct Entry *)dict.bst.head->data;
    struct Entry *second_entry = (struct Entry *)dict.bst.head->prev->data;

    ASSERT_TRUE(key1, head_entry->key, strlen(key1) + 1, "Testing if first key is correctly set to 'name'");
    ASSERT_TRUE(value1, head_entry->value, strlen(value1) + 1, "Testing if first value is correctly set to 'John'");

    ASSERT_TRUE(key2, second_entry->key, strlen(key2) + 1, "Testing if second key is correctly set to 'last_name'");
    ASSERT_TRUE(value2, second_entry->value, strlen(value2) + 1, "Testing if first value is correctly set to 'Doe'");

    dictionary_free(&dict);
}

void test_dict_search()
{
    struct Dictionary dict = dictionary_init(compare_string_entries);
    char *key1 = "name";
    char *value1 = "John";
    char *key2 = "last_name";
    char *value2 = "Doe";

    dict.insert(&dict, key1, strlen(key1) + 1, value1, strlen(value1) + 1);
    dict.insert(&dict, key2, strlen(key2) + 1, value2, strlen(value2) + 1);
    
    ASSERT_TRUE((char *)dict.search(&dict, key1, strlen(key1) + 1), value1, strlen(value1) + 1, "Testing if after searching for key 'name' the result is 'John'");
    ASSERT_TRUE((char *)dict.search(&dict, key2, strlen(key2) + 1), value2, strlen(value2) + 1, "Testing if after searching for key 'last_name' the result is 'Doe'");

    dictionary_free(&dict);
}

void test_dictionary()
{
    TEST_SUITE("Entry Init Tests");
    test_entry_init();
    TEST_SUITE("Dictionary Init Tests");
    test_dict_init();
    TEST_SUITE("Dictionary Insert Tests");
    test_dict_insert();
    TEST_SUITE("Dictionary Search Tests");
    test_dict_search();
}