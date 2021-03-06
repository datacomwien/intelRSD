/*!
 * @brief Implementation of NvmeContext class.
 *
 * @header{License}
 * @copyright Copyright (c) 2017-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @header{Files}
 * @file nvme_context.cpp
 */

#include "tools/nvme_context.hpp"
#include "tools/nvme_database.hpp"
#include "tools/unix_dir.hpp"

using namespace agent::nvme::tools;
using namespace std;

NvmeContext::~NvmeContext() {}

Context::DatabasePtr NvmeContext::create_database(const Uuid& resource, const string& name) const {
    DatabasePtr db{new NvmeDatabase(resource, name)};
    return db;
}

Context::DirPtr NvmeContext::create_dir() const {
    DirPtr dir{new UnixDir()};
    return dir;
}

