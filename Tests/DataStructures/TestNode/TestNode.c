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
 * TestNode.c
 */

#include "TestNode.h"

#include <stdlib.h>

void test_node_init()
{
    // testing int data allocation and if next node is NULL
    int int_data = 42;
    struct Node *int_node = (struct Node *)malloc(sizeof(struct Node));
    *int_node = node_init(&int_data, sizeof(int));
    ASSERT_TRUE(int_node->data, &int_data, sizeof(int), "Testing if int data is correctly allocated");
    ASSERT_PTR_TRUE(int_node->next, NULL, "Testing if next node is NULL");
    ASSERT_PTR_TRUE(int_node->prev, NULL, "Testing if prev node is NULL");
    node_free(int_node);

    // testing float data allocation
    float float_data = 3.14;
    struct Node *float_node = (struct Node *)malloc(sizeof(struct Node));
    *float_node = node_init(&float_data, sizeof(int));
    ASSERT_TRUE(float_node->data, &float_data, sizeof(int), "Testing if float data is correctly allocated");
    node_free(float_node);
}

void test_node()
{
    TEST_SUITE("Node Tests");
    test_node_init();
}