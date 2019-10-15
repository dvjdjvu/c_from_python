CC = g++
LINK = $(CC)
STRIP = strip

SRC = ./src/c
BUILD = ./objs
LIB = ./lib

CFLAGS      = -g -O2 -L/usr/lib/python3 -I/usr/include/python3.6 -lboost_python3
CSAHREDLIBS = -fPIC -g -shared

INCS = -I$(SRC) 

DEPS = $(SRC)/test.hpp 

OBJS = $(BUILD)/test.o 

BINS = $(LIB)/_test.so 

all: prebuild \
	$(BINS)

$(LIB)/_test.so: \
	$(OBJS)
	$(CC) -fPIC -g -shared -o $(LIB)/_test.so $(OBJS) -lboost_python3
	$(STRIP) --strip-unneeded $(LIB)/_test.so

$(BUILD)/test.o: $(DEPS) \
	$(SRC)/test.cpp
	$(CC) -g -fPIC -I/usr/include/python3.6 $(INCS) -o $(BUILD)/test.o -c $(SRC)/test.cpp

clean:
	rm -rf $(BUILD)
	rm -rf $(LIB)

prebuild:
	test -d $(BUILD) || mkdir -p $(BUILD)
	test -d $(LIB) || mkdir -p $(LIB)