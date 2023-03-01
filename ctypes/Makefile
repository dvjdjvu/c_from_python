#CC = arm-linux-gnueabi-gcc
#PP = arm-linux-gnueabi-g++
LINK = $(CC)
LINKPP = $(PP)
UNAME := $(shell uname)
EXT := so

SRC = ./src/c

ifeq ($(CC),gcc)
    $(info ************  Linux  ************)
    $(info ************  x86_64 ************)
    override CFLAGS := $(CFLAGS) -g -O2
    override PFLAGS := $(PFLAGS) -std=c++17
    STRIP = strip --strip-unneeded
    BUILD = ./objs
else ifeq ($(CC),arm-linux-gnueabi-gcc)
    $(info ************  Android ************)
    $(info ************  armv7-a ************)
    override CFLAGS := $(CFLAGS) -Wl,-hash-style=sysv -g -O2 -march=armv7-a
    override PFLAGS := $(PFLAGS) -std=c++17
    STRIP = arm-linux-gnueabi-strip --strip-unneeded
    BUILD = src/python/android/libs/libs_armeabi_v7a/
else ifeq ($(CC),aarch64-linux-gnu-gcc)
    $(info ************  Android ************)
    $(info ************  armv8-a ************)
    override CFLAGS := $(CFLAGS) -Wl,-hash-style=sysv -g -O2 -march=armv8-a
    override PFLAGS := $(PFLAGS) -std=c++17
    STRIP = aarch64-linux-gnu-strip --strip-unneeded
    BUILD = src/python/android/libs/libs_arm64_v8a/
else
    ifeq ($(UNAME), Linux)
    	$(info ************  Android ************)
	$(info ************   clang  ************)
        CC = ~/.buildozer/android/platform/android-ndk-r19c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang
        PP = ~/.buildozer/android/platform/android-ndk-r19c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++
        override CFLAGS := $(CFLAGS) -target aarch64-linux-android21
        override PFLAGS := $(PFLAGS) -std=c++17 -stdlib=libc++
        STRIP = /home/djvu/.buildozer/android/platform/android-ndk-r19c/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-strip --strip-unneeded
        BUILD = src/python/android/libs/libs_arm64_v8a/
    endif
    
    ifeq ($(UNAME), Darwin)
    	$(info ************  iOS  ************)
        $(info ************ clang ************)
	CC = clang
        PP = clang++
    	override CFLAGS := $(CFLAGS)
	STRIP = strip -x
	BUILD = src/python/ios/libs/$(ARCH)/
	EXT := a
    endif
endif

CSAHREDLIBS = -shared

INCS = -I$(SRC) 

DEPS = $(SRC)/test.h 

DEPSPP = $(SRC)/test.hpp

OBJS = $(BUILD)/test.o 
OBJSPP = $(BUILD)/test.pp.o 

BINS = $(BUILD)/libtest.$(EXT) \
	$(BUILD)/libtestpp.$(EXT) 

all: prebuild \
	$(BINS)

$(BUILD)/libtest.$(EXT): \
	$(OBJS)
	$(CC) $(CFLAGS) $(CSAHREDLIBS) -o $(BUILD)/libtest.$(EXT) $(OBJS)
	$(STRIP) $(BUILD)/libtest.$(EXT)

$(BUILD)/libtestpp.$(EXT): \
	$(OBJSPP)
	$(PP) $(CFLAGS) $(PFLAGS) $(CSAHREDLIBS) -o $(BUILD)/libtestpp.$(EXT) $(OBJSPP)
	$(STRIP) $(BUILD)/libtestpp.$(EXT)

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
	cp objs/*.$(EXT) src/python/android/lib/libtest
	
ios:
	cp objs/*.$(EXT) src/python/ios/lib/libtest
