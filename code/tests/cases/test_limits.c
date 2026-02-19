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

#include "fossil/type/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define the test suite and add test cases
FOSSIL_SUITE(c_limits_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_limits_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_limits_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: fossil_type_limits_get returns NULL for unknown type
FOSSIL_TEST(c_test_limits_unknown_type) {
    const fossil_type_limits* lim = fossil_type_limits_get("not_a_type");
    ASSUME_ITS_TRUE(lim == NULL);
}

// Test: fossil_type_limits_get returns NULL for NULL input
FOSSIL_TEST(c_test_limits_null_input) {
    const fossil_type_limits* lim = fossil_type_limits_get(NULL);
    ASSUME_ITS_TRUE(lim == NULL);
}

// Test: fossil_type_limits_get returns correct aliases for unsigned types
FOSSIL_TEST(c_test_limits_aliases) {
    struct {
        const char* alias;
        const char* base;
    } aliases[] = {
        {"h8", "u8"}, {"h16", "u16"}, {"h32", "u32"}, {"h64", "u64"},
        {"o8", "u8"}, {"o16", "u16"}, {"o32", "u32"}, {"o64", "u64"},
        {"b8", "u8"}, {"b16", "u16"}, {"b32", "u32"}, {"b64", "u64"},
    };

    for (size_t i = 0; i < sizeof(aliases)/sizeof(aliases[0]); ++i) {
        const fossil_type_limits* lim_alias = fossil_type_limits_get(aliases[i].alias);
        const fossil_type_limits* lim_base = fossil_type_limits_get(aliases[i].base);
        ASSUME_ITS_TRUE(lim_alias != NULL && lim_base != NULL);
        ASSUME_ITS_TRUE(lim_alias->min_value == lim_base->min_value);
        ASSUME_ITS_TRUE(lim_alias->max_value == lim_base->max_value);
        ASSUME_ITS_TRUE(lim_alias->size == lim_base->size);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_limits_tests) {
    FOSSIL_TEST_ADD(c_limits_suite, c_test_limits_unknown_type);
    FOSSIL_TEST_ADD(c_limits_suite, c_test_limits_null_input);
    FOSSIL_TEST_ADD(c_limits_suite, c_test_limits_aliases);

    FOSSIL_TEST_REGISTER(c_limits_suite);
}
