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
 * TestLinkedList.c
 */

#include "TestLinkedList.h"

#include <stdlib.h>

void test_linked_list_init()
{
    struct LinkedList linked_list = linked_list_init();

    int len = 0;

    ASSERT_PTR_TRUE(linked_list.head, NULL, "Testing if head is NULL");
    ASSERT_TRUE(&linked_list.length, &len, sizeof(int), "Testing if length is set to 0");
    ASSERT_PTR_FALSE(linked_list.insert, NULL, "Testing if function pointer for insert is set");
    ASSERT_PTR_FALSE(linked_list.remove, NULL, "Testing if function pointer for remove is set");
    ASSERT_PTR_FALSE(linked_list.get, NULL, "Testing if function pointer for get is set");

    linked_list_free(&linked_list);
}

void test_linked_list_insert()
{
    struct LinkedList linked_list = linked_list_init();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int len = 3;

    // insert at head
    linked_list.insert(&linked_list, 0, &data1, sizeof(int));
    // insert at tail
    linked_list.insert(&linked_list, 1, &data2, sizeof(int));
    // insert in the middle
    linked_list.insert(&linked_list, 1, &data3, sizeof(int));

    ASSERT_TRUE(&linked_list.length, &len, sizeof(int), "Testing if length is 3");
    ASSERT_TRUE(linked_list.head->data, &data1, sizeof(int), "Testing if first value is 10");
    ASSERT_TRUE(linked_list.head->next->data, &data3, sizeof(int), "Testing if second value is 30");
    ASSERT_TRUE(linked_list.head->next->next->data, &data2, sizeof(int), "Testing if third value is 20");

    linked_list_free(&linked_list);
}

void test_linked_list_remove()
{
    struct LinkedList linked_list = linked_list_init();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int len = 3;

    linked_list.insert(&linked_list, 0, &data1, sizeof(int));
    linked_list.insert(&linked_list, 1, &data2, sizeof(int));
    linked_list.insert(&linked_list, 2, &data3, sizeof(int));

    // remove the middle element
    linked_list.remove(&linked_list, 1);
    len -= 1;

    ASSERT_TRUE(&linked_list.length, &len, sizeof(int), "Testing if length is 2 after removal");
    ASSERT_TRUE(linked_list.head->next->data, &data3, sizeof(int), "Testing if second element is 30 after removal");

    // remove head element
    linked_list.remove(&linked_list, 0);
    len -= 1;

    ASSERT_TRUE(linked_list.head->data, &data3, sizeof(int), "Testing if head value is 30 after removal");

    // remove head element (list should be empty after this removal)
    linked_list.remove(&linked_list, 0);
    len -= 1;

    ASSERT_TRUE(&linked_list.length, &len, sizeof(int), "Testing if length is 0 after removing all of the elements");
    ASSERT_PTR_TRUE(linked_list.head, NULL, "Testing if head is NULL after removing all of the elements");

    linked_list_free(&linked_list);
}

void test_linked_list_get()
{
    struct LinkedList linked_list = linked_list_init();

    int data1 = 10;
    int data2 = 20;

    linked_list.insert(&linked_list, 0, &data1, sizeof(int));
    linked_list.insert(&linked_list, 1, &data2, sizeof(int));

    ASSERT_TRUE(linked_list.get(&linked_list, 0), &data1, sizeof(int), "Testing if first node returns the value of 10");
    ASSERT_TRUE(linked_list.get(&linked_list, 1), &data2, sizeof(int), "Testing if second node returns the value of 20");
    ASSERT_PTR_TRUE(linked_list.get(&linked_list, -1), NULL, "Testing if index < 0 returns NULL");
    ASSERT_PTR_TRUE(linked_list.get(&linked_list, 2), NULL, "Testing if index >= linked_list.length returns NULL");

    linked_list_free(&linked_list);
}

void test_linked_list()
{
    TEST_SUITE("Linked List Init Tests");
    test_linked_list_init();
    TEST_SUITE("Linked List Insert Tests");
    test_linked_list_insert();
    TEST_SUITE("Linked List Remove Tests");
    test_linked_list_remove();
    TEST_SUITE("Linked List Get Tests");
    test_linked_list_get();
}