/* This file is part of dedup.
 *
 * dedup is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dedup is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dedup.  If not, see <https://www.gnu.org/licenses/>.
 *
 * For further information about dedup you can visit
 * http://cdelord.fr/dedup
 */

#include "name_list.h"

#include <stdio.h>

t_name_list name_list;

void name_list_init(void)
{
    name_list.capacity = 16*1024;
    name_list.length = 0;
    name_list.buffer = malloc(name_list.capacity);
    if (name_list.buffer == NULL) {
        fprintf(stderr, "Memory allocation error (too many files)\n");
        exit(EXIT_FAILURE);
    }
}

size_t name_list_new(size_t name_size)
{
    if (name_list.length + name_size + 1 >= name_list.capacity) {
        while (name_list.length + name_size + 1 >= name_list.capacity) {
            name_list.capacity *= 2;
        }
        name_list.buffer = realloc(name_list.buffer, name_list.capacity);
        if (name_list.buffer == NULL) {
            fprintf(stderr, "Memory allocation error (too many files)\n");
            exit(EXIT_FAILURE);
        }
    }
    const size_t name_idx = name_list.length;
    name_list.length += name_size + 1;
    return name_idx;
}

char *name_list_get(size_t name_idx)
{
    return &name_list.buffer[name_idx];
}