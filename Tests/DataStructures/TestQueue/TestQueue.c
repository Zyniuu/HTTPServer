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
 * TestQueue.c
 */

#include "TestQueue.h"

#include <stdlib.h>
#include <string.h>

void test_queue_init()
{
    struct Queue queue = queue_init();

    ASSERT_PTR_FALSE(queue.push, NULL, "Testing if function pointer for push is set");
    ASSERT_PTR_FALSE(queue.peek, NULL, "Testing if function pointer for peek is set");
    ASSERT_PTR_FALSE(queue.pop, NULL, "Testing if function pointer for pop is set");
    ASSERT_PTR_FALSE(queue.linked_list.insert, NULL, "Testing if linked list has been initialized");

    queue_free(&queue);
}

void test_queue_push()
{
    struct Queue queue = queue_init();
    int data1 = 10;
    int data2 = 20;

    queue.push(&queue, &data1, sizeof(int));
    queue.push(&queue, &data2, sizeof(int));

    ASSERT_TRUE(queue.linked_list.head->data, &data1, sizeof(int), "Testing if first value in queue is 10");
    ASSERT_TRUE(queue.linked_list.head->next->data, &data2, sizeof(int), "Testing if second value in queue is 20");

    queue_free(&queue);
}

void test_queue_peek()
{
    struct Queue queue = queue_init();
    char *data1 = "John Doe";

    queue.push(&queue, data1, strlen(data1) + 1);

    ASSERT_TRUE(queue.peek(&queue), data1, strlen(data1) + 1, "Testing if peek returns 'John Doe'");

    queue_free(&queue);
}

void test_queue_pop()
{
    struct Queue queue = queue_init();
    char *data1 = "John Doe";
    char *data2 = "William Doe";
    
    queue.push(&queue, data1, strlen(data1) + 1);
    queue.push(&queue, data2, strlen(data2) + 1);

    ASSERT_TRUE(queue.peek(&queue), data1, strlen(data1) + 1, "Testing if first value before using pop is 'John Doe'");

    queue.pop(&queue);

    ASSERT_TRUE(queue.peek(&queue), data2, strlen(data2) + 1, "Testing if first value after using pop is 'William Doe'");

    queue_free(&queue);
}

void test_queue()
{
    TEST_SUITE("Queue Init Tests");
    test_queue_init();
    TEST_SUITE("Queue Push Tests");
    test_queue_push();
    TEST_SUITE("Queue Peek Tests");
    test_queue_peek();
    TEST_SUITE("Queue Pop Tests");
    test_queue_pop();
}