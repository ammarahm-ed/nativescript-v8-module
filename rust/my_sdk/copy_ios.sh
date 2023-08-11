#! /bin/bash
LIB_NAME="MySdk"

cp -r $LIB_NAME.xcframework ../../packages/v8-module-cpp/src-native/ios
cp $LIB_NAME.podspec ../../packages/v8-module-cpp/src-native/ios
rm -rf $LIB_NAME.xcframework
rm simulator_fat/libmy_sdk.a
