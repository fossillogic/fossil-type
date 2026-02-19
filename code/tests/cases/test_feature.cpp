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
FOSSIL_SUITE(cpp_feature_suite);

// Setup function for the test suite
FOSSIL_SETUP(cpp_feature_suite) {
    // Setup code here
}

// Teardown function for the test suite
FOSSIL_TEARDOWN(cpp_feature_suite) {
    // Teardown code here
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test: Feature class constructors and initial state
FOSSIL_TEST(cpp_test_Feature_class_constructors) {
    fossil::type::Feature feat1("omega", true);
    fossil::type::Feature feat2("psi");

    ASSUME_ITS_TRUE(feat1.enabled());
    ASSUME_ITS_FALSE(feat2.enabled());
}

// Test: Feature class enable/disable methods
FOSSIL_TEST(cpp_test_Feature_class_enable_disable) {
    fossil::type::Feature feat("lambda");
    ASSUME_ITS_FALSE(feat.enabled());

    feat.enable();
    ASSUME_ITS_TRUE(feat.enabled());

    feat.disable();
    ASSUME_ITS_FALSE(feat.enabled());
}

// Test: Feature class multiple enable/disable calls
FOSSIL_TEST(cpp_test_Feature_class_multiple_enable_disable) {
    fossil::type::Feature feat("sigma");

    feat.enable();
    feat.enable();
    ASSUME_ITS_TRUE(feat.enabled());

    feat.disable();
    feat.disable();
    ASSUME_ITS_FALSE(feat.enabled());
}

// Test: Feature class independent instances
FOSSIL_TEST(cpp_test_Feature_class_independent_instances) {
    fossil::type::Feature featA("alpha", true);
    fossil::type::Feature featB("beta", false);

    ASSUME_ITS_TRUE(featA.enabled());
    ASSUME_ITS_FALSE(featB.enabled());

    featB.enable();
    ASSUME_ITS_TRUE(featB.enabled());
    ASSUME_ITS_TRUE(featA.enabled());

    featA.disable();
    ASSUME_ITS_FALSE(featA.enabled());
    ASSUME_ITS_TRUE(featB.enabled());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_feature_tests) {
    FOSSIL_TEST_ADD(cpp_feature_suite, cpp_test_Feature_class_constructors);
    FOSSIL_TEST_ADD(cpp_feature_suite, cpp_test_Feature_class_enable_disable);
    FOSSIL_TEST_ADD(cpp_feature_suite, cpp_test_Feature_class_multiple_enable_disable);
    FOSSIL_TEST_ADD(cpp_feature_suite, cpp_test_Feature_class_independent_instances);

    FOSSIL_TEST_REGISTER(cpp_feature_suite);
}
