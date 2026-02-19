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
FOSSIL_SUITE(cpp_limits_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_limits_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_limits_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Limits class returns 0 for unknown type
FOSSIL_TEST(cpp_test_limits_class_unknown_type) {
    fossil::type::Limits lim("not_a_type");
    ASSUME_ITS_TRUE(lim.min() == 0);
    ASSUME_ITS_TRUE(lim.max() == 0);
    ASSUME_ITS_TRUE(lim.size() == 0);
}

// Test: Limits class returns 0 for NULL input
FOSSIL_TEST(cpp_test_limits_class_null_input) {
    fossil::type::Limits lim(nullptr);
    ASSUME_ITS_TRUE(lim.min() == 0);
    ASSUME_ITS_TRUE(lim.max() == 0);
    ASSUME_ITS_TRUE(lim.size() == 0);
}

// Test: Limits class returns correct values for aliases
FOSSIL_TEST(cpp_test_limits_class_aliases) {
    struct {
        const char* alias;
        const char* base;
    } aliases[] = {
        {"h8", "u8"}, {"h16", "u16"}, {"h32", "u32"}, {"h64", "u64"},
        {"o8", "u8"}, {"o16", "u16"}, {"o32", "u32"}, {"o64", "u64"},
        {"b8", "u8"}, {"b16", "u16"}, {"b32", "u32"}, {"b64", "u64"},
    };

    for (size_t i = 0; i < sizeof(aliases)/sizeof(aliases[0]); ++i) {
        fossil::type::Limits lim_alias(aliases[i].alias);
        fossil::type::Limits lim_base(aliases[i].base);
        ASSUME_ITS_TRUE(lim_alias.min() == lim_base.min());
        ASSUME_ITS_TRUE(lim_alias.max() == lim_base.max());
        ASSUME_ITS_TRUE(lim_alias.size() == lim_base.size());
    }
}

// Test: Limits class can be used in a scoped block and still valid
FOSSIL_TEST(cpp_test_limits_class_scoped_usage) {
    long double min_val = 0, max_val = 0;
    size_t sz = 0;
    {
        fossil::type::Limits lim("i16");
        min_val = lim.min();
        max_val = lim.max();
        sz = lim.size();
    }
    ASSUME_ITS_TRUE(min_val == SHRT_MIN);
    ASSUME_ITS_TRUE(max_val == SHRT_MAX);
    ASSUME_ITS_TRUE(sz == sizeof(int16_t));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_limits_tests) {
    FOSSIL_TEST_ADD(cpp_limits_suite, cpp_test_limits_class_unknown_type);
    FOSSIL_TEST_ADD(cpp_limits_suite, cpp_test_limits_class_null_input);
    FOSSIL_TEST_ADD(cpp_limits_suite, cpp_test_limits_class_aliases);
    FOSSIL_TEST_ADD(cpp_limits_suite, cpp_test_limits_class_scoped_usage);

    FOSSIL_TEST_REGISTER(cpp_limits_suite);
}
