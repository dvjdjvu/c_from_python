## Примеры вызова C/C++ из Python через ctypes.

## x86_x64
```bash
make CC=gcc PP=g++
./src/python/x86_64/main.py
```

## Android

[Article](https://habr.com/ru/post/656453/)

### GCC
 - **armv7-a**
```bash
make CC=arm-linux-gnueabi-gcc PP=arm-linux-gnueabi-g++ CFLAGS=-D__ANDROID__=1
```
 - **armv8-a**
```bash
make CC=aarch64-linux-gnu-gcc PP=aarch64-linux-gnu-g++ CFLAGS=-D__ANDROID__=1
```

### Clang (**Recomended**)
 - **aarch64-linux-android21**, don't forget chanche path to clang in Makefile.
```bash
make CFLAGS=-D__ANDROID__=1
```

### python
Building:
```bash
cd src/python/android
buildozer android debug
```

Installing in phone:
```bash
adb install -r ./bin/kivy_test-*.apk
```

View phone logs:
```bash
adb logcat | grep python
```

## iOS

[Article](https://habr.com/ru/post/720310/)

### Clang 
You can do it in **mac OS** only. 

 - **armv6**
```bash
make ARCH=armv6 CFLAGS="-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=12.0"
```

 - **armv7**
```bash
make ARCH=armv7 CFLAGS="-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=12.0"
```

 - **arm64** (means armv8 aarch64)

```bash
make ARCH=arm64 CFLAGS="-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=12.0"
```

 - emulator **x86_64**
```bash
make ARCH=x86_64 CFLAGS="-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk"
```

Create a universal file from multy single-architecture files:
```bash
lipo -arch armv7 src/python/ios/libs/armv7/libtest.a -arch arm64 src/python/ios/libs/arm64/libtest.a  -arch x86_64 src/python/ios/libs/x86_64/libtest.a  -create -output src/python/ios/libs/libtest.a

lipo -arch armv7 src/python/ios/libs/armv7/libtestpp.a -arch arm64 src/python/ios/libs/arm64/libtestpp.a  -arch x86_64 src/python/ios/libs/x86_64/libtestpp.a  -create -output src/python/ios/libs/libtestpp.a
```

How can I get the architecture of a '.a' file?
```bash
lipo -info libtest.a
```

```
cd src/python/
mkdir ios-build
cd ios-build
toolchain build python3 kivy openssl # very long operation
toolchain create test ~/workspace/c_from_python/ctypes/src/python/ios #<full_path_to_my_app_source_directory>
```

#### Signing

Signing libs for iPhone, emulator works without it:
```bash
codesign -s djvu@inbox.ru src/python/ios/libs/libtest.a 
codesign -s djvu@inbox.ru src/python/ios/libs/libtestpp.a 
```
Instead of djvu@inbox.ru, your **Apple ID**.

View signature:
```bash
codesign -d -v src/python/ios/libs/libtest.a 
codesign -d -v src/python/ios/libs/libtestpp.a 
```

### python

Open and **RUN** the project in **Xcode**:

```bash
open test-ios/test.xcodeproj
```

If you need to update the project:
```bash
toolchain update test-ios
```

TODO: Make starting from console. Doesn't work now.
```bash
cd test-ios
xcodebuild -list -project test.xcodeproj
xcodebuild -workspace test.xcodeproj/project.xcworkspace -scheme test build
```


