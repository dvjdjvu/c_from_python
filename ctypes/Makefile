#CC = arm-linux-gnueabi-gcc
#PP = arm-linux-gnueabi-g++
LINK = $(CC)
LINKPP = $(PP)

SRC = ./src/c
BUILD = ./objs

ifeq ($(CC),gcc)
    $(info ************  x86_64 ************)
    CFLAGS = -g -O2
    PFLAGS = -std=c++17
    STRIP = strip
else ifeq ($(CC),arm-linux-gnueabi-gcc)
    $(info ************  armv7-a ************)
    CFLAGS = -Wl,-hash-style=sysv -g -O2 -march=armv7-a
    PFLAGS = -std=c++17
    STRIP = arm-linux-gnueabi-strip
else ifeq ($(CC),aarch64-linux-gnu-gcc)
    $(info ************  armv8-a ************)
    CFLAGS = -Wl,-hash-style=sysv -g -O2 -march=armv8-a
    PFLAGS = -std=c++17
    STRIP = aarch64-linux-gnu-strip
else
    $(info ************  clang ************)
    CC = /home/djvu/.buildozer/android/platform/android-ndk-r19c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang
    PP = /home/djvu/.buildozer/android/platform/android-ndk-r19c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++
    CFLAGS = -target aarch64-linux-android21
    PFLAGS = -std=c++17 -stdlib=libc++
    STRIP = /home/djvu/.buildozer/android/platform/android-ndk-r19c/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-strip
endif

CSAHREDLIBS = -shared

INCS = -I$(SRC) 

DEPS = $(SRC)/test.h 

DEPSPP = $(SRC)/test.hpp

OBJS = $(BUILD)/test.o 
OBJSPP = $(BUILD)/test.pp.o 

BINS = $(BUILD)/libtest.so \
	$(BUILD)/libtestpp.so 

BINS2 = libtest.so \
	libtestpp.so

all: prebuild \
	$(BINS)

$(BUILD)/libtest.so: \
	$(OBJS)
	$(CC) $(CFLAGS) $(CSAHREDLIBS) -o $(BUILD)/libtest.so $(OBJS)
	$(STRIP) --strip-unneeded $(BUILD)/libtest.so

$(BUILD)/libtestpp.so: \
	$(OBJSPP)
	$(PP) $(CFLAGS) $(PFLAGS) $(CSAHREDLIBS) -o $(BUILD)/libtestpp.so $(OBJSPP)
	$(STRIP) --strip-unneeded $(BUILD)/libtestpp.so

$(BUILD)/test.o: $(DEPS) \
	$(SRC)/test.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/test.o $(SRC)/test.c
	
$(BUILD)/test.pp.o: $(DEPSPP) \
	$(SRC)/test.cpp
	$(PP) -c $(CFLAGS) $(PFLAGS) -fPIC $(INCS) -o $(BUILD)/test.pp.o $(SRC)/test.cpp

clean:
	rm -rf $(BUILD)

prebuild:
	test -d $(BUILD) || mkdir -p $(BUILD)
	
install: 
	ldconfig

android:
	cp objs/*.so src/python/android/lib/libtest
