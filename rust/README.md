# Rust library example

This is a rust library example that compiles to both Android and iOS.

## Building

Make sure that you have rust installed in your system and properly setup.

### iOS

For installing ios arch

```
rustup target add x86_64-apple-ios aarch64-apple-ios aarch64-apple-ios-sim
```

### Android

Install all the android archs you want compile your library for

```
rustup target add i686-linux-android x86_64-linux-android aarch64-linux-android armv7-linux-androideabi
```

For android, you also need to setup toolchains for each arch in `~/.cargo/config`

```
[target.armv7-linux-androideabi]
linker = "[PATH_TO_YOUR_ANDROID_SDK]/ndk/23.1.7779620/toolchains/llvm/prebuilt/darwin-x86_64/bin/armv7a-linux-androideabi30-clang++"
[target.aarch64-linux-android]
linker = "[PATH_TO_YOUR_ANDROID_SDK]/ndk/23.1.7779620/toolchains/llvm/prebuilt/darwin-x86_64/bin/aarch64-linux-android30-clang++"
[target.i686-linux-android]
linker = "[PATH_TO_YOUR_ANDROID_SDK]/ndk/23.1.7779620/toolchains/llvm/prebuilt/darwin-x86_64/bin/i686-linux-android30-clang++"
[target.x86_64-linux-android]
linker = "[PATH_TO_YOUR_ANDROID_SDK]/ndk/23.1.7779620/toolchains/llvm/prebuilt/darwin-x86_64/bin/x86_64-linux-android30-clang++"⏎
```

The above is for ios, for linux or windows, the setup might be slightly different. Especially `darwin-x86_64` might be replaced with something else. Please do the research if you face any errors.

### Install cbindgen

```
cargo install cbindgen
```

To build the library

```
make all
```

or `make ios` and `make android` for platform specific builds.

# Cleanup

To cleanup build files run the following command

`make clean`

#

On iOS after build completes, MySdk.xcframework & MySdk.podspec will be copied to `packages/v8-module-cpp/src-native/ios/`.

On android `.so` files will be copied to `packages/v8-module-cpp/src-native/android/src/main/jniLibs` and the generated header files will also copied on android into `cpp/my_sdk/include` folder automatically.
