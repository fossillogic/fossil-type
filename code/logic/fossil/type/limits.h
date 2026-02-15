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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct fossil_type_limits {
    const char* type_id;
    long double min_value;
    long double max_value;
    size_t size;
} fossil_type_limits;

/* Query */
const fossil_type_limits*
fossil_type_limits_get(const char* type_id);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Limits {
    const fossil_type_limits* l;
public:
    explicit Limits(const char* id){
        l=fossil_type_limits_get(id);
    }
    long double min() const { return l?l->min_value:0; }
    long double max() const { return l?l->max_value:0; }
    size_t size() const { return l?l->size:0; }
};

}
#endif

#endif
