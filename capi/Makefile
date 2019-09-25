CC = gcc
LINK = $(CC)
STRIP = strip

SRC = ./src/c
BUILD = ./objs
LIB = ./lib

CFLAGS      = -g -O2 $$(python3-config --includes --ldflags) -Wincompatible-pointer-types
CSAHREDLIBS = -shared

INCS = -I$(SRC) 

DEPS = $(SRC)/test.h 

OBJS = $(BUILD)/test.o \
	$(BUILD)/struct.o 

BINS = $(BUILD)/_test.so

BINS2 = _test.so 

all: prebuild \
	$(BINS)

$(BUILD)/_test.so: \
	$(OBJS)
	$(CC) $(CFLAGS) $(CSAHREDLIBS) -o $(LIB)/_test.so $(OBJS)
	$(STRIP) --strip-unneeded $(LIB)/_test.so

$(BUILD)/test.o: $(DEPS) \
	$(SRC)/test.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/test.o $(SRC)/test.c

$(BUILD)/struct.o: $(DEPS) \
	$(SRC)/struct.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/struct.o $(SRC)/struct.c

clean:
	rm -rf $(BUILD)
	rm -rf $(LIB)

prebuild:
	test -d $(BUILD) || mkdir -p $(BUILD)
	test -d $(LIB) || mkdir -p $(LIB)
	
install: 
	ldconfig