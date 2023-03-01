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
```bash
cd src/python/android
buildozer android debug
adb install -r ./bin/kivy_test-*.apk
```

```bash
adb logcat | grep python
```

## iOS

### Clang 
You can do it in **mac OS** only. 

 - **armv7**. 
```bash
make BUILD="src/python/ios/libs_armv7/" CFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk"
```

 - **arm64v8**

```bash
make BUILD="src/python/ios/libs_arm64v8/" CFLAGS="-arch arm64v8 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk"
```

 - emulator **x86_64**
```bash
make BUILD="src/python/ios/libs_x86_64/" CFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk"
```

```
cd src/python/
mkdir ios-build
cd ios-build
toolchain build python3 kivy openssl # very long operation
toolchain create test /Users/djvu/workspace/c_from_python/src/python/ios #<full_path_to_my_app_source_directory>
```

How can I get the architecture of a '.a' file?
```bash
lipo -info libtest.a
```

and **RUN** in **Xcode**

```bash
open test-ios/test.xcodeproj
```

if need to update the project:
```bash
toolchain update test-ios
```


Console doesnt work now.
```bash
cd test-ios
xcodebuild -list -project test.xcodeproj
xcodebuild -workspace test.xcodeproj/project.xcworkspace -scheme test build
```


