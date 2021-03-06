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

add_library(storage-command-conf-based-ref OBJECT
    get_managers_collection.cpp
    get_tasks_collection.cpp
    get_manager_info.cpp
    get_chassis_info.cpp
    get_system_info.cpp
    get_network_interface_info.cpp
    get_drive_info.cpp
    get_storage_service_info.cpp
    get_collection.cpp
    get_task_info.cpp
    get_task_result_info.cpp
    get_metric_definition_info.cpp
    get_metric_definitions_collection.cpp
    get_metrics.cpp
    get_fabric_info.cpp
    get_zone_info.cpp
    get_endpoint_info.cpp
    get_storage_pool_info.cpp
    get_volume_info.cpp
    delete_task.cpp
    add_volume.cpp
    delete_volume.cpp
    add_endpoint.cpp
    delete_endpoint.cpp
    add_zone.cpp
    delete_zone.cpp
    add_zone_endpoints.cpp
    delete_zone_endpoints.cpp

    set_component_attributes.cpp
    set_endpoint_attributes.cpp
    set_volume_attributes.cpp
    set_chassis_attributes.cpp
)

set_psme_command_target_properties(storage-command-conf-based-ref)
