# <license_header>
#
# Copyright (c) 2015-2018 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# </license_header>

set(SOURCES
    lvm_api.cpp
    lvm_attribute.cpp
    lvm_clone_task.cpp
    lvm_discovery.cpp

    model/logical_volume.cpp
    model/volume_group.cpp
    model/physical_volume.cpp
    model/creation_data.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    set_source_files_properties(
        lvm_discovery.cpp
        PROPERTIES COMPILE_FLAGS "-Wno-old-style-cast"
    )
endif()


add_library(lvm-api-ref OBJECT ${SOURCES})
