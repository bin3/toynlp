add_lib(segmenter "token.cpp segmenter.cpp fmm_segmenter.cpp" "")

add_test(segmenter_test "segmenter")
add_test(fmm_segmenter_test "segmenter")
