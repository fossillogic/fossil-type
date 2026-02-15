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
#ifndef FOSSIL_TYPE_INTROSPECTION_H
#define FOSSIL_TYPE_INTROSPECTION_H

#ifdef __cplusplus
extern "C" {
#endif

typedef const char* (*fossil_type_introspect_name_fn)(const void*);
typedef size_t      (*fossil_type_introspect_size_fn)(const void*);

typedef struct fossil_type_introspection {
    const char* type_id;
    fossil_type_introspect_name_fn name;
    fossil_type_introspect_size_fn size;
} fossil_type_introspection;

/* Register */
int fossil_type_introspection_register(
    fossil_type_introspection* info);

/* Query */
const char* fossil_type_introspection_name(const char* type_id);
size_t      fossil_type_introspection_size(const char* type_id);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Introspection {
    fossil_type_introspection i;
public:
    Introspection(const char* id,
                  fossil_type_introspect_name_fn n,
                  fossil_type_introspect_size_fn s){
        i.type_id=id; i.name=n; i.size=s;
    }
    bool register_info(){
        return fossil_type_introspection_register(&i)==0;
    }
};

}
#endif

#endif
