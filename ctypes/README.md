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
 - **armv7** and **armv8**. You can do it in **mac OS** only. 
```bash
make
cd src/python/
mkdir ios-build
cd ios-build
toolchain build python3 kivy openssl
toolchain create test ~/workspace/c_from_python/src/python/ios #<full_path_to_my_app_source_directory>

cd test-ios
xcodebuild -list -project test.xcodeproj
xcodebuild -workspace test.xcodeproj/project.xcworkspace -scheme test build
```


