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
FOSSIL_SUITE(c_feature_suite);

// Setup function for the test suite
FOSSIL_SETUP(c_feature_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(c_feature_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Feature constructors
FOSSIL_TEST(c_test_feature_constructors) {
    feature f1 = fossil_type_feature_make("alpha", 1);
    feature f2 = fossil_type_feature_make("beta", 0);

    ASSUME_ITS_TRUE(f1.enabled == 1);
    ASSUME_ITS_TRUE(f2.enabled == 0);
    ASSUME_ITS_TRUE(f1.name != NULL && strcmp(f1.name, "alpha") == 0);
    ASSUME_ITS_TRUE(f2.name != NULL && strcmp(f2.name, "beta") == 0);
}

// Test: Feature is_enabled predicate
FOSSIL_TEST(c_test_feature_is_enabled) {
    feature f1 = fossil_type_feature_make("gamma", 1);
    feature f2 = fossil_type_feature_make("delta", 0);

    ASSUME_ITS_TRUE(fossil_type_feature_is_enabled(&f1));
    ASSUME_ITS_FALSE(fossil_type_feature_is_enabled(&f2));
    ASSUME_ITS_FALSE(fossil_type_feature_is_enabled(NULL));
}

// Test: Feature enable operation
FOSSIL_TEST(c_test_feature_enable) {
    feature f = fossil_type_feature_make("epsilon", 0);
    fossil_type_feature_enable(&f);
    ASSUME_ITS_TRUE(f.enabled == 1);
    ASSUME_ITS_TRUE(fossil_type_feature_is_enabled(&f));

    // Should not crash or change anything if NULL
    fossil_type_feature_enable(NULL);
}

// Test: Feature disable operation
FOSSIL_TEST(c_test_feature_disable) {
    feature f = fossil_type_feature_make("zeta", 1);
    fossil_type_feature_disable(&f);
    ASSUME_ITS_TRUE(f.enabled == 0);
    ASSUME_ITS_FALSE(fossil_type_feature_is_enabled(&f));

    // Should not crash or change anything if NULL
    fossil_type_feature_disable(NULL);
}

// Test: Feature enable/disable toggle
FOSSIL_TEST(c_test_feature_toggle) {
    feature f = fossil_type_feature_make("theta", 0);
    ASSUME_ITS_FALSE(fossil_type_feature_is_enabled(&f));
    fossil_type_feature_enable(&f);
    ASSUME_ITS_TRUE(fossil_type_feature_is_enabled(&f));
    fossil_type_feature_disable(&f);
    ASSUME_ITS_FALSE(fossil_type_feature_is_enabled(&f));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_feature_tests) {
    FOSSIL_TEST_ADD(c_feature_suite, c_test_feature_constructors);
    FOSSIL_TEST_ADD(c_feature_suite, c_test_feature_is_enabled);
    FOSSIL_TEST_ADD(c_feature_suite, c_test_feature_enable);
    FOSSIL_TEST_ADD(c_feature_suite, c_test_feature_disable);
    FOSSIL_TEST_ADD(c_feature_suite, c_test_feature_toggle);

    FOSSIL_TEST_REGISTER(c_feature_suite);
}
