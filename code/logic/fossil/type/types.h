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
#ifndef FOSSIL_TYPE_TYPES_H
#define FOSSIL_TYPE_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ======================================================
 * Signed integers
 * ====================================================== */
typedef int8_t   fossil_type_i8;   typedef fossil_type_i8   i8;
typedef int16_t  fossil_type_i16;  typedef fossil_type_i16  i16;
typedef int32_t  fossil_type_i32;  typedef fossil_type_i32  i32;
typedef int64_t  fossil_type_i64;  typedef fossil_type_i64  i64;

/* ======================================================
 * Unsigned integers
 * ====================================================== */
typedef uint8_t  fossil_type_u8;   typedef fossil_type_u8   u8;
typedef uint16_t fossil_type_u16;  typedef fossil_type_u16  u16;
typedef uint32_t fossil_type_u32;  typedef fossil_type_u32  u32;
typedef uint64_t fossil_type_u64;  typedef fossil_type_u64  u64;

/* ======================================================
 * Hexadecimal types (alias for unsigned)
 * ====================================================== */
typedef fossil_type_u8   fossil_type_h8;   typedef fossil_type_h8   h8;
typedef fossil_type_u16  fossil_type_h16;  typedef fossil_type_h16  h16;
typedef fossil_type_u32  fossil_type_h32;  typedef fossil_type_h32  h32;
typedef fossil_type_u64  fossil_type_h64;  typedef fossil_type_h64  h64;

/* ======================================================
 * Octal types (alias for unsigned)
 * ====================================================== */
typedef fossil_type_u8   fossil_type_o8;   typedef fossil_type_o8   o8;
typedef fossil_type_u16  fossil_type_o16;  typedef fossil_type_o16  o16;
typedef fossil_type_u32  fossil_type_o32;  typedef fossil_type_o32  o32;
typedef fossil_type_u64  fossil_type_o64;  typedef fossil_type_o64  o64;

/* ======================================================
 * Binary types (alias for unsigned)
 * ====================================================== */
typedef fossil_type_u8   fossil_type_b8;   typedef fossil_type_b8   b8;
typedef fossil_type_u16  fossil_type_b16;  typedef fossil_type_b16  b16;
typedef fossil_type_u32  fossil_type_b32;  typedef fossil_type_b32  b32;
typedef fossil_type_u64  fossil_type_b64;  typedef fossil_type_b64  b64;

/* ======================================================
 * Floating
 * ====================================================== */
typedef float    fossil_type_f32;  typedef fossil_type_f32  f32;
typedef double   fossil_type_f64;  typedef fossil_type_f64  f64;

/* ======================================================
 * Size
 * ====================================================== */
typedef ptrdiff_t fossil_type_isize; typedef fossil_type_isize isize;
typedef size_t    fossil_type_usize; typedef fossil_type_usize usize;

/* ======================================================
 * Char + strings
 * ====================================================== */
typedef char fossil_type_char; typedef fossil_type_char char_t;
typedef char* fossil_type_cstr; typedef fossil_type_cstr cstr;

/* ======================================================
 * Boolean
 * ====================================================== */
typedef bool fossil_type_bool; typedef fossil_type_bool bool_t;

#ifdef __cplusplus
}
#endif

#endif
