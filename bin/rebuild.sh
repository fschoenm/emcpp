#!/bin/sh

pushd ../build
make
returnCode=$?
popd

exit $returnCode