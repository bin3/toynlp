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

#ifndef TOYNLP_UTIL_UTIL_H_
#define TOYNLP_UTIL_UTIL_H_

#include <fstream>
#include <string>

namespace toynlp {
namespace util {

#define NV_(v) #v << "=" << v
#define NVC_(v) NV_(v) << ", "
#define NVE_(v) NV_(v) << "\n"

template<typename Container>
bool ReadLines(const std::string& path, Container* c) {
  if (!c) return false;
  std::ifstream ifs(path);
  if (ifs) {
    std::string line;
    while (std::getline(ifs, line)) {
      while (line.size() && (line.back() == '\n' || line.back() == '\r')) {
        line.pop_back();
      }
      c->push_back(std::string());
      c->back().swap(line);
    }
    return true;
  }
  return false;
}

} /* namespace util */
} /* namespace toynlp */
#endif /* TOYNLP_UTIL_UTIL_H_ */
