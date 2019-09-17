LIB = ./lib
BUILD = ./build

all: clean \
	prebuild \
	build

prebuild:
	test -d $(LIB) || mkdir -p $(LIB)

clean:
	rm -rf $(LIB) \
	rm -rf $(BUILD)
	
build:
	python3 setup.py build --build-lib=$(LIB)
