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

#ifndef OCEANBASE_SQL_DAS_OB_KERNEL_R5_STAT_H_
#define OCEANBASE_SQL_DAS_OB_KERNEL_R5_STAT_H_

#include <stdint.h>

namespace oceanbase
{
namespace sql
{
// KERNEL_R5(experiment): global cumulative counters for per-layer latency attribution.
// Values are cumulative across the process; per-query cost = delta between consecutive
// KERNEL_R5 dump lines (each dump is emitted per query at FuncData release).
struct KernelR5Stat
{
  static std::atomic<int64_t> fill_ns_;          // DAS scan op fill_task_result (inclusive)
  static std::atomic<int64_t> fill_rows_;
  static std::atomic<int64_t> func_open_ns_;     // FuncData do_table_scan + rescan
  static std::atomic<int64_t> func_get_ns_;      // FuncData inner_get_next_row(s) (inclusive)
  static std::atomic<int64_t> trm_get_ns_;       // TRMergeIter inner_get_next_row(s) (inclusive)
  static std::atomic<int64_t> lookup_load_ns_;   // SRSortedLookupIter::load_results (inclusive)
  static std::atomic<int64_t> lookup_proj_ns_;   // SRLookupIter::project_results (inclusive)
  static std::atomic<int64_t> scaniter_open_ns_; // DASScanIter do_table_scan + rescan
  static std::atomic<int64_t> scaniter_get_ns_;  // DASScanIter inner_get_next_row(s) (inclusive)
  static std::atomic<int64_t> bm25_ns_;          // BM25 expr eval (single + batch)
  static std::atomic<int64_t> bm25_cnt_;
  static std::atomic<int64_t> daat_get_ns_;      // DAAT merge iter pulls (inside load_results)
  static std::atomic<int64_t> sync_rows_;        // rows processed in the load_results sync loop
  static std::atomic<int64_t> daat_fill_ns_;     // DAAT fill_merge_heap (inclusive)
  static std::atomic<int64_t> daat_collect_ns_;  // DAAT collect_dims_by_id (inclusive)
  static std::atomic<int64_t> daat_filter_ns_;   // DAAT filter_on_demand (inclusive)
  static std::atomic<int64_t> daat_cache_ns_;    // DAAT cache_result (inclusive)
  static std::atomic<int64_t> daat_rounds_;      // DAAT do_one_merge_round count
  static std::atomic<int64_t> dim_next_ns_;      // DaaT dim iter get_next_row (inclusive)
  static std::atomic<int64_t> dim_fast_cnt_;     // fast path hits (row within buffer)
  static std::atomic<int64_t> dim_pull_ns_;      // pull branch time (token_iter get_next_row/batch)
  static std::atomic<int64_t> dim_pull_cnt_;     // pull branch hits
  static std::atomic<int64_t> dim_save_ns_;      // save_relevances/docids time
  static std::atomic<int64_t> dim_last_count_;   // count_ after last pull
  static std::atomic<int64_t> est_ns_;           // estimate_token_doc_cnt total
  static std::atomic<int64_t> est_cnt_;          // estimate calls
  static std::atomic<int64_t> sync_skipped_;     // merge rows skipped by merge-join tolerance
};
}  // namespace sql
}  // namespace oceanbase

#endif  // OCEANBASE_SQL_DAS_OB_KERNEL_R5_STAT_H_
