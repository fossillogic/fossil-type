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
#include "fossil/type/attribute.h"
#include <string.h>

#ifndef FOSSIL_TYPE_ATTRIBUTE_TABLE_MAX
#define FOSSIL_TYPE_ATTRIBUTE_TABLE_MAX 64
#endif

static fossil_type_attribute_table* g_tables[FOSSIL_TYPE_ATTRIBUTE_TABLE_MAX];
static size_t g_table_count = 0;

/* ======================================================
 * Registration
 * ====================================================== */
int fossil_type_attributes_register(fossil_type_attribute_table* table)
{
    if (!table || !table->type_id)
        return -1;

    /* prevent duplicate registrations of same type_id */
    for (size_t i = 0; i < g_table_count; ++i) {
        if (strcmp(g_tables[i]->type_id, table->type_id) == 0)
            return 0; /* already registered */
    }

    if (g_table_count >= FOSSIL_TYPE_ATTRIBUTE_TABLE_MAX)
        return -1;

    g_tables[g_table_count++] = table;
    return 0;
}

/* ======================================================
 * Internal lookup helper
 * ====================================================== */
static fossil_type_attribute_table*
fossil_type_attributes_find_table(const char* type_id)
{
    if (!type_id) return NULL;

    for (size_t i = 0; i < g_table_count; ++i) {
        fossil_type_attribute_table* t = g_tables[i];
        if (t && strcmp(t->type_id, type_id) == 0)
            return t;
    }

    return NULL;
}

/* ======================================================
 * Queries
 * ====================================================== */
const attribute*
fossil_type_attributes_get(
    const char* type_id,
    const char* key)
{
    if (!type_id || !key) return NULL;

    fossil_type_attribute_table* t =
        fossil_type_attributes_find_table(type_id);

    if (!t || !t->attributes)
        return NULL;

    for (size_t i = 0; i < t->count; ++i) {
        attribute* a = &t->attributes[i];
        if (a->key && strcmp(a->key, key) == 0)
            return a;
    }

    return NULL;
}

int fossil_type_attributes_has(
    const char* type_id,
    const char* key)
{
    return fossil_type_attributes_get(type_id, key) != NULL;
}
