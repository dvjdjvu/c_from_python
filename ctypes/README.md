Примеры вызова C/C++ из Python через ctypes.

x86_x64 build
```bash
make CC=gcc PP=g++
./src/python/x86_64/main.py
```

android build
```bash
make CC=arm-linux-gnueabi-gcc PP=arm-linux-gnueabi-g++
```
or
```bash
make CC=aarch64-linux-gnu-gcc PP=aarch64-linux-gnu-g++
```
or use clang/clang++ android, but dont forget chanche path to clang in Makefile
```bash
make
```

```bash
make android
```

