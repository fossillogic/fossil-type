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
#ifndef FOSSIL_TYPE_TRIBOOL_H
#define FOSSIL_TYPE_TRIBOOL_H

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================
 * Type Definition
 * ====================================================== */

typedef enum fossil_type_tribool {
    FOSSIL_TYPE_TRIBOOL_FALSE = 0,
    FOSSIL_TYPE_TRIBOOL_TRUE  = 1,
    FOSSIL_TYPE_TRIBOOL_UNKNOWN = 2
} fossil_type_tribool;

typedef fossil_type_tribool tribool;

/* ======================================================
 * Constructors
 * ====================================================== */

/**
 * @brief Constructs a tribool with the value TRUE.
 * @return tribool representing TRUE.
 */
tribool fossil_type_tribool_make_true(void);

/**
 * @brief Constructs a tribool with the value FALSE.
 * @return tribool representing FALSE.
 */
tribool fossil_type_tribool_make_false(void);

/**
 * @brief Constructs a tribool with the value UNKNOWN.
 * @return tribool representing UNKNOWN.
 */
tribool fossil_type_tribool_make_unknown(void);

/* ======================================================
 * Predicates
 * ====================================================== */

/**
 * @brief Checks if the given tribool is TRUE.
 * @param t The tribool value to check.
 * @return Non-zero if t is TRUE, zero otherwise.
 */
int fossil_type_tribool_is_true(tribool t);

/**
 * @brief Checks if the given tribool is FALSE.
 * @param t The tribool value to check.
 * @return Non-zero if t is FALSE, zero otherwise.
 */
int fossil_type_tribool_is_false(tribool t);

/**
 * @brief Checks if the given tribool is UNKNOWN.
 * @param t The tribool value to check.
 * @return Non-zero if t is UNKNOWN, zero otherwise.
 */
int fossil_type_tribool_is_unknown(tribool t);

/* ======================================================
 * Logic
 * ====================================================== */

/**
 * @brief Performs logical AND on two tribool values.
 * @param a The first tribool operand.
 * @param b The second tribool operand.
 * @return Resulting tribool after logical AND.
 */
tribool fossil_type_tribool_and(tribool a, tribool b);

/**
 * @brief Performs logical OR on two tribool values.
 * @param a The first tribool operand.
 * @param b The second tribool operand.
 * @return Resulting tribool after logical OR.
 */
tribool fossil_type_tribool_or (tribool a, tribool b);

/**
 * @brief Performs logical NOT on a tribool value.
 * @param t The tribool operand.
 * @return Resulting tribool after logical NOT.
 */
tribool fossil_type_tribool_not(tribool t);

#ifdef __cplusplus
}
#endif


/* ======================================================
 * C++ Wrapper
 * ====================================================== */
#ifdef __cplusplus

namespace fossil::type {

class Tribool {
    tribool value;

public:
    /**
     * @brief Default constructor. Initializes the Tribool to UNKNOWN.
     */
    Tribool() : value(fossil_type_tribool_make_unknown()) {}

    /**
     * @brief Constructs a Tribool from a given tribool value.
     * @param v The tribool value to initialize with.
     */
    explicit Tribool(tribool v) : value(v) {}

    /**
     * @brief Checks if the Tribool is TRUE.
     * @return true if the value is TRUE, false otherwise.
     */
    bool is_true() const    { return fossil_type_tribool_is_true(value); }

    /**
     * @brief Checks if the Tribool is FALSE.
     * @return true if the value is FALSE, false otherwise.
     */
    bool is_false() const   { return fossil_type_tribool_is_false(value); }

    /**
     * @brief Checks if the Tribool is UNKNOWN.
     * @return true if the value is UNKNOWN, false otherwise.
     */
    bool is_unknown() const { return fossil_type_tribool_is_unknown(value); }

    /**
     * @brief Logical NOT operator for Tribool.
     * @return A new Tribool representing the logical NOT of this value.
     */
    Tribool operator!() const {
        return Tribool(fossil_type_tribool_not(value));
    }

    /**
     * @brief Logical AND operator for Tribool.
     * @param rhs The right-hand side Tribool operand.
     * @return A new Tribool representing the logical AND of this and rhs.
     */
    Tribool operator&&(const Tribool& rhs) const {
        return Tribool(fossil_type_tribool_and(value, rhs.value));
    }

    /**
     * @brief Logical OR operator for Tribool.
     * @param rhs The right-hand side Tribool operand.
     * @return A new Tribool representing the logical OR of this and rhs.
     */
    Tribool operator||(const Tribool& rhs) const {
        return Tribool(fossil_type_tribool_or(value, rhs.value));
    }

    operator tribool() const { return value; }
};

} // namespace fossil::type

#endif

#endif
