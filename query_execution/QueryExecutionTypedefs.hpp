/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
 *   Copyright 2015-2016 Pivotal Software, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#ifndef QUICKSTEP_QUERY_EXECUTION_QUERY_EXECUTION_TYPEDEFS_HPP_
#define QUICKSTEP_QUERY_EXECUTION_QUERY_EXECUTION_TYPEDEFS_HPP_

#include <cstddef>

#include "tmb/address.h"
#include "tmb/id_typedefs.h"
#include "tmb/message_style.h"
#include "tmb/pure_memory_message_bus.h"
#include "tmb/tagged_message.h"

namespace quickstep {

/** \addtogroup QueryExecution
 *  @{
 */

constexpr std::size_t kInvalidShiftbossIndex = static_cast<std::size_t>(-1);

typedef tmb::Address Address;
typedef tmb::AnnotatedMessage AnnotatedMessage;
typedef tmb::MessageBus MessageBus;
typedef tmb::MessageStyle MessageStyle;
typedef tmb::Priority Priority;
typedef tmb::PureMemoryMessageBus<false> MessageBusImpl;
typedef tmb::TaggedMessage TaggedMessage;
typedef tmb::client_id client_id;
typedef tmb::message_type_id message_type_id;

enum QueryExecutionMessageType : message_type_id {
  kShiftbossRegistrationMessage,
  kShiftbossRegistrationResponseMessage,
  kDistributedCliRegistrationMessage,
  kDistributedCliRegistrationResponseMessage,
  kSqlQueryMessage,
  kShiftbossInitiateMessage,
  kShiftbossInitiateResponseMessage,
  kWorkOrderMessage,  // From Foreman to Worker.
  kWorkOrderCompleteMessage,  // From Worker to Foreman.
  kInitiateRebuildMessage,
  kInitiateRebuildResponseMessage,
  kCatalogRelationNewBlockMessage,  // From InsertDestination to Foreman.
  kDataPipelineMessage,  // From InsertDestination or some WorkOrders to Foreman.
  kWorkOrdersAvailableMessage,  // From some WorkOrders to Foreman.
  kWorkOrderFeedbackMessage,  // From some WorkOrders to Foreman on behalf of
                              // their corresponding RelationalOperators.
  kRebuildWorkOrderMessage,  // From Foreman to Worker.
  kRebuildWorkOrderCompleteMessage,  // From Worker to Foreman.
  kQueryExecutionSuccessMessage,
  kQueryExecutionErrorMessage,
  kQueryResultRelationMessage,
  kQueryResultRelationResponseMessage,
  kPoisonMessage,  // From the CLI shell to Foreman, then from Foreman to Workers.

  // BlockLocator related messages used only in the distributed version.
  kBlockDomainRegistrationMessage,  // From Worker to BlockLocator.
  kBlockDomainRegistrationResponseMessage,  // From BlockLocator to Worker.
  kAddBlockLocationMessage,  // From StorageManager to BlockLocator.
  kAddBlockLocationResponseMessage,  // From BlockLocator to StorageManager.
  kDeleteBlockLocationMessage,  // From StorageManager to BlockLocator.
  kDeleteBlockLocationResponseMessage,  // From BlockLocator to StorageManager.
  kLocateBlockMessage,  // From StorageManager to BlockLocator.
  kLocateBlockResponseMessage,  // From BlockLocator to StorageManager.
  kGetDomainNetworkInfoMessage,  // From StorageManager to BlockLocator.
  kGetDomainNetworkInfoResponseMessage,  // From BlockLocator to StorageManager.
  kBlockDomainUnregistrationMessage,  // From Worker to BlockLocator.
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_QUERY_EXECUTION_QUERY_EXECUTION_TYPEDEFS_HPP_
