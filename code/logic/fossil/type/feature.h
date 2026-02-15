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
#ifndef FOSSIL_TYPE_FEATURE_H
#define FOSSIL_TYPE_FEATURE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct fossil_type_feature {
    const char* name;
    int enabled;
} fossil_type_feature;

typedef fossil_type_feature feature;

/* Creation */
feature fossil_type_feature_make(const char* name, int enabled);

/* Operations */
int fossil_type_feature_is_enabled(const feature* f);
void fossil_type_feature_enable(feature* f);
void fossil_type_feature_disable(feature* f);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
namespace fossil::type {

class Feature {
    feature f;
public:
    Feature(const char* n,bool e=false){ f=fossil_type_feature_make(n,e); }

    bool enabled() const { return fossil_type_feature_is_enabled(&f); }
    void enable(){ fossil_type_feature_enable(&f); }
    void disable(){ fossil_type_feature_disable(&f); }
};

}
#endif

#endif
