#!/usr/bin/python3
#-*- coding: utf-8 -*-

from distutils.core import setup, Extension

mdl = Extension('_test', sources = ['src/c/test.c', 'src/c/struct.c'])

setup(name = '_test',
        version = '1.0',
        description = 'Python C API Simplest Module',
        ext_modules = [mdl])