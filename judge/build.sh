#!/usr/bin/env bash

for f in **/*.judge.cpp; do
    pushd `dirname $f` > /dev/null
    src=`basename $f`
    g++ $src -o ${src/.cpp/}
    popd > /dev/null
done
