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

#include "fmm_segmenter.h"
#include <glog/logging.h>

#include <toynlp/util/util.h>

namespace toynlp {

FMMSegmenter::FMMSegmenter() {
}

FMMSegmenter::~FMMSegmenter() {
}

bool FMMSegmenter::Init(const SegmenterOptions& options) {
  Segmenter::Init(options);
  std::vector<std::string> words;
  if (!util::ReadLines(options.dict_path, &words)) {
    LOG(ERROR) << "Failed to read dictionary file: " << options.dict_path;
    return false;
  }
  VLOG(1) << "Read " << words.size() << " words";
  WordTrie trie;
  for (std::size_t i = 0; i < words.size(); ++i) {
    trie.Insert(words[i].data(), words[i].size(), i);
  }
  VLOG(1) << "Finished inserting Trie";
  words_.swap(words);
  trie_.Swap(trie);
  return true;
}

bool FMMSegmenter::Segment(const std::string& text,
    std::vector<std::string>* tokens) const {
  std::vector<std::size_t> ids;
  for (std::size_t i = 0; i < text.size(); ) {
    ids.clear();
    if (trie_.PrefixMatch(text.data() + i, text.size() - i, &ids)) {
      const std::string& token = words_[ids.back()];
      tokens->push_back(token);
      i += token.size();
    } else {
      // TODO
      std::size_t len = (text[i] >= 0) ? 1 : 2;
      tokens->push_back(text.substr(i, len));
      i += len;
    }
  }
  return true;
}

bool FMMSegmenter::Segment(const std::string& text,
    std::vector<Token>* tokens) const {
  return true;
}

} /* namespace toynlp */
