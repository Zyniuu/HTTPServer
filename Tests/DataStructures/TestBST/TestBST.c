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
 * TestBST.c
 */

#include "TestBST.h"

#include <stdlib.h>
#include <string.h>

void test_bst_init()
{
    struct BST tree = bst_init(bst_int_compare);

    ASSERT_PTR_TRUE(tree.head, NULL, "Testing if head pointer is set to NULL");
    ASSERT_PTR_TRUE(tree.compare, bst_int_compare, "Testing if compare function pointer is set correctly");

    bst_free(&tree);
}

void test_bst_insert_search_int()
{
    struct BST tree = bst_init(bst_int_compare);

    int data1 = 10;
    int data2 = 20;
    int data3 = 5;

    tree.insert(&tree, &data1, sizeof(int));
    tree.insert(&tree, &data2, sizeof(int));
    tree.insert(&tree, &data3, sizeof(int));

    ASSERT_TRUE(tree.search(&tree, &data1), &data1, sizeof(int), "Testing if value 10 has been inserted into BST");
    ASSERT_TRUE(tree.search(&tree, &data2), &data2, sizeof(int), "Testing if value 20 has been inserted into BST");
    ASSERT_TRUE(tree.search(&tree, &data3), &data3, sizeof(int), "Testing if value 5 has been inserted into BST");

    bst_free(&tree);
}

void test_bst_insert_search_str()
{
    struct BST tree = bst_init(bst_int_compare);

    char *data1 = "apple";
    char *data2 = "banana";
    char *data3 = "cherry";

    tree.insert(&tree, data1, strlen(data1) + 1);
    tree.insert(&tree, data2, strlen(data2) + 1);
    tree.insert(&tree, data3, strlen(data3) + 1);

    ASSERT_TRUE(tree.search(&tree, data1), data1, strlen(data1) + 1, "Testing if 'apple' has been inserted into BST");
    ASSERT_TRUE(tree.search(&tree, data2), data2, strlen(data2) + 1, "Testing if 'banana' has been inserted into BST");
    ASSERT_TRUE(tree.search(&tree, data3), data3, strlen(data3) + 1, "Testing if 'cherry' has been inserted into BST");

    bst_free(&tree);
}

void test_bst()
{
    TEST_SUITE("BST Init Tests");
    test_bst_init();
    TEST_SUITE("BST Insert & Search For Integer Tests");
    test_bst_insert_search_int();
    TEST_SUITE("BST Insert & Search For String Tests");
    test_bst_insert_search_str();
}