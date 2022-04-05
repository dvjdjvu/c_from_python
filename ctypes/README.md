## Примеры вызова C/C++ из Python через ctypes.

## x86_x64
```bash
make CC=gcc PP=g++
./src/python/x86_64/main.py
```

## Android

### GCC
 - **armv7-a**
```bash
make CC=arm-linux-gnueabi-gcc PP=arm-linux-gnueabi-g++ -D __ANDROID__=1
```
 - **armv8-a**
```bash
make CC=aarch64-linux-gnu-gcc PP=aarch64-linux-gnu-g++ -D __ANDROID__=1
```

### Clang
 - **aarch64-linux-android21**, dont forget chanche path to clang in Makefile
```bash
make -D __ANDROID__=1
```


Copy *.so in buildozer dir.
```bash
make android
```

