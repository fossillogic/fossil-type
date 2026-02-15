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
#ifndef FOSSIL_TYPE_ADAPTER_H
#define FOSSIL_TYPE_ADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*fossil_type_adapter_fn)(void* input, void* user);

typedef struct fossil_type_adapter {
    const char* name;
    fossil_type_adapter_fn adapt;
    void* user;
} fossil_type_adapter;

/* Register */
int fossil_type_adapter_register(fossil_type_adapter* a);

/* Apply */
void* fossil_type_adapter_apply(const char* name, void* input);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Adapter {
    fossil_type_adapter a;
public:
    Adapter(const char* n,fossil_type_adapter_fn fn,void* u=nullptr){
        a.name=n; a.adapt=fn; a.user=u;
    }
    bool register_adapter(){ return fossil_type_adapter_register(&a)==0; }
};

}
#endif

#endif
