#!/usr/bin/python3
#-*- coding: utf-8 -*-

import os
import cffi

if __name__ == "__main__":
    ffi = cffi.FFI()
    # Путь расположение скрипта
    PATH = os.getcwd()
    
    # test.h заголовочный файл нашей библиотеки
    # указываем путь до него относительно build.py
    with open(os.path.join(PATH, "src/c/test.h")) as f:
        ffi.cdef(f.read())
    
    ffi.set_source("_test", # имя библиотеки собранной cffi
        # Подключаем test.h, указываем путь относительно собираемой _test
        '#include "../src/c/test.h"',
        # Где libtest.so относительно _test
        # Исходная собранная библиотека
        libraries=[os.path.join(PATH, "lib/test"), "./test"],
        library_dirs=[PATH, 'objs/'],
    )

    # Куда компилируем _test
    ffi.compile(tmpdir='./lib')
