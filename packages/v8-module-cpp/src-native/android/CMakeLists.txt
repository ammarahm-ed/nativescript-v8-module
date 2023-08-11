cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set this to your library name in lower case.
project(helloworld)

# This name will be used as your library name. For example helloworld will become libhelloworld.so
# Keep it unique so it doesn't conflict with other libraries.
set (PACKAGE_NAME "helloworld")
 # The is the folder for the common cpp code we will share with ios
set (COMMON_CPP_DIR ../../platforms/ios/src/common-cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        # This name here determines our library .so file name
        ${PACKAGE_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src/main/cpp/include/libc++
        ${PROJECT_SOURCE_DIR}/src/main/cpp/include
        ${PROJECT_SOURCE_DIR}/src/main/cpp
        # Include headers of our rust library, if you don't use it, disable this line.
        ${PROJECT_SOURCE_DIR}/src/main/cpp/my_sdk/include

        # The is the folder for the common cpp code we will share with ios
        ../../platforms/ios/src/common-cpp
        ../../
)


set(CMAKE_CXX_FLAGS ${COMMON_CMAKE_ARGUMENTS})


add_library(
        ${PACKAGE_NAME}

        SHARED
        # Here you can define any other cpp files for android
        # The header files are automatically added so we will
        # just add the source files
        src/main/cpp/Install.cpp

        # We define any cpp files we add the common-cpp folder here
        # The header files are included automatically.
        ${COMMON_CPP_DIR}/hello-world.cpp
)


set_target_properties(
        ${PACKAGE_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        POSITION_INDEPENDENT_CODE ON
)

find_library(log-lib log)

# Finally we link the librares we need with our package
target_link_libraries(${PACKAGE_NAME}
          ${log-lib}
          ${NATIVESCRIPT_SO_PATH}/jni/${ANDROID_ABI}/libNativeScript.so
          android
          # Remove this line if not using the rust library
          ${PROJECT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libmy_sdk.so
          )


