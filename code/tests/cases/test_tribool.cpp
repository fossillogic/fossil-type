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
FOSSIL_SUITE(cpp_tribool_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_tribool_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_tribool_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Tribool class default constructor
FOSSIL_TEST(cpp_test_Tribool_default_constructor) {
    fossil::type::Tribool t;
    ASSUME_ITS_TRUE(t.is_unknown());
    ASSUME_ITS_FALSE(t.is_true());
    ASSUME_ITS_FALSE(t.is_false());
}

// Test: Tribool class explicit value constructor
FOSSIL_TEST(cpp_test_Tribool_value_constructor) {
    fossil::type::Tribool t_true(FOSSIL_TYPE_TRIBOOL_TRUE);
    fossil::type::Tribool t_false(FOSSIL_TYPE_TRIBOOL_FALSE);
    fossil::type::Tribool t_unknown(FOSSIL_TYPE_TRIBOOL_UNKNOWN);

    ASSUME_ITS_TRUE(t_true.is_true());
    ASSUME_ITS_TRUE(t_false.is_false());
    ASSUME_ITS_TRUE(t_unknown.is_unknown());
}

// Test: Tribool class is_true/is_false/is_unknown
FOSSIL_TEST(cpp_test_Tribool_predicates) {
    fossil::type::Tribool t(FOSSIL_TYPE_TRIBOOL_TRUE);
    fossil::type::Tribool f(FOSSIL_TYPE_TRIBOOL_FALSE);
    fossil::type::Tribool u(FOSSIL_TYPE_TRIBOOL_UNKNOWN);

    ASSUME_ITS_TRUE(t.is_true());
    ASSUME_ITS_FALSE(t.is_false());
    ASSUME_ITS_FALSE(t.is_unknown());

    ASSUME_ITS_TRUE(f.is_false());
    ASSUME_ITS_FALSE(f.is_true());
    ASSUME_ITS_FALSE(f.is_unknown());

    ASSUME_ITS_TRUE(u.is_unknown());
    ASSUME_ITS_FALSE(u.is_true());
    ASSUME_ITS_FALSE(u.is_false());
}

// Test: Tribool class logical NOT operator
FOSSIL_TEST(cpp_test_Tribool_not_operator) {
    fossil::type::Tribool t(FOSSIL_TYPE_TRIBOOL_TRUE);
    fossil::type::Tribool f(FOSSIL_TYPE_TRIBOOL_FALSE);
    fossil::type::Tribool u(FOSSIL_TYPE_TRIBOOL_UNKNOWN);

    ASSUME_ITS_TRUE((!t).is_false());
    ASSUME_ITS_TRUE((!f).is_true());
    ASSUME_ITS_TRUE((!u).is_unknown());
}

// Test: Tribool class logical AND operator
FOSSIL_TEST(cpp_test_Tribool_and_operator) {
    using fossil::type::Tribool;
    Tribool t(FOSSIL_TYPE_TRIBOOL_TRUE);
    Tribool f(FOSSIL_TYPE_TRIBOOL_FALSE);
    Tribool u(FOSSIL_TYPE_TRIBOOL_UNKNOWN);

    ASSUME_ITS_TRUE((t && t).is_true());
    ASSUME_ITS_TRUE((t && u).is_unknown());
    ASSUME_ITS_TRUE((u && t).is_unknown());
    ASSUME_ITS_TRUE((u && u).is_unknown());
    ASSUME_ITS_TRUE((f && t).is_false());
    ASSUME_ITS_TRUE((t && f).is_false());
    ASSUME_ITS_TRUE((f && u).is_false());
    ASSUME_ITS_TRUE((u && f).is_false());
    ASSUME_ITS_TRUE((f && f).is_false());
}

// Test: Tribool class logical OR operator
FOSSIL_TEST(cpp_test_Tribool_or_operator) {
    using fossil::type::Tribool;
    Tribool t(FOSSIL_TYPE_TRIBOOL_TRUE);
    Tribool f(FOSSIL_TYPE_TRIBOOL_FALSE);
    Tribool u(FOSSIL_TYPE_TRIBOOL_UNKNOWN);

    ASSUME_ITS_TRUE((t || t).is_true());
    ASSUME_ITS_TRUE((t || u).is_true());
    ASSUME_ITS_TRUE((u || t).is_true());
    ASSUME_ITS_TRUE((f || t).is_true());
    ASSUME_ITS_TRUE((t || f).is_true());
    ASSUME_ITS_TRUE((f || f).is_false());
    ASSUME_ITS_TRUE((f || u).is_unknown());
    ASSUME_ITS_TRUE((u || f).is_unknown());
    ASSUME_ITS_TRUE((u || u).is_unknown());
}

// Test: Tribool class conversion to tribool
FOSSIL_TEST(cpp_test_Tribool_conversion_operator) {
    using fossil::type::Tribool;
    Tribool t(FOSSIL_TYPE_TRIBOOL_TRUE);
    Tribool f(FOSSIL_TYPE_TRIBOOL_FALSE);
    Tribool u(FOSSIL_TYPE_TRIBOOL_UNKNOWN);

    tribool raw_t = t;
    tribool raw_f = f;
    tribool raw_u = u;

    ASSUME_ITS_TRUE(raw_t == FOSSIL_TYPE_TRIBOOL_TRUE);
    ASSUME_ITS_TRUE(raw_f == FOSSIL_TYPE_TRIBOOL_FALSE);
    ASSUME_ITS_TRUE(raw_u == FOSSIL_TYPE_TRIBOOL_UNKNOWN);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tribool_tests) {
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_default_constructor);
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_value_constructor);
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_predicates);
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_not_operator);
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_and_operator);
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_or_operator);
    FOSSIL_TEST_ADD(cpp_tribool_suite, cpp_test_Tribool_conversion_operator);

    FOSSIL_TEST_REGISTER(cpp_tribool_suite);
}
