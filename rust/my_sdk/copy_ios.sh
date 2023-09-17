#! /bin/bash
LIB_NAME="my_sdk"
FRAMEWORK="MySdk"

cp -r $FRAMEWORK.xcframework ../../packages/v8-module-cpp/platforms/ios
rm -rf $FRAMEWORK.xcframework
rm simulator_fat/lib$LIB_NAME.dylib
