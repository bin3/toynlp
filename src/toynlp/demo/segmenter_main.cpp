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

#include <iostream>
#include <glog/logging.h>
#include <gflags/gflags.h>

#include <toynlp/seg/segmenter.h>
#include <toynlp/seg/fmm_segmenter.h>

void SegmenterDemo() {
  VLOG(0) << "[SegmenterDemo]";
  toynlp::SegmenterOptions options;
  toynlp::Segmenter seg;
  VLOG(0) << "SegmenterOptions: " << options.ToString();
  CHECK(seg.Init(options));

  std::string text = "Hello NLP";
  std::vector<std::string> tokens;
  VLOG(0) << "text: " << text;
  CHECK(seg.Segment(text, &tokens));
  for (std::size_t i = 0; i < tokens.size(); ++i) {
    VLOG(0) << "token#" << i << ": " << tokens[i];
  }
}

void FMMSegmenterDemo() {
  VLOG(0) << "[FMMSegmenterDemo]";
  toynlp::SegmenterOptions options;
  toynlp::FMMSegmenter seg;
  CHECK(seg.Init(options));

  std::string text = "2001年1月1日零时，随着新世纪钟声的响起，北京中华世纪坛礼花齐放，万民欢腾。";
  std::vector<std::string> tokens;
  VLOG(0) << "text: " << text;
  CHECK(seg.Segment(text, &tokens));
  for (std::size_t i = 0; i < tokens.size(); ++i) {
    VLOG(0) << "token#" << i << " " << tokens[i];
  }
}

int main(int argc, char **argv) {
  FLAGS_stderrthreshold = 0;
//  FLAGS_log_dir = "log/";
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);

  VLOG(0) << "------" << argv[0] << "------";
  SegmenterDemo();
  FMMSegmenterDemo();

  return 0;
}
