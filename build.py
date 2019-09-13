#!/usr/bin/python3

import os
import cffi

if __name__ == "__main__":
    ffi = cffi.FFI()
    PATH = os.getcwd()#os.path.dirname(__file__)
    
    # test.h относительно build.py
    with open(os.path.join(PATH, "src/c/test.h")) as f:
        ffi.cdef(f.read())
    
    ffi.set_source("_test",
        # Где лежит test.h, относительно _test.cpython-36m-x86_64-linux-gnu.so
        '#include "../src/c/test.h"',
        # Где libtest.so относительно _test.cpython-36m-x86_64-linux-gnu.so
        libraries=[os.path.join(PATH, "lib/test"), "./test"],
        library_dirs=[PATH, 'objs/'],
    )

    # Куда компилируется _test.cpython-36m-x86_64-linux-gnu.
    ffi.compile(tmpdir='./lib')
