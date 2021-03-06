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

#include "segmenter.h"
#include <sstream>

#include <toynlp/util/util.h>

namespace toynlp {

std::string SegmenterOptions::ToString() const {
  std::stringstream ss;
  ss << NVC_(dict_path) << NV_(stopwords_path);
  return ss.str();
}

Segmenter::Segmenter() {
}

Segmenter::~Segmenter() {
}

bool Segmenter::Segment(const std::string& text,
    std::vector<std::string>* tokens) const {
  if (!tokens) return false;
  tokens->clear();
  // TODO
  for (std::size_t i = 0; i < text.size(); ++i) {
    tokens->push_back(std::string(1, text[i]));
  }
  return true;
}

bool Segmenter::Init(const SegmenterOptions& options) {
  options_ = options;
  return true;
}

bool Segmenter::Segment(const std::string& text,
    std::vector<Token>* tokens) const {
  if (!tokens) return false;
  tokens->clear();
  // TODO
  return true;
}

} /* namespace toynlp */
