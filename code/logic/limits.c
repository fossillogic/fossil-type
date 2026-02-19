/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/type/limits.h"
#include <stdint.h>
#include <stddef.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

/* ======================================================
 * Static limits table for all core Fossil types
 * ====================================================== */
static const fossil_type_limits fossil_limits_table[] = {

    /* Signed integers */
    {"i8",  SCHAR_MIN,  SCHAR_MAX, sizeof(int8_t)},
    {"i16", SHRT_MIN,   SHRT_MAX,  sizeof(int16_t)},
    {"i32", INT_MIN,    INT_MAX,   sizeof(int32_t)},
    {"i64", LLONG_MIN,  LLONG_MAX, sizeof(int64_t)},

    /* Unsigned integers */
    {"u8",  0, UCHAR_MAX, sizeof(uint8_t)},
    {"u16", 0, USHRT_MAX, sizeof(uint16_t)},
    {"u32", 0, UINT_MAX,  sizeof(uint32_t)},
    {"u64", 0, ULLONG_MAX,sizeof(uint64_t)},

    /* Hexadecimal (aliases of unsigned) */
    {"h8", 0, UCHAR_MAX, sizeof(uint8_t)},
    {"h16",0, USHRT_MAX, sizeof(uint16_t)},
    {"h32",0, UINT_MAX,  sizeof(uint32_t)},
    {"h64",0, ULLONG_MAX,sizeof(uint64_t)},

    /* Octal (aliases of unsigned) */
    {"o8", 0, UCHAR_MAX, sizeof(uint8_t)},
    {"o16",0, USHRT_MAX, sizeof(uint16_t)},
    {"o32",0, UINT_MAX,  sizeof(uint32_t)},
    {"o64",0, ULLONG_MAX,sizeof(uint64_t)},

    /* Binary (aliases of unsigned) */
    {"b8", 0, UCHAR_MAX, sizeof(uint8_t)},
    {"b16",0, USHRT_MAX, sizeof(uint16_t)},
    {"b32",0, UINT_MAX,  sizeof(uint32_t)},
    {"b64",0, ULLONG_MAX,sizeof(uint64_t)},

    /* Floating */
    {"f32", INT32_MIN, INT32_MAX, sizeof(float)},
    {"f64", INT64_MIN, INT64_MAX, sizeof(double)},

    /* Boolean */
    {"bool", 0, 1, sizeof(bool)},

    /* Tribool */
    {"tribool", 0, 2, sizeof(uint8_t)}, /* 0=false, 1=true, 2=unknown */

    /* Char and cstr */
    {"char", CHAR_MIN, CHAR_MAX, sizeof(char)},
    {"cstr", 0, 0, sizeof(char*)}, /* variable-length string pointer */
};

/* Number of entries */
static const size_t fossil_limits_count =
    sizeof(fossil_limits_table) / sizeof(fossil_limits_table[0]);

/* ======================================================
 * Query function
 * ====================================================== */
const fossil_type_limits* fossil_type_limits_get(const char* type_id) {
    if (!type_id) return NULL;
    for (size_t i = 0; i < fossil_limits_count; i++) {
        if (fossil_limits_table[i].type_id &&
            strcmp(fossil_limits_table[i].type_id, type_id) == 0) {
            return &fossil_limits_table[i];
        }
    }
    return NULL;
}
