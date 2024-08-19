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
 * TestConfig.c
 */

#include "TestConfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_config_file(char *content)
{
    FILE *file = fopen("Config.ini", "w");
    if (file == NULL)
    {
        printf("Error: could not create Config.txt file\n");
        exit(1);
    }
    fputs(content, file);
    fclose(file);
}

void delete_config_file()
{
    if (remove("Config.ini") != 0)
    {
        printf("Error: could not delete Config.txt file\n");
        exit(1);
    }
}

void test_config_init()
{
    char *config_content = "# Config File\n\nRootUri = /var/www/html # Comment\nAllowedMethods=GET, POST, DELETE\n";
    create_config_file(config_content);
    struct Config config = config_init("Config.ini");
    int len = 3;

    ASSERT_TRUE(config.root_uri, "/var/www/html", strlen("/var/www/html") + 1, "Testing if root_uri is set to '/var/www/html'");
    ASSERT_TRUE(config.allowed_methods.get(&config.allowed_methods, 0), "DELETE", strlen("DELETE") + 1, "Testing if DELETE method has been added");
    ASSERT_TRUE(config.allowed_methods.get(&config.allowed_methods, 1), "POST", strlen("POST") + 1, "Testing if POST method has been added");
    ASSERT_TRUE(config.allowed_methods.get(&config.allowed_methods, 2), "GET", strlen("GET") + 1, "Testing if GET method has been added");
    ASSERT_TRUE(&config.allowed_methods.length, &len, sizeof(int), "Testing if there are 3 elements in linked list");

    delete_config_file();
    config_free(&config);
}

void test_config() 
{
    TEST_SUITE("HTTP Config Init Tests");
    test_config_init();
}