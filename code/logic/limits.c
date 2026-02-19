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
#include <string.h>

/* ======================================================
 * Fossil canonical numeric limits (macro form)
 * ====================================================== */

/* ======================================================
 * Fossil Canonical Numeric Limits
 * Frozen ABI-safe constants for storage + hashing
 * ====================================================== */

/* ---------------- Signed integers ---------------- */

#define FOSSIL_I8_MIN    (-128)
#define FOSSIL_I8_MAX    127

#define FOSSIL_I16_MIN   (-32768)
#define FOSSIL_I16_MAX   32767

#define FOSSIL_I32_MIN   (-2147483647 - 1)
#define FOSSIL_I32_MAX   2147483647

#define FOSSIL_I64_MIN   (-9223372036854775807LL - 1)
#define FOSSIL_I64_MAX   9223372036854775807LL


/* ---------------- Unsigned integers ---------------- */

#define FOSSIL_U8_MIN    0u
#define FOSSIL_U8_MAX    0xFFu

#define FOSSIL_U16_MIN   0u
#define FOSSIL_U16_MAX   0xFFFFu

#define FOSSIL_U32_MIN   0u
#define FOSSIL_U32_MAX   0xFFFFFFFFu

#define FOSSIL_U64_MIN   0ull
#define FOSSIL_U64_MAX   0xFFFFFFFFFFFFFFFFull


/* ---------------- Floating point (IEEE-754) ---------------- */
/* These reflect bit-representation ranges, not decimal limits */

#define FOSSIL_F32_BITS_MIN   FOSSIL_I32_MIN
#define FOSSIL_F32_BITS_MAX   FOSSIL_I32_MAX

#define FOSSIL_F64_BITS_MIN   FOSSIL_I64_MIN
#define FOSSIL_F64_BITS_MAX   FOSSIL_I64_MAX


/* Optional real-number semantic limits (IEEE-754) */

#define FOSSIL_F32_MAX        3.402823466e+38F
#define FOSSIL_F32_MIN_POS    1.175494351e-38F

#define FOSSIL_F64_MAX        1.7976931348623157e+308
#define FOSSIL_F64_MIN_POS    2.2250738585072014e-308


/* ---------------- Boolean ---------------- */

#define FOSSIL_BOOL_MIN   0
#define FOSSIL_BOOL_MAX   1


/* ---------------- Tribool ---------------- */
/* 0=false, 1=true, 2=unknown */

#define FOSSIL_TRIBOOL_MIN 0
#define FOSSIL_TRIBOOL_MAX 2


/* ---------------- Character ---------------- */
/* Fossil assumes 8-bit char storage */

#define FOSSIL_CHAR_MIN   (-128)
#define FOSSIL_CHAR_MAX   127

#define FOSSIL_UCHAR_MIN  0
#define FOSSIL_UCHAR_MAX  255


/* ---------------- Pointer-like / variable types ---------------- */

#define FOSSIL_CSTR_MIN   0
#define FOSSIL_CSTR_MAX   0   /* variable-length, no fixed bound */

/* ======================================================
 * Fossil ABI / Platform Validation
 * Must compile or Fossil storage is unsafe
 * ====================================================== */

/* ---------- Integer size guarantees ---------- */

_Static_assert(sizeof(int8_t)  == 1, "Fossil requires 8-bit int8_t");
_Static_assert(sizeof(int16_t) == 2, "Fossil requires 16-bit int16_t");
_Static_assert(sizeof(int32_t) == 4, "Fossil requires 32-bit int32_t");
_Static_assert(sizeof(int64_t) == 8, "Fossil requires 64-bit int64_t");

_Static_assert(sizeof(uint8_t)  == 1, "Fossil requires 8-bit uint8_t");
_Static_assert(sizeof(uint16_t) == 2, "Fossil requires 16-bit uint16_t");
_Static_assert(sizeof(uint32_t) == 4, "Fossil requires 32-bit uint32_t");
_Static_assert(sizeof(uint64_t) == 8, "Fossil requires 64-bit uint64_t");


/* ---------- Signed integer range guarantees ---------- */

_Static_assert(INT8_MIN  == FOSSIL_I8_MIN,  "Host i8 min mismatch");
_Static_assert(INT8_MAX  == FOSSIL_I8_MAX,  "Host i8 max mismatch");

_Static_assert(INT16_MIN == FOSSIL_I16_MIN, "Host i16 min mismatch");
_Static_assert(INT16_MAX == FOSSIL_I16_MAX, "Host i16 max mismatch");

_Static_assert(INT32_MIN == FOSSIL_I32_MIN, "Host i32 min mismatch");
_Static_assert(INT32_MAX == FOSSIL_I32_MAX, "Host i32 max mismatch");

_Static_assert(INT64_MIN == FOSSIL_I64_MIN, "Host i64 min mismatch");
_Static_assert(INT64_MAX == FOSSIL_I64_MAX, "Host i64 max mismatch");


/* ---------- Unsigned integer range guarantees ---------- */

_Static_assert(UINT8_MAX  == FOSSIL_U8_MAX,  "Host u8 max mismatch");
_Static_assert(UINT16_MAX == FOSSIL_U16_MAX, "Host u16 max mismatch");
_Static_assert(UINT32_MAX == FOSSIL_U32_MAX, "Host u32 max mismatch");
_Static_assert(UINT64_MAX == FOSSIL_U64_MAX, "Host u64 max mismatch");


/* ---------- Character guarantees ---------- */

_Static_assert(CHAR_BIT == 8, "Fossil requires 8-bit bytes");

/* signed char must be two’s complement */
_Static_assert(SCHAR_MIN == -128, "Fossil requires signed 8-bit char");
_Static_assert(SCHAR_MAX == 127,  "Fossil requires signed 8-bit char");


/* ---------- Floating-point guarantees ---------- */
/* Fossil assumes IEEE-754 floats */

_Static_assert(sizeof(float)  == 4, "Fossil requires IEEE-754 32-bit float");
_Static_assert(sizeof(double) == 8, "Fossil requires IEEE-754 64-bit double");

/* radix must be binary */
_Static_assert(FLT_RADIX == 2, "Fossil requires binary floating point");

/* mantissa bits check (IEEE-754) */
_Static_assert(FLT_MANT_DIG == 24, "Non IEEE float detected");
_Static_assert(DBL_MANT_DIG == 53, "Non IEEE double detected");


/* ---------- Boolean guarantees ---------- */

_Static_assert(sizeof(bool) == 1, "Fossil requires 1-byte bool");


/* ======================================================
 * If this file compiles, Fossil ABI is safe on this host
 * ====================================================== */

/* ======================================================
 * Static limits table for all core Fossil types
 * ====================================================== */
static const fossil_type_limits fossil_limits_table[] = {

    /* Signed integers */
    {"i8",  FOSSIL_I8_MIN,  FOSSIL_I8_MAX,  sizeof(int8_t)},
    {"i16", FOSSIL_I16_MIN, FOSSIL_I16_MAX, sizeof(int16_t)},
    {"i32", FOSSIL_I32_MIN, FOSSIL_I32_MAX, sizeof(int32_t)},
    {"i64", FOSSIL_I64_MIN, FOSSIL_I64_MAX, sizeof(int64_t)},

    /* Unsigned integers */
    {"u8", 0, FOSSIL_U8_MAX, sizeof(uint8_t)},
    {"u16",0, FOSSIL_U16_MAX,sizeof(uint16_t)},
    {"u32",0, FOSSIL_U32_MAX,sizeof(uint32_t)},
    {"u64",0, FOSSIL_U64_MAX,sizeof(uint64_t)},

    /* Hex aliases */
    {"h8",  0, FOSSIL_U8_MAX,  sizeof(uint8_t)},
    {"h16", 0, FOSSIL_U16_MAX, sizeof(uint16_t)},
    {"h32", 0, FOSSIL_U32_MAX, sizeof(uint32_t)},
    {"h64", 0, FOSSIL_U64_MAX, sizeof(uint64_t)},

    /* Octal aliases */
    {"o8",  0, FOSSIL_U8_MAX,  sizeof(uint8_t)},
    {"o16", 0, FOSSIL_U16_MAX, sizeof(uint16_t)},
    {"o32", 0, FOSSIL_U32_MAX, sizeof(uint32_t)},
    {"o64", 0, FOSSIL_U64_MAX, sizeof(uint64_t)},

    /* Binary aliases */
    {"b8",  0, FOSSIL_U8_MAX,  sizeof(uint8_t)},
    {"b16", 0, FOSSIL_U16_MAX, sizeof(uint16_t)},
    {"b32", 0, FOSSIL_U32_MAX, sizeof(uint32_t)},
    {"b64", 0, FOSSIL_U64_MAX, sizeof(uint64_t)},

    /* Floating ranges represented via integer storage model */
    {"f32", FOSSIL_I32_MIN, FOSSIL_I32_MAX, sizeof(float)},
    {"f64", FOSSIL_I64_MIN, FOSSIL_I64_MAX, sizeof(double)},

    /* Boolean */
    {"bool", 0, 1, sizeof(bool)},

    /* Tribool */
    {"tribool", 0, 2, sizeof(uint8_t)},

    /* Char and cstr */
    {"char", CHAR_MIN, CHAR_MAX, sizeof(char)},
    {"cstr", 0, 0, sizeof(char*)},
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
