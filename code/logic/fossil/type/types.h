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
extern "C"
{
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
typedef int8_t fossil_type_i8;
typedef fossil_type_i8 i8;
typedef int16_t fossil_type_i16;
typedef fossil_type_i16 i16;
typedef int32_t fossil_type_i32;
typedef fossil_type_i32 i32;
typedef int64_t fossil_type_i64;
typedef fossil_type_i64 i64;

/* ======================================================
    * Unsigned integers
    * Fixed-width unsigned numeric primitives
    *
    * Example:
    *     u32 flags = 0xFF00FF00;
    *     u8  byte  = 255;
    * ====================================================== */
typedef uint8_t fossil_type_u8;
typedef fossil_type_u8 u8;
typedef uint16_t fossil_type_u16;
typedef fossil_type_u16 u16;
typedef uint32_t fossil_type_u32;
typedef fossil_type_u32 u32;
typedef uint64_t fossil_type_u64;
typedef fossil_type_u64 u64;

/* ======================================================
    * Hexadecimal aliases
    * Semantic alias for unsigned integers used as hex values
    *
    * Example:
    *     h32 color = 0xFFAA33CC;
    * ====================================================== */
typedef fossil_type_u8 fossil_type_h8;
typedef fossil_type_h8 h8;
typedef fossil_type_u16 fossil_type_h16;
typedef fossil_type_h16 h16;
typedef fossil_type_u32 fossil_type_h32;
typedef fossil_type_h32 h32;
typedef fossil_type_u64 fossil_type_h64;
typedef fossil_type_h64 h64;

/* ======================================================
    * Octal aliases
    * Semantic alias for unsigned integers used as octal values
    *
    * Example:
    *     o16 perms = 0755;
    * ====================================================== */
typedef fossil_type_u8 fossil_type_o8;
typedef fossil_type_o8 o8;
typedef fossil_type_u16 fossil_type_o16;
typedef fossil_type_o16 o16;
typedef fossil_type_u32 fossil_type_o32;
typedef fossil_type_o32 o32;
typedef fossil_type_u64 fossil_type_o64;
typedef fossil_type_o64 o64;

/* ======================================================
    * Binary aliases
    * Semantic alias for unsigned integers used as bitfields
    *
    * Example:
    *     b8 mask = 0b10101010;
    * ====================================================== */
typedef fossil_type_u8 fossil_type_b8;
typedef fossil_type_b8 b8;
typedef fossil_type_u16 fossil_type_b16;
typedef fossil_type_b16 b16;
typedef fossil_type_u32 fossil_type_b32;
typedef fossil_type_b32 b32;
typedef fossil_type_u64 fossil_type_b64;
typedef fossil_type_b64 b64;

/* ======================================================
    * Floating point
    * IEEE floating precision primitives
    *
    * Example:
    *     f32 ratio = 0.75f;
    *     f64 pi    = 3.141592653589793;
    * ====================================================== */
typedef float fossil_type_f32;
typedef fossil_type_f32 f32;
typedef double fossil_type_f64;
typedef fossil_type_f64 f64;

/* ======================================================
    * Size types
    * Platform-sized signed/unsigned pointer-sized integers
    *
    * Example:
    *     usize len = buffer_length;
    *     isize diff = end - start;
    * ====================================================== */
typedef ptrdiff_t fossil_type_isize;
typedef fossil_type_isize isize;
typedef size_t fossil_type_usize;
typedef fossil_type_usize usize;

/* ======================================================
    * Character + string
    * Basic textual primitives
    *
    * Example:
    *     char_t letter = 'A';
    *     cstr message  = "hello fossil";
    * ====================================================== */
typedef char fossil_type_char;
typedef fossil_type_char char_t;
typedef char *fossil_type_cstr;
typedef fossil_type_cstr cstr;

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
typedef void *fossil_type_ptr;
typedef fossil_type_ptr ptr;
typedef const void *fossil_type_cptr;
typedef fossil_type_cptr cptr;

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
typedef void *fossil_type_handle;
typedef fossil_type_handle handle;
typedef void *fossil_type_ref;
typedef fossil_type_ref ref;

/* ======================================================
    * Atom
    * Canonical immutable identity value
    * Intended for interning, symbol tables, metadata keys
    *
    * Example:
    *     atom id = fossil_intern("user_id");
    *     if(id == other_id) { /* pointer equality / }
    * ====================================================== */
typedef const void *fossil_type_atom;
typedef fossil_type_atom atom;

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
typedef const char *fossil_type_id;
typedef fossil_type_id type_id;
typedef const char *fossil_type_symbol;
typedef fossil_type_symbol symbol;

/* ======================================================
    * Flags bitfield
    * Generic 64-bit flag container
    *
    * Example:
    *     flags opts = (1ULL << 0) | (1ULL << 3);
    * ====================================================== */
typedef uint64_t fossil_type_flags;
typedef fossil_type_flags flags;

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

namespace fossil::type
{

    // Signed integer types
    class I8
    {
    public:
        int8_t value;
        /** Construct from int8_t value (default 0) */
        explicit I8(int8_t v = 0) : value(v) {}
        /** Implicit conversion to int8_t */
        operator int8_t() const { return value; }
        /** Assign from int8_t */
        I8 &operator=(int8_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const I8 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const I8 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const I8 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const I8 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const I8 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const I8 &other) const { return value >= other.value; }
        /** Addition operator */
        I8 operator+(const I8 &other) const { return I8(value + other.value); }
        /** Subtraction operator */
        I8 operator-(const I8 &other) const { return I8(value - other.value); }
        /** Multiplication operator */
        I8 operator*(const I8 &other) const { return I8(value * other.value); }
        /** Division operator */
        I8 operator/(const I8 &other) const { return I8(value / other.value); }
        /** Compound addition assignment */
        I8 &operator+=(const I8 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        I8 &operator-=(const I8 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        I8 &operator*=(const I8 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        I8 &operator/=(const I8 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class I16
    {
    public:
        int16_t value;
        /** Construct from int16_t value (default 0) */
        explicit I16(int16_t v = 0) : value(v) {}
        /** Implicit conversion to int16_t */
        operator int16_t() const { return value; }
        /** Assign from int16_t */
        I16 &operator=(int16_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const I16 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const I16 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const I16 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const I16 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const I16 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const I16 &other) const { return value >= other.value; }
        /** Addition operator */
        I16 operator+(const I16 &other) const { return I16(value + other.value); }
        /** Subtraction operator */
        I16 operator-(const I16 &other) const { return I16(value - other.value); }
        /** Multiplication operator */
        I16 operator*(const I16 &other) const { return I16(value * other.value); }
        /** Division operator */
        I16 operator/(const I16 &other) const { return I16(value / other.value); }
        /** Compound addition assignment */
        I16 &operator+=(const I16 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        I16 &operator-=(const I16 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        I16 &operator*=(const I16 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        I16 &operator/=(const I16 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class I32
    {
    public:
        int32_t value;
        /** Construct from int32_t value (default 0) */
        explicit I32(int32_t v = 0) : value(v) {}
        /** Implicit conversion to int32_t */
        operator int32_t() const { return value; }
        /** Assign from int32_t */
        I32 &operator=(int32_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const I32 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const I32 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const I32 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const I32 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const I32 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const I32 &other) const { return value >= other.value; }
        /** Addition operator */
        I32 operator+(const I32 &other) const { return I32(value + other.value); }
        /** Subtraction operator */
        I32 operator-(const I32 &other) const { return I32(value - other.value); }
        /** Multiplication operator */
        I32 operator*(const I32 &other) const { return I32(value * other.value); }
        /** Division operator */
        I32 operator/(const I32 &other) const { return I32(value / other.value); }
        /** Compound addition assignment */
        I32 &operator+=(const I32 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        I32 &operator-=(const I32 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        I32 &operator*=(const I32 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        I32 &operator/=(const I32 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class I64
    {
    public:
        int64_t value;
        /** Construct from int64_t value (default 0) */
        explicit I64(int64_t v = 0) : value(v) {}
        /** Implicit conversion to int64_t */
        operator int64_t() const { return value; }
        /** Assign from int64_t */
        I64 &operator=(int64_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const I64 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const I64 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const I64 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const I64 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const I64 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const I64 &other) const { return value >= other.value; }
        /** Addition operator */
        I64 operator+(const I64 &other) const { return I64(value + other.value); }
        /** Subtraction operator */
        I64 operator-(const I64 &other) const { return I64(value - other.value); }
        /** Multiplication operator */
        I64 operator*(const I64 &other) const { return I64(value * other.value); }
        /** Division operator */
        I64 operator/(const I64 &other) const { return I64(value / other.value); }
        /** Compound addition assignment */
        I64 &operator+=(const I64 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        I64 &operator-=(const I64 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        I64 &operator*=(const I64 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        I64 &operator/=(const I64 &other)
        {
            value /= other.value;
            return *this;
        }
    };

    // Unsigned integer types
    class U8
    {
    public:
        uint8_t value;
        /** Construct from uint8_t value (default 0) */
        explicit U8(uint8_t v = 0) : value(v) {}
        /** Implicit conversion to uint8_t */
        operator uint8_t() const { return value; }
        /** Assign from uint8_t */
        U8 &operator=(uint8_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const U8 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const U8 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const U8 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const U8 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const U8 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const U8 &other) const { return value >= other.value; }
        /** Addition operator */
        U8 operator+(const U8 &other) const { return U8(value + other.value); }
        /** Subtraction operator */
        U8 operator-(const U8 &other) const { return U8(value - other.value); }
        /** Multiplication operator */
        U8 operator*(const U8 &other) const { return U8(value * other.value); }
        /** Division operator */
        U8 operator/(const U8 &other) const { return U8(value / other.value); }
        /** Compound addition assignment */
        U8 &operator+=(const U8 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        U8 &operator-=(const U8 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        U8 &operator*=(const U8 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        U8 &operator/=(const U8 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class U16
    {
    public:
        uint16_t value;
        /** Construct from uint16_t value (default 0) */
        explicit U16(uint16_t v = 0) : value(v) {}
        /** Implicit conversion to uint16_t */
        operator uint16_t() const { return value; }
        /** Assign from uint16_t */
        U16 &operator=(uint16_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const U16 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const U16 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const U16 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const U16 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const U16 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const U16 &other) const { return value >= other.value; }
        /** Addition operator */
        U16 operator+(const U16 &other) const { return U16(value + other.value); }
        /** Subtraction operator */
        U16 operator-(const U16 &other) const { return U16(value - other.value); }
        /** Multiplication operator */
        U16 operator*(const U16 &other) const { return U16(value * other.value); }
        /** Division operator */
        U16 operator/(const U16 &other) const { return U16(value / other.value); }
        /** Compound addition assignment */
        U16 &operator+=(const U16 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        U16 &operator-=(const U16 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        U16 &operator*=(const U16 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        U16 &operator/=(const U16 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class U32
    {
    public:
        uint32_t value;
        /** Construct from uint32_t value (default 0) */
        explicit U32(uint32_t v = 0) : value(v) {}
        /** Implicit conversion to uint32_t */
        operator uint32_t() const { return value; }
        /** Assign from uint32_t */
        U32 &operator=(uint32_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const U32 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const U32 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const U32 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const U32 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const U32 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const U32 &other) const { return value >= other.value; }
        /** Addition operator */
        U32 operator+(const U32 &other) const { return U32(value + other.value); }
        /** Subtraction operator */
        U32 operator-(const U32 &other) const { return U32(value - other.value); }
        /** Multiplication operator */
        U32 operator*(const U32 &other) const { return U32(value * other.value); }
        /** Division operator */
        U32 operator/(const U32 &other) const { return U32(value / other.value); }
        /** Compound addition assignment */
        U32 &operator+=(const U32 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        U32 &operator-=(const U32 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        U32 &operator*=(const U32 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        U32 &operator/=(const U32 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class U64
    {
    public:
        uint64_t value;
        /** Construct from uint64_t value (default 0) */
        explicit U64(uint64_t v = 0) : value(v) {}
        /** Implicit conversion to uint64_t */
        operator uint64_t() const { return value; }
        /** Assign from uint64_t */
        U64 &operator=(uint64_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const U64 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const U64 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const U64 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const U64 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const U64 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const U64 &other) const { return value >= other.value; }
        /** Addition operator */
        U64 operator+(const U64 &other) const { return U64(value + other.value); }
        /** Subtraction operator */
        U64 operator-(const U64 &other) const { return U64(value - other.value); }
        /** Multiplication operator */
        U64 operator*(const U64 &other) const { return U64(value * other.value); }
        /** Division operator */
        U64 operator/(const U64 &other) const { return U64(value / other.value); }
        /** Compound addition assignment */
        U64 &operator+=(const U64 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        U64 &operator-=(const U64 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        U64 &operator*=(const U64 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        U64 &operator/=(const U64 &other)
        {
            value /= other.value;
            return *this;
        }
    };

    // Hex, octal, binary types (inherit all operators)
    /** 8-bit hexadecimal type (inherits U8) */
    class H8 : public U8
    {
    public:
        using U8::U8;
    };
    /** 16-bit hexadecimal type (inherits U16) */
    class H16 : public U16
    {
    public:
        using U16::U16;
    };
    /** 32-bit hexadecimal type (inherits U32) */
    class H32 : public U32
    {
    public:
        using U32::U32;
    };
    /** 64-bit hexadecimal type (inherits U64) */
    class H64 : public U64
    {
    public:
        using U64::U64;
    };

    /** 8-bit octal type (inherits U8) */
    class O8 : public U8
    {
    public:
        using U8::U8;
    };
    /** 16-bit octal type (inherits U16) */
    class O16 : public U16
    {
    public:
        using U16::U16;
    };
    /** 32-bit octal type (inherits U32) */
    class O32 : public U32
    {
    public:
        using U32::U32;
    };
    /** 64-bit octal type (inherits U64) */
    class O64 : public U64
    {
    public:
        using U64::U64;
    };

    /** 8-bit binary type (inherits U8) */
    class B8 : public U8
    {
    public:
        using U8::U8;
    };
    /** 16-bit binary type (inherits U16) */
    class B16 : public U16
    {
    public:
        using U16::U16;
    };
    /** 32-bit binary type (inherits U32) */
    class B32 : public U32
    {
    public:
        using U32::U32;
    };
    /** 64-bit binary type (inherits U64) */
    class B64 : public U64
    {
    public:
        using U64::U64;
    };

    // Floating point types
    class F32
    {
    public:
        float value;
        /** Construct from float value (default 0.0f) */
        explicit F32(float v = 0.0f) : value(v) {}
        /** Implicit conversion to float */
        operator float() const { return value; }
        /** Assign from float */
        F32 &operator=(float v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const F32 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const F32 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const F32 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const F32 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const F32 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const F32 &other) const { return value >= other.value; }
        /** Addition operator */
        F32 operator+(const F32 &other) const { return F32(value + other.value); }
        /** Subtraction operator */
        F32 operator-(const F32 &other) const { return F32(value - other.value); }
        /** Multiplication operator */
        F32 operator*(const F32 &other) const { return F32(value * other.value); }
        /** Division operator */
        F32 operator/(const F32 &other) const { return F32(value / other.value); }
        /** Compound addition assignment */
        F32 &operator+=(const F32 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        F32 &operator-=(const F32 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        F32 &operator*=(const F32 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        F32 &operator/=(const F32 &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class F64
    {
    public:
        double value;
        /** Construct from double value (default 0.0) */
        explicit F64(double v = 0.0) : value(v) {}
        /** Implicit conversion to double */
        operator double() const { return value; }
        /** Assign from double */
        F64 &operator=(double v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const F64 &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const F64 &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const F64 &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const F64 &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const F64 &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const F64 &other) const { return value >= other.value; }
        /** Addition operator */
        F64 operator+(const F64 &other) const { return F64(value + other.value); }
        /** Subtraction operator */
        F64 operator-(const F64 &other) const { return F64(value - other.value); }
        /** Multiplication operator */
        F64 operator*(const F64 &other) const { return F64(value * other.value); }
        /** Division operator */
        F64 operator/(const F64 &other) const { return F64(value / other.value); }
        /** Compound addition assignment */
        F64 &operator+=(const F64 &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        F64 &operator-=(const F64 &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        F64 &operator*=(const F64 &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        F64 &operator/=(const F64 &other)
        {
            value /= other.value;
            return *this;
        }
    };

    // Size types
    class Isize
    {
    public:
        ptrdiff_t value;
        /** Construct from ptrdiff_t value (default 0) */
        explicit Isize(ptrdiff_t v = 0) : value(v) {}
        /** Implicit conversion to ptrdiff_t */
        operator ptrdiff_t() const { return value; }
        /** Assign from ptrdiff_t */
        Isize &operator=(ptrdiff_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Isize &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Isize &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const Isize &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const Isize &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const Isize &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const Isize &other) const { return value >= other.value; }
        /** Addition operator */
        Isize operator+(const Isize &other) const { return Isize(value + other.value); }
        /** Subtraction operator */
        Isize operator-(const Isize &other) const { return Isize(value - other.value); }
        /** Multiplication operator */
        Isize operator*(const Isize &other) const { return Isize(value * other.value); }
        /** Division operator */
        Isize operator/(const Isize &other) const { return Isize(value / other.value); }
        /** Compound addition assignment */
        Isize &operator+=(const Isize &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        Isize &operator-=(const Isize &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        Isize &operator*=(const Isize &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        Isize &operator/=(const Isize &other)
        {
            value /= other.value;
            return *this;
        }
    };
    class Usize
    {
    public:
        size_t value;
        /** Construct from size_t value (default 0) */
        explicit Usize(size_t v = 0) : value(v) {}
        /** Implicit conversion to size_t */
        operator size_t() const { return value; }
        /** Assign from size_t */
        Usize &operator=(size_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Usize &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Usize &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const Usize &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const Usize &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const Usize &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const Usize &other) const { return value >= other.value; }
        /** Addition operator */
        Usize operator+(const Usize &other) const { return Usize(value + other.value); }
        /** Subtraction operator */
        Usize operator-(const Usize &other) const { return Usize(value - other.value); }
        /** Multiplication operator */
        Usize operator*(const Usize &other) const { return Usize(value * other.value); }
        /** Division operator */
        Usize operator/(const Usize &other) const { return Usize(value / other.value); }
        /** Compound addition assignment */
        Usize &operator+=(const Usize &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        Usize &operator-=(const Usize &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        Usize &operator*=(const Usize &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        Usize &operator/=(const Usize &other)
        {
            value /= other.value;
            return *this;
        }
    };

    // Character and string types
    class Char_t
    {
    public:
        char value;
        /** Construct from char value (default '\0') */
        explicit Char_t(char v = '\0') : value(v) {}
        /** Implicit conversion to char */
        operator char() const { return value; }
        /** Assign from char */
        Char_t &operator=(char v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Char_t &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Char_t &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const Char_t &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const Char_t &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const Char_t &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const Char_t &other) const { return value >= other.value; }
    };
    class Cstr
    {
    public:
        const char *value;
        /** Construct from const char* value (default nullptr) */
        explicit Cstr(const char *v = nullptr) : value(v) {}
        /** Implicit conversion to const char* */
        operator const char *() const { return value; }
        /** Assign from const char* */
        Cstr &operator=(const char *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison (pointer equality) */
        bool operator==(const Cstr &other) const { return value == other.value; }
        /** Inequality comparison (pointer inequality) */
        bool operator!=(const Cstr &other) const { return value != other.value; }
    };

    // Pointer types
    class Ptr
    {
    public:
        void *value;
        /** Construct from void* value (default nullptr) */
        explicit Ptr(void *v = nullptr) : value(v) {}
        /** Implicit conversion to void* */
        operator void *() const { return value; }
        /** Assign from void* */
        Ptr &operator=(void *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Ptr &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Ptr &other) const { return value != other.value; }
    };
    class Cptr
    {
    public:
        const void *value;
        /** Construct from const void* value (default nullptr) */
        explicit Cptr(const void *v = nullptr) : value(v) {}
        /** Implicit conversion to const void* */
        operator const void *() const { return value; }
        /** Assign from const void* */
        Cptr &operator=(const void *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Cptr &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Cptr &other) const { return value != other.value; }
    };

    // Handle and ref types
    class Handle
    {
    public:
        void *value;
        /** Construct from void* value (default nullptr) */
        explicit Handle(void *v = nullptr) : value(v) {}
        /** Implicit conversion to void* */
        operator void *() const { return value; }
        /** Assign from void* */
        Handle &operator=(void *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Handle &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Handle &other) const { return value != other.value; }
    };
    class Ref
    {
    public:
        void *value;
        /** Construct from void* value (default nullptr) */
        explicit Ref(void *v = nullptr) : value(v) {}
        /** Implicit conversion to void* */
        operator void *() const { return value; }
        /** Assign from void* */
        Ref &operator=(void *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Ref &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Ref &other) const { return value != other.value; }
    };

    // Atom type
    class Atom
    {
    public:
        const void *value;
        /** Construct from const void* value (default nullptr) */
        explicit Atom(const void *v = nullptr) : value(v) {}
        /** Implicit conversion to const void* */
        operator const void *() const { return value; }
        /** Assign from const void* */
        Atom &operator=(const void *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Atom &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Atom &other) const { return value != other.value; }
    };

    // Type id and symbol
    class Type_id
    {
    public:
        const char *value;
        /** Construct from const char* value (default nullptr) */
        explicit Type_id(const char *v = nullptr) : value(v) {}
        /** Implicit conversion to const char* */
        operator const char *() const { return value; }
        /** Assign from const char* */
        Type_id &operator=(const char *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison (pointer equality) */
        bool operator==(const Type_id &other) const { return value == other.value; }
        /** Inequality comparison (pointer inequality) */
        bool operator!=(const Type_id &other) const { return value != other.value; }
    };
    class Symbol
    {
    public:
        const char *value;
        /** Construct from const char* value (default nullptr) */
        explicit Symbol(const char *v = nullptr) : value(v) {}
        /** Implicit conversion to const char* */
        operator const char *() const { return value; }
        /** Assign from const char* */
        Symbol &operator=(const char *v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison (pointer equality) */
        bool operator==(const Symbol &other) const { return value == other.value; }
        /** Inequality comparison (pointer inequality) */
        bool operator!=(const Symbol &other) const { return value != other.value; }
    };

    // Flags
    class Flags
    {
    public:
        uint64_t value;
        /** Construct from uint64_t value (default 0) */
        explicit Flags(uint64_t v = 0) : value(v) {}
        /** Implicit conversion to uint64_t */
        operator uint64_t() const { return value; }
        /** Assign from uint64_t */
        Flags &operator=(uint64_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Flags &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Flags &other) const { return value != other.value; }
        /** Bitwise OR operator */
        Flags operator|(const Flags &other) const { return Flags(value | other.value); }
        /** Bitwise AND operator */
        Flags operator&(const Flags &other) const { return Flags(value & other.value); }
        /** Bitwise XOR operator */
        Flags operator^(const Flags &other) const { return Flags(value ^ other.value); }
        /** Bitwise NOT operator */
        Flags operator~() const { return Flags(~value); }
        /** Compound bitwise OR assignment */
        Flags &operator|=(const Flags &other)
        {
            value |= other.value;
            return *this;
        }
        /** Compound bitwise AND assignment */
        Flags &operator&=(const Flags &other)
        {
            value &= other.value;
            return *this;
        }
        /** Compound bitwise XOR assignment */
        Flags &operator^=(const Flags &other)
        {
            value ^= other.value;
            return *this;
        }
    };

    // Node id
    class Node_id
    {
    public:
        uint64_t value;
        /** Construct from uint64_t value (default 0) */
        explicit Node_id(uint64_t v = 0) : value(v) {}
        /** Implicit conversion to uint64_t */
        operator uint64_t() const { return value; }
        /** Assign from uint64_t */
        Node_id &operator=(uint64_t v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Node_id &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Node_id &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const Node_id &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const Node_id &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const Node_id &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const Node_id &other) const { return value >= other.value; }
    };

    // Entropy
    class Entropy
    {
    public:
        double value;
        /** Construct from double value (default 0.0) */
        explicit Entropy(double v = 0.0) : value(v) {}
        /** Implicit conversion to double */
        operator double() const { return value; }
        /** Assign from double */
        Entropy &operator=(double v)
        {
            value = v;
            return *this;
        }
        /** Equality comparison */
        bool operator==(const Entropy &other) const { return value == other.value; }
        /** Inequality comparison */
        bool operator!=(const Entropy &other) const { return value != other.value; }
        /** Less-than comparison */
        bool operator<(const Entropy &other) const { return value < other.value; }
        /** Greater-than comparison */
        bool operator>(const Entropy &other) const { return value > other.value; }
        /** Less-than or equal comparison */
        bool operator<=(const Entropy &other) const { return value <= other.value; }
        /** Greater-than or equal comparison */
        bool operator>=(const Entropy &other) const { return value >= other.value; }
        /** Addition operator */
        Entropy operator+(const Entropy &other) const { return Entropy(value + other.value); }
        /** Subtraction operator */
        Entropy operator-(const Entropy &other) const { return Entropy(value - other.value); }
        /** Multiplication operator */
        Entropy operator*(const Entropy &other) const { return Entropy(value * other.value); }
        /** Division operator */
        Entropy operator/(const Entropy &other) const { return Entropy(value / other.value); }
        /** Compound addition assignment */
        Entropy &operator+=(const Entropy &other)
        {
            value += other.value;
            return *this;
        }
        /** Compound subtraction assignment */
        Entropy &operator-=(const Entropy &other)
        {
            value -= other.value;
            return *this;
        }
        /** Compound multiplication assignment */
        Entropy &operator*=(const Entropy &other)
        {
            value *= other.value;
            return *this;
        }
        /** Compound division assignment */
        Entropy &operator/=(const Entropy &other)
        {
            value /= other.value;
            return *this;
        }
    };

}

#endif

#endif
