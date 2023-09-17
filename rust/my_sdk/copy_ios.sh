#! /bin/bash
LIB_NAME="MySdk"

cp -r $LIB_NAME.xcframework ../../packages/v8-module-cpp/platforms/ios
rm -rf $LIB_NAME.xcframework
rm simulator_fat/libmy_sdk.dylib
