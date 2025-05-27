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

/* https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function */

#include <stdlib.h>

constexpr size_t hash_size = 128;
typedef unsigned _BitInt(hash_size) t_hash;

constexpr t_hash FNV_OFFSET_BASIS = ((t_hash)0x6c62272e07bb0142ULL << 64) | 0x62b821756295c58dULL;
constexpr t_hash FNV_PRIME        = ((t_hash)0x0000000001000000ULL << 64) | 0x000000000000013bULL;

static inline void fnv1a_init(t_hash *hash)
{
    *hash = FNV_OFFSET_BASIS;
}

static inline void fnv1a_update(t_hash *hash, const unsigned char *data, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        *hash = (*hash ^ (t_hash)data[i]) * FNV_PRIME;
    }
}

static inline int fnv1a_compare(t_hash hash1, t_hash hash2)
{
    if (hash2 > hash1) { return 1; }
    if (hash2 < hash1) { return -1; }
    return 0;
}
