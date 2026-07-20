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
 * Date: 04/05/2013
 *
 * Copyright (C) 2013-Current Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/type/feature.h"

/* Creation */
feature fossil_type_feature_make(const char* name, int enabled) {
    feature f;
    f.name = name;
    f.enabled = enabled ? 1 : 0;
    return f;
}

/* Operations */
int fossil_type_feature_is_enabled(const feature* f) {
    if (!f) return 0;
    return f->enabled ? 1 : 0;
}

void fossil_type_feature_enable(feature* f) {
    if (!f) return;
    f->enabled = 1;
}

void fossil_type_feature_disable(feature* f) {
    if (!f) return;
    f->enabled = 0;
}
