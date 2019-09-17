CC = gcc
LINK = $(CC)
STRIP = strip

SRC = ./src/c
BUILD = ./objs
LIB = ./lib

CFLAGS      = -g -O2
CSAHREDLIBS = -shared

INCS = -I$(SRC) 

DEPS = $(SRC)/test.h 

OBJS = $(BUILD)/test.o 

BINS = $(LIB)/libtest.so 

all: prebuild \
	$(BINS)
	./build.py

$(LIB)/libtest.so: \
	$(OBJS)
	$(CC) $(CFLAGS) $(CSAHREDLIBS) -o $(LIB)/libtest.so $(OBJS)
	$(STRIP) --strip-unneeded $(LIB)/libtest.so

$(BUILD)/test.o: $(DEPS) \
	$(SRC)/test.c
	$(CC) -c $(CFLAGS) -fPIC $(INCS) -o $(BUILD)/test.o $(SRC)/test.c

test: libtest.so
	./build.py

clean:
	rm -rf $(BUILD)
	rm -rf $(LIB)

prebuild:
	test -d $(BUILD) || mkdir -p $(BUILD)
	test -d $(LIB) || mkdir -p $(LIB)

