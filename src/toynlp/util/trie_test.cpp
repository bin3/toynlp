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

#include "trie.h"
#include <gtest/gtest.h>

namespace toynlp {

TEST(Trie, Match) {
  const int kN = 4;
  std::string patterns[kN] = {"abc", "ab", "bc", "c"};
  Trie<int, char> trie;
  for (int i = 0; i < kN; ++i) {
    trie.Insert(patterns[i].data(), patterns[i].size(), i);
  }
  int val = -1;
  for (int i = 0; i < kN; ++i) {
    EXPECT_TRUE(trie.Match(patterns[i].data(), patterns[i].size(), &val));
    EXPECT_EQ(i, val);
  }
  std::string newpatterns[kN] = {"abcd", "a", "", "ac"};
  for (int i = 0; i < kN; ++i) {
    EXPECT_FALSE(trie.Match(newpatterns[i].data(), newpatterns[i].size(), &val));
    trie.Insert(newpatterns[i].data(), newpatterns[i].size(), i + kN);
    EXPECT_TRUE(trie.Match(newpatterns[i].data(), newpatterns[i].size(), &val));
    EXPECT_EQ(i + kN, val);
  }
}

TEST(Trie, PrefixMatch) {
  const int kN = 4;
  std::string patterns[kN] = {"abc", "ab", "bc", "c"};
  Trie<int, char> trie;
  for (int i = 0; i < kN; ++i) {
    trie.Insert(patterns[i].data(), patterns[i].size(), i);
  }
  std::string text = "abcdef";
  std::vector<int> vals;
  ASSERT_TRUE(trie.PrefixMatch(text.data(), text.size(), &vals));
  ASSERT_EQ(2U, vals.size());
  EXPECT_EQ(1, vals[0]);
  EXPECT_EQ(0, vals[1]);
}

} /* namespace toynlp */
