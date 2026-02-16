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
 * Fixed-width signed numeric primitives
 *
 * Example:
 *     i32 count = -42;
 *     i64 big   = 9000000000;
 * ====================================================== */
typedef int8_t   fossil_type_i8;   typedef fossil_type_i8   i8;
typedef int16_t  fossil_type_i16;  typedef fossil_type_i16  i16;
typedef int32_t  fossil_type_i32;  typedef fossil_type_i32  i32;
typedef int64_t  fossil_type_i64;  typedef fossil_type_i64  i64;


/* ======================================================
 * Unsigned integers
 * Fixed-width unsigned numeric primitives
 *
 * Example:
 *     u32 flags = 0xFF00FF00;
 *     u8  byte  = 255;
 * ====================================================== */
typedef uint8_t  fossil_type_u8;   typedef fossil_type_u8   u8;
typedef uint16_t fossil_type_u16;  typedef fossil_type_u16  u16;
typedef uint32_t fossil_type_u32;  typedef fossil_type_u32  u32;
typedef uint64_t fossil_type_u64;  typedef fossil_type_u64  u64;


/* ======================================================
 * Hexadecimal aliases
 * Semantic alias for unsigned integers used as hex values
 *
 * Example:
 *     h32 color = 0xFFAA33CC;
 * ====================================================== */
typedef fossil_type_u8   fossil_type_h8;   typedef fossil_type_h8   h8;
typedef fossil_type_u16  fossil_type_h16;  typedef fossil_type_h16  h16;
typedef fossil_type_u32  fossil_type_h32;  typedef fossil_type_h32  h32;
typedef fossil_type_u64  fossil_type_h64;  typedef fossil_type_h64  h64;


/* ======================================================
 * Octal aliases
 * Semantic alias for unsigned integers used as octal values
 *
 * Example:
 *     o16 perms = 0755;
 * ====================================================== */
typedef fossil_type_u8   fossil_type_o8;   typedef fossil_type_o8   o8;
typedef fossil_type_u16  fossil_type_o16;  typedef fossil_type_o16  o16;
typedef fossil_type_u32  fossil_type_o32;  typedef fossil_type_o32  o32;
typedef fossil_type_u64  fossil_type_o64;  typedef fossil_type_o64  o64;


/* ======================================================
 * Binary aliases
 * Semantic alias for unsigned integers used as bitfields
 *
 * Example:
 *     b8 mask = 0b10101010;
 * ====================================================== */
typedef fossil_type_u8   fossil_type_b8;   typedef fossil_type_b8   b8;
typedef fossil_type_u16  fossil_type_b16;  typedef fossil_type_b16  b16;
typedef fossil_type_u32  fossil_type_b32;  typedef fossil_type_b32  b32;
typedef fossil_type_u64  fossil_type_b64;  typedef fossil_type_b64  b64;


/* ======================================================
 * Floating point
 * IEEE floating precision primitives
 *
 * Example:
 *     f32 ratio = 0.75f;
 *     f64 pi    = 3.141592653589793;
 * ====================================================== */
typedef float    fossil_type_f32;  typedef fossil_type_f32  f32;
typedef double   fossil_type_f64;  typedef fossil_type_f64  f64;


/* ======================================================
 * Size types
 * Platform-sized signed/unsigned pointer-sized integers
 *
 * Example:
 *     usize len = buffer_length;
 *     isize diff = end - start;
 * ====================================================== */
typedef ptrdiff_t fossil_type_isize; typedef fossil_type_isize isize;
typedef size_t    fossil_type_usize; typedef fossil_type_usize usize;


/* ======================================================
 * Character + string
 * Basic textual primitives
 *
 * Example:
 *     char_t letter = 'A';
 *     cstr message  = "hello fossil";
 * ====================================================== */
typedef char fossil_type_char; typedef fossil_type_char char_t;
typedef char* fossil_type_cstr; typedef fossil_type_cstr cstr;


/* ======================================================
 * Pointer semantics
 * Generic runtime pointers and references
 *
 * ptr    : mutable pointer
 * cptr   : immutable pointer
 *
 * Example:
 *     ptr  mem = malloc(64);
 *     cptr view = mem;
 * ====================================================== */
typedef void*       fossil_type_ptr;    typedef fossil_type_ptr    ptr;
typedef const void* fossil_type_cptr;   typedef fossil_type_cptr   cptr;


/* ======================================================
 * Ownership-aware handles
 *
 * handle : resource ownership token
 * ref    : non-owning reference
 *
 * Example:
 *     handle file = open_resource(...);
 *     ref    view = file;
 * ====================================================== */
typedef void* fossil_type_handle;       typedef fossil_type_handle handle;
typedef void* fossil_type_ref;          typedef fossil_type_ref    ref;


/* ======================================================
 * Atom
 * Canonical immutable identity value
 * Intended for interning, symbol tables, metadata keys
 *
 * Example:
 *     atom id = fossil_intern("user_id");
 *     if(id == other_id) { /* pointer equality */ }
 * ====================================================== */
typedef const void* fossil_type_atom;   typedef fossil_type_atom atom;


/* ======================================================
 * Type identifiers
 *
 * type_id : canonical runtime type name
 * symbol  : general symbolic identifier
 *
 * Example:
 *     type_id t = "i32";
 *     symbol key = "max_value";
 * ====================================================== */
typedef const char* fossil_type_id; typedef fossil_type_id type_id;
typedef const char* fossil_type_symbol; typedef fossil_type_symbol symbol;


/* ======================================================
 * Flags bitfield
 * Generic 64-bit flag container
 *
 * Example:
 *     flags opts = (1ULL << 0) | (1ULL << 3);
 * ====================================================== */
typedef uint64_t fossil_type_flags; typedef fossil_type_flags flags;


/* ======================================================
 * Node identity
 * Stable graph or DAG identifier
 *
 * Example:
 *     node_id n = 42;
 * ====================================================== */
typedef uint64_t fossil_type_node_id;
typedef fossil_type_node_id node_id;


/* ======================================================
 * Entropy / information metric
 * Useful for AI metrics, uncertainty, and scoring
 *
 * Example:
 *     entropy e = 0.73;
 * ====================================================== */
typedef double fossil_type_entropy;
typedef fossil_type_entropy entropy;


#ifdef __cplusplus
}
#endif

#endif
