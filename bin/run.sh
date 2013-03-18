#!/usr/bin/env sh

cd ../build
make
if [ $? -ne 0 ]
then
    echo "---make failed---"
    exit 1
fi

cd ../bin

#./trie_test
./fmm_segmenter_test
#./segmenter_main --log_dir=log/ --v=4
