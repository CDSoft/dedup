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

#pragma once

#include <fnmatch.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    bool skip_hidden;
    bool safe;
    char **ignore_patterns;
    size_t nb_ignore_patterns;
} t_opts;

extern t_opts opts;

void help(void);
void read_conf(void);
bool ignored(const char *path);