#! /bin/bash
COPY_DIR="../packages/v8-module-cpp/src-native/android/src/main/jniLibs"

rm -rf $COPY_DIR

mkdir -p $COPY_DIR
mkdir -p $COPY_DIR/x86
mkdir -p $COPY_DIR/x86_64
mkdir -p $COPY_DIR/arm64-v8a
mkdir -p $COPY_DIR/armeabi-v7a

cp ./target/i686-linux-android/release/libmy_sdk.so $COPY_DIR/x86/libmy_sdk.so
cp ./target/x86_64-linux-android/release/libmy_sdk.so $COPY_DIR/x86_64/libmy_sdk.so
cp ./target/aarch64-linux-android/release/libmy_sdk.so $COPY_DIR/arm64-v8a/libmy_sdk.so
cp ./target/armv7-linux-androideabi/release/libmy_sdk.so $COPY_DIR/armeabi-v7a/libmy_sdk.so
cp -r ./my_sdk/include ../packages/v8-module-cpp/src-native/android/src/main/cpp/my_sdk/include

echo "Dynamic libraries copied!"
