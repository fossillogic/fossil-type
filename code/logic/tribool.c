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
 * Date: 04/05/2013
 *
 * Copyright (C) 2013-Current Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/type/tribool.h"

/* ======================================================
 * Constructors
 * ====================================================== */
tribool fossil_type_tribool_make_true(void) {
    return FOSSIL_TYPE_TRIBOOL_TRUE;
}

tribool fossil_type_tribool_make_false(void) {
    return FOSSIL_TYPE_TRIBOOL_FALSE;
}

tribool fossil_type_tribool_make_unknown(void) {
    return FOSSIL_TYPE_TRIBOOL_UNKNOWN;
}

/* ======================================================
 * Predicates
 * ====================================================== */
int fossil_type_tribool_is_true(tribool t) {
    return t == FOSSIL_TYPE_TRIBOOL_TRUE;
}

int fossil_type_tribool_is_false(tribool t) {
    return t == FOSSIL_TYPE_TRIBOOL_FALSE;
}

int fossil_type_tribool_is_unknown(tribool t) {
    return t == FOSSIL_TYPE_TRIBOOL_UNKNOWN;
}

/* ======================================================
 * Logic operations
 * ====================================================== */

/*
 * Truth table for AND:
 * FALSE & X = FALSE
 * TRUE & TRUE = TRUE
 * TRUE & UNKNOWN = UNKNOWN
 * UNKNOWN & UNKNOWN = UNKNOWN
 */
tribool fossil_type_tribool_and(tribool a, tribool b) {
    if (a == FOSSIL_TYPE_TRIBOOL_FALSE || b == FOSSIL_TYPE_TRIBOOL_FALSE)
        return FOSSIL_TYPE_TRIBOOL_FALSE;
    if (a == FOSSIL_TYPE_TRIBOOL_UNKNOWN || b == FOSSIL_TYPE_TRIBOOL_UNKNOWN)
        return FOSSIL_TYPE_TRIBOOL_UNKNOWN;
    return FOSSIL_TYPE_TRIBOOL_TRUE;
}

/*
 * Truth table for OR:
 * TRUE | X = TRUE
 * FALSE | FALSE = FALSE
 * FALSE | UNKNOWN = UNKNOWN
 * UNKNOWN | UNKNOWN = UNKNOWN
 */
tribool fossil_type_tribool_or(tribool a, tribool b) {
    if (a == FOSSIL_TYPE_TRIBOOL_TRUE || b == FOSSIL_TYPE_TRIBOOL_TRUE)
        return FOSSIL_TYPE_TRIBOOL_TRUE;
    if (a == FOSSIL_TYPE_TRIBOOL_UNKNOWN || b == FOSSIL_TYPE_TRIBOOL_UNKNOWN)
        return FOSSIL_TYPE_TRIBOOL_UNKNOWN;
    return FOSSIL_TYPE_TRIBOOL_FALSE;
}

/*
 * NOT operation:
 * NOT TRUE = FALSE
 * NOT FALSE = TRUE
 * NOT UNKNOWN = UNKNOWN
 */
tribool fossil_type_tribool_not(tribool t) {
    switch (t) {
        case FOSSIL_TYPE_TRIBOOL_TRUE:    return FOSSIL_TYPE_TRIBOOL_FALSE;
        case FOSSIL_TYPE_TRIBOOL_FALSE:   return FOSSIL_TYPE_TRIBOOL_TRUE;
        case FOSSIL_TYPE_TRIBOOL_UNKNOWN: return FOSSIL_TYPE_TRIBOOL_UNKNOWN;
        default: return FOSSIL_TYPE_TRIBOOL_UNKNOWN;
    }
}
