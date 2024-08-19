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
 * Config.h
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "../../DataStructures/Linear/LinkedList/LinkedList.h"

// Structure representing the configuration settings loaded from a configuration file
struct Config
{
    char *root_uri;
    struct LinkedList allowed_methods;
};

/**
 * Function to initialize a Config structure by loading settings from a configuration file
 * 
 * @param config_filename The name of the configuration file to load
 * 
 * @return A Config structure with the loaded settings
 */
struct Config config_init(char *config_filename);

/**
 * Function to free all resources associated with a Config structure
 * 
 * @param config Pointer to the Config structure to be freed
 */
void config_free(struct Config *config);

#endif // CONFIG_H