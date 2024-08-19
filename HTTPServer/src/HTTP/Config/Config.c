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
 * Config.c
 */

#include "Config.h"
#include "../../DataStructures/NonLinear/Dictionary/Dictionary.h"
#include "../../Helpers/Helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper function to parse a single line from the configuration file and insert
 * the extracted key-value pair into the provided dictionary.
 *
 * @param line The line from the configuration file to be parsed.
 * @param dict Pointer to the dictionary where the key-value pair will be inserted.
 * @param save_ptr Pointer to a char* that stores the position in the string between calls.
 */
void parse_line(char *line, struct Dictionary *dict, char *save_ptr);

struct Config config_init(char *config_filename)
{
    struct Config config;
    config.allowed_methods = linked_list_init();
    // Open the configuration file for reading
    FILE *config_file = fopen(config_filename, "r");
    if (config_file == NULL)
    {
        printf("Error: could not open config file. Make sure the file 'Config.ini' is in the same directory as an executable.\n");
        exit(1);
    }
    // Initialize a dictionary to store key-value pairs from the config file
    struct Dictionary dict = dictionary_init(compare_string_entries);
    unsigned max_len = 256;
    char buffer[max_len];
    char *save_ptr;
    // Read each line from the configuration file
    while (fgets(buffer, max_len, config_file))
    {
        // Remove any spaces from the line
        remove_spaces(buffer, 0, 0);
        // Skip comments and empty lines
        if (buffer[0] == '#' || buffer[0] == '\n')
            continue;
        // Strip comments at the end of the line
        char *line = str_multi_tok(buffer, &save_ptr, "#");
        parse_line(line, &dict, save_ptr);
    }
    // Close the configuration file
    fclose(config_file);
    // Retrieve the RootUri value from the dictionary and print an error msg if not specified
    char *uri = (char *)dict.search(&dict, "RootUri", strlen("RootUri") + 1);
    if (uri == NULL || strlen(uri) < 1)
    {
        printf("Error: RootUri was not specified in Config.ini file.\n");
        exit(1);
    }
    config.root_uri = malloc(strlen(uri) + 1);
    if (!config.root_uri)
    {
        printf("Error: Failed to allocate memory for root_uri.\n");
        exit(1);
    }
    strcpy(config.root_uri, uri);
    // Retrieve the AllowedMethods value from the dictionary and print an error msg if not specified
    char *methods_list = dict.search(&dict, "AllowedMethods", strlen("AllowedMethods") + 1);
    if (methods_list == NULL || strlen(methods_list) < 1)
    {
        printf("Error: AllowedMethods field was not specified in Config.ini file\n");
        exit(1);
    }
    // Copy the methods list and tokenize it to extract individual methods
    char methods_list_copy[strlen(methods_list) + 1];
    strcpy(methods_list_copy, methods_list);
    // Initialize the allowed_methods linked list
    char *method = (char *)str_multi_tok(methods_list_copy, &save_ptr, ",");
    while (method)
    {
        // Insert each method into the allowed_methods linked list
        config.allowed_methods.insert(&config.allowed_methods, 0, method, strlen(method) + 1);
        method = (char *)str_multi_tok(NULL, &save_ptr, ",");
    }
    // Free the dictionary now that we're done using it
    dictionary_free(&dict);
    return config;
}

void config_free(struct Config *config)
{
    if (config->root_uri)
        free(config->root_uri);
    linked_list_free(&config->allowed_methods);
}

void parse_line(char *line, struct Dictionary *dict, char *save_ptr)
{
    char line_copy[strlen(line) + 1];
    strcpy(line_copy, line);
    // Split the line into key and value parts
    char *key = str_multi_tok(line_copy, &save_ptr, "=");
    char *val = str_multi_tok(NULL, &save_ptr, "\n");
    // Insert the key-value pair into the dictionary
    dict->insert(dict, key, strlen(key) + 1, val, strlen(val) + 1);
}