/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * performance, cross-platform applications and libraries. The code contained
 * This file is part of the Fossil Logic project, which aims to develop high-
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/pizza/framework.h>

#include "fossil/time/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define the test suite and add test cases
FOSSIL_SUITE(c_types_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_types_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_types_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Signed integer types
FOSSIL_TEST(c_test_type_signed_integers) {
    i8 a = -128;   ASSUME_ITS_EQUAL_I32(a, -128);
    i16 b = -32768; ASSUME_ITS_EQUAL_I32(b, -32768);
    i32 c = -2147483647 - 1; ASSUME_ITS_TRUE(c < 0);
    i64 d = -9000000000000000000LL; ASSUME_ITS_TRUE(d < 0);
}

// Test: Unsigned integer types
FOSSIL_TEST(c_test_type_unsigned_integers) {
    u8 a = 255;    ASSUME_ITS_EQUAL_I32(a, 255);
    u16 b = 65535; ASSUME_ITS_EQUAL_I32(b, 65535);
    u32 c = 0xFFFFFFFFU; ASSUME_ITS_TRUE(c > 0);
    u64 d = 18446744073709551615ULL; ASSUME_ITS_TRUE(d > 0);
}

// Test: Hexadecimal aliases
FOSSIL_TEST(c_test_type_hex_aliases) {
    h8 a = 0xAB;    ASSUME_ITS_EQUAL_I32(a, 0xAB);
    h16 b = 0xBEEF; ASSUME_ITS_EQUAL_I32(b, 0xBEEF);
    h32 c = 0xDEADBEEF; ASSUME_ITS_TRUE(c == 0xDEADBEEF);
    h64 d = 0x123456789ABCDEF0ULL; ASSUME_ITS_TRUE(d == 0x123456789ABCDEF0ULL);
}

// Test: Octal aliases
FOSSIL_TEST(c_test_type_octal_aliases) {
    o8 a = 077;     ASSUME_ITS_EQUAL_I32(a, 63);
    o16 b = 0777;   ASSUME_ITS_EQUAL_I32(b, 511);
    o32 c = 01234567; ASSUME_ITS_EQUAL_I32(c, 342391);
    o64 d = 07777777777777777777ULL; ASSUME_ITS_TRUE(d > 0);
}

// Test: Binary aliases
FOSSIL_TEST(c_test_type_binary_aliases) {
    b8 a = 0b10101010; ASSUME_ITS_EQUAL_I32(a, 170);
    b16 b = 0b1111000011110000; ASSUME_ITS_EQUAL_I32(b, 61680);
    b32 c = 0b10101010101010101010101010101010U; ASSUME_ITS_TRUE(c == 0xAAAAAAAAU);
    b64 d = 0b1ULL << 63; ASSUME_ITS_TRUE(d == 0x8000000000000000ULL);
}

// Test: Floating point types
FOSSIL_TEST(c_test_type_floating_point) {
    f32 a = 0.75f; ASSUME_ITS_TRUE(a > 0.7f && a < 0.8f);
    f64 b = 3.141592653589793; ASSUME_ITS_TRUE(b > 3.14 && b < 3.15);
}

// Test: Size types
FOSSIL_TEST(c_test_type_size_types) {
    usize a = 12345; ASSUME_ITS_TRUE(a == 12345);
    isize b = -12345; ASSUME_ITS_TRUE(b == -12345);
}

// Test: Character and string types
FOSSIL_TEST(c_test_type_char_and_string) {
    char_t c = 'A'; ASSUME_ITS_EQUAL_I32(c, 'A');
    cstr s = "hello fossil"; ASSUME_ITS_EQUAL_CSTR(s, "hello fossil");
}

// Test: Pointer semantics
FOSSIL_TEST(c_test_type_pointer_semantics) {
    int x = 42;
    ptr p = &x; ASSUME_ITS_TRUE(*(int*)p == 42);
    cptr cp = p; ASSUME_ITS_TRUE(*(const int*)cp == 42);
}

// Test: Ownership-aware handles
FOSSIL_TEST(c_test_type_handle_and_ref) {
    int x = 99;
    handle h = &x; ASSUME_ITS_TRUE(*(int*)h == 99);
    ref r = h; ASSUME_ITS_TRUE(*(int*)r == 99);
}

// Test: Atom type
FOSSIL_TEST(c_test_type_atom) {
    atom a = (atom)"user_id";
    atom b = (atom)"user_id";
    ASSUME_ITS_TRUE(a == b || strcmp((const char*)a, (const char*)b) == 0);
}

// Test: Type identifiers and symbols
FOSSIL_TEST(c_test_type_typeid_and_symbol) {
    type_id t = "i32";
    symbol s = "max_value";
    ASSUME_ITS_EQUAL_CSTR(t, "i32");
    ASSUME_ITS_EQUAL_CSTR(s, "max_value");
}

// Test: Flags bitfield
FOSSIL_TEST(c_test_type_flags) {
    flags f = (1ULL << 0) | (1ULL << 3);
    ASSUME_ITS_TRUE((f & (1ULL << 0)) && (f & (1ULL << 3)));
    ASSUME_ITS_FALSE(f & (1ULL << 2));
}

// Test: Node identity
FOSSIL_TEST(c_test_type_node_id) {
    node_id n = 42;
    ASSUME_ITS_TRUE(n == 42);
}

// Test: Entropy type
FOSSIL_TEST(c_test_type_entropy) {
    entropy e = 0.73;
    ASSUME_ITS_TRUE(e > 0.7 && e < 0.8);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_types_tests) {
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_signed_integers);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_unsigned_integers);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_hex_aliases);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_octal_aliases);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_binary_aliases);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_floating_point);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_size_types);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_char_and_string);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_pointer_semantics);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_handle_and_ref);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_atom);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_typeid_and_symbol);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_flags);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_node_id);
    FOSSIL_TEST_ADD(c_types_suite, c_test_type_entropy);

    FOSSIL_TEST_REGISTER(c_types_suite);
}
