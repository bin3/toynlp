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

#ifndef TOYNLP_UTIL_TRIE_H_
#define TOYNLP_UTIL_TRIE_H_

#include <string>
#include <deque>
#include <tr1/unordered_map>

namespace toynlp {

/**
 * @brief Trie
 */
template<typename Value, typename Char = char, typename Index = uint32_t>
class Trie {
public:
  typedef std::tr1::unordered_map<Char, Index> Char2Index;
  struct Node {
    Node(Char lab = 0) :
        label(lab), final(false) {
    }
    Char label;
    Value val;
    bool final;
    Char2Index l2c; // label to child
  };
  Trie() {
    Clear();
  }
  virtual ~Trie() {
  }

  /**
   * Insert a pattern
   * @param s
   * @param n
   * @param val
   */
  void Insert(const Char* s, std::size_t n, Value val) {
    Index cur = kRoot;
    for (size_t i = 0; i < n; ++i) {
      cur = FindOrAdd(cur, s[i]);
    }
    Node& nod = GetNode(cur);
    nod.final = true;
    nod.val = val;
  }
  /**
   * Totally match the given string with a pattern
   * @param s
   * @param n
   * @param val
   * @return true if totally matched
   */
  bool Match(const Char* s, std::size_t n, Value* val = NULL) {
    Index cur = kRoot;
    for (size_t i = 0; i < n; ++i) {
      cur = Find(cur, s[i]);
      if (cur == kNull) return false;
    }
    Node& nod = GetNode(cur);
    if (nod.final) {
      if (val) *val = nod.val;
      return true;
    }
    return false;
  }
  /**
   * Find all the patterns matched by the prefix of the given string
   * @param s
   * @param n
   * @param c the container to contain all the values related to matched patterns
   * @return true if matched any one pattern
   */
  template<typename Container>
  bool PrefixMatch(const Char* s, std::size_t n, Container* c = NULL) {
    bool matched = false;
    Index cur = kRoot;
    for (size_t i = 0; i < n; ++i) {
      cur = Find(cur, s[i]);
      Node& nod = GetNode(cur);
      if (nod.final) {
        matched = true;
        if (c) c->push_back(nod.val);
      }
      if (cur == kNull) break;
    }
    return matched;
  }
  std::size_t NumNodes() const {
    return nodes_.size() - kRoot;
  }
  void Swap(const Trie<Value, Char, Index>& other) {
    std::swap(nodes_, other.nodes_);
  }
  void Clear() {
    nodes_.clear();
    while (nodes_.size() <= kRoot) {
      NewNode();
    }
  }
private:
  const static uint32_t kNull = 0;
  const static uint32_t kRoot = 1;

  std::deque<Node> nodes_;

  Index NewNode(Char label = 0) {
    nodes_.push_back(Node(label));
    return nodes_.size() - 1;
  }
  Node& GetNode(Index idx) {
    return nodes_[idx];
  }
  Index FindOrAdd(Index parent, Char label) {
    Node& p = GetNode(parent);
    if (!p.l2c.count(label)) {
      p.l2c[label] = NewNode(label);
    }
    return p.l2c[label];
  }
  Index Find(Index parent, Char label) {
    Node& p = GetNode(parent);
    typename Char2Index::iterator i = p.l2c.find(label);
    if (i != p.l2c.end())
      return i->second;
    else
      return kNull;
  }
};

} /* namespace toynlp */
#endif /* TOYNLP_UTIL_TRIE_H_ */
