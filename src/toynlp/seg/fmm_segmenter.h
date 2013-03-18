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
 * @date		2013-3-17
 */

#ifndef TOYNLP_SEG_FMM_SEGMENTER_H_
#define TOYNLP_SEG_FMM_SEGMENTER_H_

#include <toynlp/util/trie.h>
#include "segmenter.h"

namespace toynlp {

/**
 * @brief Forward Maximum Matching Segmenter
 */
class FMMSegmenter: public Segmenter {
public:
  FMMSegmenter();
  virtual ~FMMSegmenter();

  bool Init(const SegmenterOptions& options);
  virtual bool Segment(const std::string& text,
      std::vector<std::string>* tokens) const;
  virtual bool Segment(const std::string& text,
      std::vector<Token>* tokens) const;
private:
  typedef Trie<std::size_t, char> WordTrie;
  std::vector<std::string> words_;
  WordTrie trie_;
};

} /* namespace toynlp */
#endif /* TOYNLP_SEG_FMM_SEGMENTER_H_ */
