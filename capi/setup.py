#!/usr/bin/python3
#-*- coding: utf-8 -*-

from distutils.core import setup, Extension

mdl = Extension('do_nothing', sources = ['src/c/test.c'])

setup(name = 'do_nothing',
        version = '1.0',
        description = 'Python C API Simplest Module',
        ext_modules = [mdl])