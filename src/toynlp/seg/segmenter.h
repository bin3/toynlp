/*
 * Copyright (c) 2013 Binson Zhang.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2013-3-16
 */

#ifndef TOYNLP_SEG_SEGMENTER_H_
#define TOYNLP_SEG_SEGMENTER_H_

#include <string>
#include <vector>

#include "token.h"

namespace toynlp {

struct SegmenterOptions {
  std::string dict_path;
  std::string stopwords_path;
  SegmenterOptions() :
      dict_path("../data/dict/dict.txt"), stopwords_path(
          "../data/dict/stopwords.txt") {
  }
  std::string ToString() const;
};

/**
 * @brief 
 */
class Segmenter {
public:
  Segmenter();
  virtual ~Segmenter();

  bool Init(const SegmenterOptions& options);
  bool Segment(const std::string& text, std::vector<std::string>* tokens) const;
  bool Segment(const std::string& text, std::vector<Token>* tokens) const;
private:
  SegmenterOptions options_;
};

} /* namespace toynlp */
#endif /* TOYNLP_SEG_SEGMENTER_H_ */
