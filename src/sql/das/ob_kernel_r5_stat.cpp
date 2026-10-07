/*
 * Copyright (c) 2025 OceanBase.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define USING_LOG_PREFIX SQL_DAS
#include "sql/das/ob_kernel_r5_stat.h"

namespace oceanbase
{
namespace sql
{
std::atomic<int64_t> KernelR5Stat::fill_ns_(0);
std::atomic<int64_t> KernelR5Stat::fill_rows_(0);
std::atomic<int64_t> KernelR5Stat::func_open_ns_(0);
std::atomic<int64_t> KernelR5Stat::func_get_ns_(0);
std::atomic<int64_t> KernelR5Stat::trm_get_ns_(0);
std::atomic<int64_t> KernelR5Stat::lookup_load_ns_(0);
std::atomic<int64_t> KernelR5Stat::lookup_proj_ns_(0);
std::atomic<int64_t> KernelR5Stat::scaniter_open_ns_(0);
std::atomic<int64_t> KernelR5Stat::scaniter_get_ns_(0);
std::atomic<int64_t> KernelR5Stat::bm25_ns_(0);
std::atomic<int64_t> KernelR5Stat::bm25_cnt_(0);
std::atomic<int64_t> KernelR5Stat::daat_get_ns_(0);
std::atomic<int64_t> KernelR5Stat::sync_rows_(0);
std::atomic<int64_t> KernelR5Stat::daat_fill_ns_(0);
std::atomic<int64_t> KernelR5Stat::daat_collect_ns_(0);
std::atomic<int64_t> KernelR5Stat::daat_filter_ns_(0);
std::atomic<int64_t> KernelR5Stat::daat_cache_ns_(0);
std::atomic<int64_t> KernelR5Stat::daat_rounds_(0);
std::atomic<int64_t> KernelR5Stat::dim_next_ns_(0);
std::atomic<int64_t> KernelR5Stat::dim_fast_cnt_(0);
std::atomic<int64_t> KernelR5Stat::dim_pull_ns_(0);
std::atomic<int64_t> KernelR5Stat::dim_pull_cnt_(0);
std::atomic<int64_t> KernelR5Stat::dim_save_ns_(0);
std::atomic<int64_t> KernelR5Stat::dim_last_count_(0);
std::atomic<int64_t> KernelR5Stat::est_ns_(0);
std::atomic<int64_t> KernelR5Stat::est_cnt_(0);
std::atomic<int64_t> KernelR5Stat::sync_skipped_(0);
}  // namespace sql
}  // namespace oceanbase
