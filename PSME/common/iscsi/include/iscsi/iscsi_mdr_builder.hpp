/*!
 * @brief iSCSI MDR v1.0 attempt region builder.
 *
 * @copyright Copyright (c) 2017 Intel Corporation
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
 * @file iscsi_entry_builder.hpp
 */

#pragma once

#include "ipmi/ipmi_interface.hpp"
#include "iscsi/iscsi_mdr_initiator_builder.hpp"
#include "iscsi/iscsi_mdr_version_builder.hpp"
#include "iscsi/iscsi_mdr_target_builder.hpp"
#include "iscsi/iscsi_mdr_attempt_builder.hpp"

namespace iscsi {
namespace builder {

/*!
 * @brief The builder for the whole iSCSI MDR region v1.0.
 */
class IscsiMdrBuilder final {
public:

    /*!
     * @brief Deleted constructor.
     */
    IscsiMdrBuilder() = delete;

    /*!
     * @brief Build and append a whole iSCSI MDR v1.0 region.
     *
     * @param buffer the buffer to append the structure to.
     * @param device_functions the network device functions context to build from.
     * @param conn_wait the attempt timeout in milliseconds.
     * @param retry_count the attempt retry count.
     */
    template<typename DevFuncCtx>
    static void build(ipmi::IpmiInterface::ByteBuffer& buffer, const DevFuncCtx& ctx, uint16_t conn_wait,
        uint8_t retry_count) {
        uint16_t current_handle = {1}; // zero is reserved for the version structure
        auto handle_inc = [&current_handle] () -> uint16_t {return current_handle++;};

        // the current design only accepts one of each initiator, target, attempt
        IscsiVersionBuilder::append_structure(buffer, nullptr);
        auto initiator_handle = current_handle;
        IscsiInitiatorBuilder::append_structure(buffer, ctx, handle_inc);
        auto target_handle = current_handle;
        IscsiTargetBuilder::append_structure(buffer, ctx, handle_inc);
        IscsiAttemptBuilder::append_structure(buffer, initiator_handle, target_handle, conn_wait, retry_count,
            handle_inc);
    }

    /*!
     * @brief Build and append a structure to clear the iSCSI MDR v1.0 region.
     *
     * @param buffer the buffer to append the structure to.
     * @param device_functions the network device functions context to build from.
     */
    template<typename DevFuncCtx>
    static void clear(ipmi::IpmiInterface::ByteBuffer& buffer, const DevFuncCtx&) {

        // a single valid version structure clears the iSCSI boot options
        IscsiVersionBuilder::append_structure(buffer, nullptr);
    }
};

}  // namespace builder
}  // namespace iscsi