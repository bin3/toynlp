#!/usr/bin/env sh

cd ../build
make
if [ $? -ne 0 ]
then
    echo "---make failed---"
    exit 1
fi

cd ../bin

#./segmenter_main
./trie_test
