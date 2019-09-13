#!/usr/bin/python3

import sys
sys.path.append('.')
sys.path.append('lib/')
sys.path.append('../../lib/')

import _test

class Test():
    def __init__(self, x=None, y=None):
        if x:
            self.p = _test.lib.get_test(x, y)
        else:
            self.p = _test.lib.get_default_test()
        
    def __repr__(self):
        return '({0}, {1})'.format(self.p.x, self.p.y)

    def show_test(self):
        _test.lib.show_test(self.p)

    def move_test(self):
        _test.lib.move_test(self.p)

    def move_test_by_ref(self):
        # Создаем новую структуру.
        ppoint = _test.ffi.new("test_st_t *", self.p)
        _test.lib.move_test_by_ref(ppoint)
        self.p = ppoint

if __name__ == '__main__':
    ###########################################################################
    print("Pass a struct into C")
    a = Test(1, 2)
    print("Test in python is", a)
    a.show_test()
    print()

    ###########################################################################
    print("Pass by value")
    a = Test(5, 6)
    print("Test in python is", a)
    a.move_test()
    print("Test in python is", a)
    print()

    ###########################################################################
    print("Pass by reference")
    a = Test(5, 6)
    print("Test in python is", a)
    a.move_test_by_ref()
    print("Test in python is", a)
    print()

    ###########################################################################
    print("Get Struct from C")
    a = Test()
    print("New Test in python (from C) is", a)
    a = Test()
    print("New Test in python (from C) is", a)
    a = Test()
    print("New Test in python (from C) is", a)
    a = Test()
    print("New Test in python (from C) is", a)
