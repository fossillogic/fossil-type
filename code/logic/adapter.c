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
#include "fossil/type/adapter.h"
#include <string.h>

#ifndef FOSSIL_TYPE_ADAPTER_MAX
#define FOSSIL_TYPE_ADAPTER_MAX 64
#endif

static fossil_type_adapter* g_adapters[FOSSIL_TYPE_ADAPTER_MAX];
static int g_adapter_count = 0;

/* Register */
int fossil_type_adapter_register(fossil_type_adapter* a)
{
    if (!a || !a->name || !a->adapt) return -1;

    /* Prevent duplicates (by name) */
    for (int i = 0; i < g_adapter_count; ++i) {
        if (strcmp(g_adapters[i]->name, a->name) == 0)
            return 0; /* already registered = success */
    }

    if (g_adapter_count >= FOSSIL_TYPE_ADAPTER_MAX)
        return -1;

    g_adapters[g_adapter_count++] = a;
    return 0;
}

/* Apply */
void* fossil_type_adapter_apply(const char* name, void* input)
{
    if (!name) return NULL;

    for (int i = 0; i < g_adapter_count; ++i) {
        fossil_type_adapter* a = g_adapters[i];
        if (a && strcmp(a->name, name) == 0) {
            return a->adapt(input, a->user);
        }
    }

    return NULL;
}
