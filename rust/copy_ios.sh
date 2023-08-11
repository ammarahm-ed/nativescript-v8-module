#! /bin/bash

cp -r MySdk.xcframework ../packages/v8-module-cpp/src-native/ios
cp MySdk.podspec ../packages/v8-module-cpp/src-native/ios
rm -rf MySdk.xcframework
rm simulator_fat/libmy_sdk.a
