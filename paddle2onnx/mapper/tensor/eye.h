// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <string>
#include <vector>

#include "paddle2onnx/mapper/mapper.h"

namespace paddle2onnx {

class EyeMapper : public Mapper {
 public:
  EyeMapper(const PaddleParser& p, OnnxHelper* helper, int64_t block_id,
            int64_t op_id)
      : Mapper(p, helper, block_id, op_id) {}
  int32_t GetMinOpsetVersion(bool verbose) override;
  void Opset9() override;

 private:
  void ParseValue(const TensorInfo& tensor_info, int64_t* num_val);
  int64_t num_rows_;
  int64_t num_columns_;
};

}  // namespace paddle2onnx
