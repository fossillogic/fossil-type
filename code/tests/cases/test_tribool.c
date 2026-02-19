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
FOSSIL_SUITE(c_tribool_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_tribool_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_tribool_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Tribool constructors
FOSSIL_TEST(c_test_tribool_constructors) {
    tribool t_true = fossil_type_tribool_make_true();
    tribool t_false = fossil_type_tribool_make_false();
    tribool t_unknown = fossil_type_tribool_make_unknown();

    ASSUME_ITS_TRUE(t_true == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(t_false == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(t_unknown == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
}

// Test: Tribool predicates
FOSSIL_TEST(c_test_tribool_predicates) {
    tribool t_true = FOSSIL_TYPE_TRIBOOL_TRUE;
    tribool t_false = FOSSIL_TYPE_TRIBOOL_FALSE;
    tribool t_unknown = FOSSIL_TYPE_TRIBOOL_UNKNOWN;

    ASSUME_ITS_TRUE(fossil_type_tribool_is_true(t_true));
    ASSUME_ITS_FALSE(fossil_type_tribool_is_true(t_false));
    ASSUME_ITS_FALSE(fossil_type_tribool_is_true(t_unknown));

    ASSUME_ITS_TRUE(fossil_type_tribool_is_false(t_false));
    ASSUME_ITS_FALSE(fossil_type_tribool_is_false(t_true));
    ASSUME_ITS_FALSE(fossil_type_tribool_is_false(t_unknown));

    ASSUME_ITS_TRUE(fossil_type_tribool_is_unknown(t_unknown));
    ASSUME_ITS_FALSE(fossil_type_tribool_is_unknown(t_true));
    ASSUME_ITS_FALSE(fossil_type_tribool_is_unknown(t_false));
}

// Test: Tribool AND logic
FOSSIL_TEST(c_test_tribool_and_logic) {
    tribool t = FOSSIL_TYPE_TRIBOOL_TRUE;
    tribool f = FOSSIL_TYPE_TRIBOOL_FALSE;
    tribool u = FOSSIL_TYPE_TRIBOOL_UNKNOWN;

    ASSUME_ITS_TRUE(fossil_type_tribool_and(t, t) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(t, u) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(u, t) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(u, u) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(f, t) == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(t, f) == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(f, u) == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(u, f) == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(fossil_type_tribool_and(f, f) == FOSSIL_TYPE_TRIBOOL_FALSE);
}

// Test: Tribool OR logic
FOSSIL_TEST(c_test_tribool_or_logic) {
    tribool t = FOSSIL_TYPE_TRIBOOL_TRUE;
    tribool f = FOSSIL_TYPE_TRIBOOL_FALSE;
    tribool u = FOSSIL_TYPE_TRIBOOL_UNKNOWN;

    ASSUME_ITS_TRUE(fossil_type_tribool_or(t, t) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(t, u) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(u, t) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(f, t) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(t, f) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(f, f) == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(f, u) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(u, f) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
    ASSUME_ITS_TRUE(fossil_type_tribool_or(u, u) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
}

// Test: Tribool NOT logic
FOSSIL_TEST(c_test_tribool_not_logic) {
    tribool t = FOSSIL_TYPE_TRIBOOL_TRUE;
    tribool f = FOSSIL_TYPE_TRIBOOL_FALSE;
    tribool u = FOSSIL_TYPE_TRIBOOL_UNKNOWN;

    ASSUME_ITS_TRUE(fossil_type_tribool_not(t) == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(fossil_type_tribool_not(f) == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(fossil_type_tribool_not(u) == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_tribool_tests) {
    FOSSIL_TEST_ADD(c_tribool_suite, c_test_tribool_constructors);
    FOSSIL_TEST_ADD(c_tribool_suite, c_test_tribool_predicates);
    FOSSIL_TEST_ADD(c_tribool_suite, c_test_tribool_and_logic);
    FOSSIL_TEST_ADD(c_tribool_suite, c_test_tribool_or_logic);
    FOSSIL_TEST_ADD(c_tribool_suite, c_test_tribool_not_logic);

    FOSSIL_TEST_REGISTER(c_tribool_suite);
}
