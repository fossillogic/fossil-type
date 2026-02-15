
#ifndef FOSSIL_TYPE_ATTRIBUTES_H
#define FOSSIL_TYPE_ATTRIBUTES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ======================================================
 * Attribute kind: maps directly to Fossil core types
 * ====================================================== */
typedef enum fossil_type_attribute_kind {
    FOSSIL_TYPE_ATTRIBUTE_NONE = 0,

    /* Signed integers */
    FOSSIL_TYPE_ATTRIBUTE_I8,
    FOSSIL_TYPE_ATTRIBUTE_I16,
    FOSSIL_TYPE_ATTRIBUTE_I32,
    FOSSIL_TYPE_ATTRIBUTE_I64,

    /* Unsigned integers */
    FOSSIL_TYPE_ATTRIBUTE_U8,
    FOSSIL_TYPE_ATTRIBUTE_U16,
    FOSSIL_TYPE_ATTRIBUTE_U32,
    FOSSIL_TYPE_ATTRIBUTE_U64,

    /* Hexadecimal (alias) */
    FOSSIL_TYPE_ATTRIBUTE_H8,
    FOSSIL_TYPE_ATTRIBUTE_H16,
    FOSSIL_TYPE_ATTRIBUTE_H32,
    FOSSIL_TYPE_ATTRIBUTE_H64,

    /* Octal (alias) */
    FOSSIL_TYPE_ATTRIBUTE_O8,
    FOSSIL_TYPE_ATTRIBUTE_O16,
    FOSSIL_TYPE_ATTRIBUTE_O32,
    FOSSIL_TYPE_ATTRIBUTE_O64,

    /* Binary (alias) */
    FOSSIL_TYPE_ATTRIBUTE_B8,
    FOSSIL_TYPE_ATTRIBUTE_B16,
    FOSSIL_TYPE_ATTRIBUTE_B32,
    FOSSIL_TYPE_ATTRIBUTE_B64,

    /* Floating */
    FOSSIL_TYPE_ATTRIBUTE_F32,
    FOSSIL_TYPE_ATTRIBUTE_F64,

    /* Boolean / Tribool */
    FOSSIL_TYPE_ATTRIBUTE_BOOL,
    FOSSIL_TYPE_ATTRIBUTE_TRIBOOL,

    /* Char / String */
    FOSSIL_TYPE_ATTRIBUTE_CHAR,
    FOSSIL_TYPE_ATTRIBUTE_CSTR,

    /* Pointer for generic or unknown types */
    FOSSIL_TYPE_ATTRIBUTE_PTR
} fossil_type_attribute_kind;

/* ======================================================
 * Attribute value union
 * ====================================================== */
typedef struct fossil_type_attribute_value {
    fossil_type_attribute_kind kind;
    union {
        /* Signed integers */
        int8_t   i8;
        int16_t  i16;
        int32_t  i32;
        int64_t  i64;

        /* Unsigned integers */
        uint8_t  u8;
        uint16_t u16;
        uint32_t u32;
        uint64_t u64;

        /* Floating */
        float    f32;
        double   f64;

        /* Boolean / tribool */
        bool     b;
        int      tribool;

        /* Char / string */
        char     c;
        const char* s;

        /* Pointer */
        void*    p;
    } data;
} fossil_type_attribute_value;

/* ======================================================
 * Attribute Entry
 * ====================================================== */

typedef struct fossil_type_attribute {
    const char* key;
    fossil_type_attribute_value value;
} fossil_type_attribute;

typedef fossil_type_attribute attribute;

/* ======================================================
 * Attribute Table
 * ====================================================== */

typedef struct fossil_type_attribute_table {
    const char* type_id;
    attribute*  attributes;
    size_t      count;
} fossil_type_attribute_table;

/* ======================================================
 * Registration
 * ====================================================== */

int fossil_type_attributes_register(
    fossil_type_attribute_table* table);

/* ======================================================
 * Queries
 * ====================================================== */

const attribute*
fossil_type_attributes_get(
    const char* type_id,
    const char* key);

int fossil_type_attributes_has(
    const char* type_id,
    const char* key);

#ifdef __cplusplus
}
#endif


/* ======================================================
 * C++ Wrapper
 * ====================================================== */
#ifdef __cplusplus

namespace fossil::type {

class AttributeValue {
    fossil_type_attribute_value v;

public:
    AttributeValue() { v.kind = FOSSIL_TYPE_ATTRIBUTE_NONE; }

    /* -----------------------------
     * Signed integers
     * ----------------------------- */
    static AttributeValue from_i8(int8_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_I8;   r.v.data.i8  = x; return r;
    }
    static AttributeValue from_i16(int16_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_I16;  r.v.data.i16 = x; return r;
    }
    static AttributeValue from_i32(int32_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_I32;  r.v.data.i32 = x; return r;
    }
    static AttributeValue from_i64(int64_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_I64;  r.v.data.i64 = x; return r;
    }

    /* -----------------------------
     * Unsigned integers
     * ----------------------------- */
    static AttributeValue from_u8(uint8_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_U8;   r.v.data.u8  = x; return r;
    }
    static AttributeValue from_u16(uint16_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_U16;  r.v.data.u16 = x; return r;
    }
    static AttributeValue from_u32(uint32_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_U32;  r.v.data.u32 = x; return r;
    }
    static AttributeValue from_u64(uint64_t x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_U64;  r.v.data.u64 = x; return r;
    }

    /* -----------------------------
     * Hex / Octal / Binary aliases
     * ----------------------------- */
    static AttributeValue from_h8(uint8_t x)   { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_H8;   r.v.data.u8 = x; return r; }
    static AttributeValue from_h16(uint16_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_H16;  r.v.data.u16 = x; return r; }
    static AttributeValue from_h32(uint32_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_H32;  r.v.data.u32 = x; return r; }
    static AttributeValue from_h64(uint64_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_H64;  r.v.data.u64 = x; return r; }

    static AttributeValue from_o8(uint8_t x)   { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_O8;   r.v.data.u8 = x; return r; }
    static AttributeValue from_o16(uint16_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_O16;  r.v.data.u16 = x; return r; }
    static AttributeValue from_o32(uint32_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_O32;  r.v.data.u32 = x; return r; }
    static AttributeValue from_o64(uint64_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_O64;  r.v.data.u64 = x; return r; }

    static AttributeValue from_b8(uint8_t x)   { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_B8;   r.v.data.u8 = x; return r; }
    static AttributeValue from_b16(uint16_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_B16;  r.v.data.u16 = x; return r; }
    static AttributeValue from_b32(uint32_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_B32;  r.v.data.u32 = x; return r; }
    static AttributeValue from_b64(uint64_t x) { AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_B64;  r.v.data.u64 = x; return r; }

    /* -----------------------------
     * Floating
     * ----------------------------- */
    static AttributeValue from_f32(float x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_F32; r.v.data.f32 = x; return r;
    }
    static AttributeValue from_f64(double x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_F64; r.v.data.f64 = x; return r;
    }

    /* -----------------------------
     * Boolean / Tribool
     * ----------------------------- */
    static AttributeValue from_bool(bool x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_BOOL; r.v.data.b = x; return r;
    }
    static AttributeValue from_tribool(int x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_TRIBOOL; r.v.data.tribool = x; return r;
    }

    /* -----------------------------
     * Char / String
     * ----------------------------- */
    static AttributeValue from_char(char x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_CHAR; r.v.data.c = x; return r;
    }
    static AttributeValue from_cstr(const char* x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_CSTR; r.v.data.s = x; return r;
    }

    /* -----------------------------
     * Generic pointer
     * ----------------------------- */
    static AttributeValue from_ptr(void* x) {
        AttributeValue r; r.v.kind = FOSSIL_TYPE_ATTRIBUTE_PTR; r.v.data.p = x; return r;
    }

    /* Access raw C struct */
    const fossil_type_attribute_value* raw() const { return &v; }
};


/* ======================================================
 * Attributes table access
 * ====================================================== */
class Attributes {
public:
    static const attribute* get(const char* type, const char* key) {
        return fossil_type_attributes_get(type, key);
    }

    static bool has(const char* type, const char* key) {
        return fossil_type_attributes_has(type, key) != 0;
    }
};

} // namespace fossil::type

#endif

#endif
