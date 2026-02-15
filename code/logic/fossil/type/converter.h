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
#ifndef FOSSIL_TYPE_CONVERTER_H
#define FOSSIL_TYPE_CONVERTER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------
 * Converter function interface
 * ------------------------------------------------------
 * Use raw data pointer + type ID instead of `any`
 */
typedef int (*fossil_type_converter_fn)(
    const void* input,
    const char* input_type,
    void* output,
    const char* output_type,
    void* user
);

typedef struct fossil_type_converter {
    const char* from_type;
    const char* to_type;
    fossil_type_converter_fn convert;
    void* user;
} fossil_type_converter;

/* Registration */
int fossil_type_converter_register(
    fossil_type_converter* converter);

/* Execution */
int fossil_type_converter_apply(
    const char* from_type,
    const char* to_type,
    const void* input,
    void* output);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Converter {
    fossil_type_converter c;

public:
    Converter(const char* from,
              const char* to,
              fossil_type_converter_fn fn,
              void* user=nullptr)
    {
        c.from_type = from;
        c.to_type   = to;
        c.convert   = fn;
        c.user      = user;
    }

    bool register_converter() {
        return fossil_type_converter_register(&c) == 0;
    }

    int apply(const void* input, void* output) const {
        return fossil_type_converter_apply(c.from_type, c.to_type, input, output);
    }
};

} // namespace fossil::type
#endif

#endif
