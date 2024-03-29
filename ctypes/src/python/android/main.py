#!/usr/bin/python3
#-*- coding: utf-8 -*-

import os
import sys
import ctypes, ctypes.util

import kivy
kivy.require("1.9.1")
from kivy.app import App
from kivy.uix.button import Button

# class in which we are creating the button
class ButtonApp(App):

    def build(self):
        # use a (r, g, b, a) tuple
        btn = Button(text ="Push Me !",
                   font_size ="20sp",
                   background_color = (1, 1, 1, 1),
                   color = (1, 1, 1, 1),
                   size_hint = (.2, .1),
                   pos_hint = {'x':.4, 'y':.45})

        # bind() use to bind the button to function callback
        btn.bind(on_press = self.callback)
        return btn

    # callback function tells when button pressed
    def callback(self, event):
        exit(0)

# Функция callback, передается в C и там вызывается.
def callback_python(a, b):
    print("callback_python a = {}, b = {}".format(a, b))
    
    return a + b

##
#  Старт.
##
if __name__ == "__main__":

    test = None
    # Загрузка библиотеки
    try:
        test = ctypes.CDLL(ctypes.util.find_library('libtest'))
    except OSError as e:
        print(str(e))
        exit(0)

    ###
    ## C
    ###

    print("ctypes\n")
    print("C\n")

    ##
    # Работа с функциями
    ##

    # Указываем, что функция возвращает int
    test.func_ret_int.restype = ctypes.c_int
    # Указываем, что функция принимает аргумент int
    test.func_ret_int.argtypes = [ctypes.c_int, ]

    # Указываем, что функция возвращает double
    test.func_ret_double.restype = ctypes.c_double
    # Указываем, что функция принимает аргумент double
    test.func_ret_double.argtypes = [ctypes.c_double]

    # Указываем, что функция возвращает char *
    test.func_ret_str.restype = ctypes.c_char_p
    # Указываем, что функция принимает аргумент char *
    test.func_ret_str.argtypes = [ctypes.POINTER(ctypes.c_char), ]

    # Указываем, что функция возвращает char
    test.func_many_args.restype = ctypes.c_char
    # Указываем, что функция принимает аргументы int, double. char, short
    test.func_many_args.argtypes = [ctypes.c_int, ctypes.c_double, ctypes.c_char, ctypes.c_short]

    # Создаем тип функции callback, 1-ый аргумент что возращает функция, далее аргументы функции
    callback_type = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_int, ctypes.c_int)
    # Создаем callback для C из функции python
    callback_func = callback_type(callback_python)

    print('Работа с функциями:')
    print('ret func_ret_int: ', test.func_ret_int(101))
    print('ret func_ret_double: ', test.func_ret_double(12.123456789))
    # Необходимо строку привести к массиву байтов, и массив байтов к строке.
    print('ret func_ret_str: ', test.func_ret_str('Hello!'.encode('utf-8')).decode("utf-8"))
    print('ret func_many_args: ', test.func_many_args(15, 18.1617, 'X'.encode('utf-8'), 32000).decode("utf-8"))
    # Функция func_callback ни чего не возвращает, вызывает callback_python
    test.func_callback(callback_func)

    ##
    # Работа с переменными
    ##

    print('\nРабота с переменными:')
    # Указываем, что переменная типа int
    a = ctypes.c_int.in_dll(test, "a")
    print('ret a: ', a.value)

    # Изменяем значение переменной.
    a.value = 22
    a = ctypes.c_int.in_dll(test, "a")
    print('new a: ', a.value)

    # Указываем, что переменная типа double
    b = ctypes.c_double.in_dll(test, "b")
    print('ret b: ', b.value)

    # Указываем, что переменная типа char
    c = ctypes.c_char.in_dll(test, "c")
    print('ret c: ', c.value.decode("utf-8"))

    ##
    # Работа со структурами
    ##

    print('\nРабота со структурами:')


    # Объявляем структуру в Python аналогичную в C
    class test_st_t(ctypes.Structure):
        _fields_ = [('val1', ctypes.c_int),
                    ('val2', ctypes.c_double),
                    ('val3', ctypes.c_char)]


    # Указываем, что функция возвращает test_st_t *
    test.func_ret_struct.restype = ctypes.POINTER(test_st_t)
    # Указываем, что функция п�инимает аргумент void *
    test.func_ret_struct.argtypes = [ctypes.c_void_p]

    # Создаем структуру
    test_st = test_st_t(19, 3.5, 'Z'.encode('utf-8'))

    # Python None == Null C
    # ret = test.func_ret_struct(None)
    # print('ret func_ret_struct: ', ret) # Если передали None, то его и получим назад
    ret = test.func_ret_struct(ctypes.byref(test_st))

    # Полученные данные из C
    print('ret val1 = {}\nret val2 = {}\nret val3 = {}'.format(ret.contents.val1, ret.contents.val2,
                                                               ret.contents.val3.decode("utf-8")))

    ###
    ## C++
    ###

    print("\n\nC++\n")

    # Загрузка библиотеки
    testpp = ctypes.CDLL(ctypes.util.find_library('libtestpp'))

    # Указываем, что функция возвращает указатель
    testpp.test_new.restype = ctypes.c_void_p
    # Создание класса test
    test = testpp.test_new()

    ##
    # Работа с методами
    ##

    # Указываем, что функция возвращает char *
    testpp.test_ret_str.restype = ctypes.c_char_p
    # Указываем, что функция принимает аргумент void * и char *
    testpp.test_ret_str.argtypes = [ctypes.c_void_p, ctypes.c_char_p]

    # Указываем, что функция возвращает int
    testpp.test_ret_int.restype = ctypes.c_int
    # Указываем, что функция принимает аргумент void * и int
    testpp.test_ret_int.argtypes = [ctypes.c_void_p, ctypes.c_int]

    # Указываем, что функция возвращает double
    testpp.test_ret_double.restype = ctypes.c_double
    # Указываем, что функция принимает аргумент void * и double
    testpp.test_ret_double.argtypes = [ctypes.c_void_p, ctypes.c_double]

    print('Работа с методами:')
    # В качестве 1-ого аргумента передаем указатель на наш класс
    print('ret test_ret_str: ', testpp.test_ret_str(test, 'Hello!'.encode('utf-8')).decode("utf-8"))
    print('ret test_ret_int: ', testpp.test_ret_int(test, 123))
    print('ret test_ret_double: ', testpp.test_ret_double(test, 9.87654321))

    ##
    # Работа с переменными
    ##

    # Указываем, что функция возвращает int
    testpp.test_get_a.restype = ctypes.c_int
    # Указываем, что функция принимает аргумент void *
    testpp.test_get_a.argtypes = [ctypes.c_void_p]
    # Указываем, что функция возвращает double
    testpp.test_get_b.restype = ctypes.c_double
    # Указываем, что функция принимает аргумент void *
    testpp.test_get_b.argtypes = [ctypes.c_void_p]
    # Указываем, что функция возвращает char
    testpp.test_get_c.restype = ctypes.c_char
    # Указываем, что функция принимает аргумент void *
    testpp.test_get_c.argtypes = [ctypes.c_void_p]

    print('\nРабота с переменными:')
    print('ret test_get_a: ', testpp.test_get_a(test))
    print('ret test_get_b: ', testpp.test_get_b(test))
    print('ret test_get_c: ', testpp.test_get_c(test).decode("utf-8"))

    # Указываем, что функция принимает аргумент void *
    testpp.test_del.argtypes = [ctypes.c_void_p]
    # Удаляем класс
    testpp.test_del(test)

    ButtonApp().run()
