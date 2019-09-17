CC = gcc
PP = g++
LINK = $(CC)
LINKPP = $(PP)
STRIP = strip

SRC = ./src/c
BUILD = ./objs

CFLAGS      = -g -O2
PFLAGS      = -std=c++17
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