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
#ifndef FOSSIL_TYPE_LIMITS_H
#define FOSSIL_TYPE_LIMITS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct fossil_type_limits {
    const char* type_id;
    long double min_value;
    long double max_value;
    size_t size;
} fossil_type_limits;

/**
 * @brief Retrieves the limits for the specified type ID.
 *
 * Available type IDs:
 *   - Signed integers:   "i8", "i16", "i32", "i64"
 *   - Unsigned integers: "u8", "u16", "u32", "u64"
 *   - Hexadecimal:       "h8", "h16", "h32", "h64"
 *   - Octal:             "o8", "o16", "o32", "o64"
 *   - Binary:            "b8", "b16", "b32", "b64"
 *   - Floating point:    "f32", "f64"
 *   - Boolean:           "bool"
 *   - Tribool:           "tribool"
 *   - Character:         "char"
 *   - C string:          "cstr"
 *
 * @param type_id The identifier of the type to retrieve limits for.
 * @return A pointer to a fossil_type_limits struct containing the limits for the type,
 *         or NULL if the type ID is not recognized.
 */
const fossil_type_limits *fossil_type_limits_get(const char* type_id);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Limits {
    const fossil_type_limits* l;
public:
    /**
     * @brief Constructs a new Limits object for the specified type ID.
     *
     * @param id The identifier of the type to retrieve limits for.
     */
    explicit Limits(const char* id){
        l=fossil_type_limits_get(id);
    }

    /**
     * @brief Checks if the limits were successfully retrieved for the type.
     *
     * @return true if limits are available, false otherwise.
     */
    long double min() const { return l?l->min_value:0; }

    /**
     * @brief Retrieves the maximum value for the type.
     *
     * @return The maximum value if limits are available, or 0 if not.
     */
    long double max() const { return l?l->max_value:0; }

    /**
     * @brief Retrieves the size in bytes for the type.
     *
     * @return The size in bytes if limits are available, or 0 if not.
     */
    size_t size() const { return l?l->size:0; }
};

}
#endif

#endif
