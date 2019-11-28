#!/usr/bin/python3
#-*- coding: utf-8 -*-

import timeit

import sys
import time

# Пути до модуля test
#sys.path.append('.')
sys.path.append('lib/')

# подключаем модуль
import _test

###
## C
###

def main():
    print("boost\n")
    print("C\n")

    ##start_time = time.time()

    ##
    # Работа с функциями
    ##

    print('Работа с функциями:')
    print('ret func_ret_int: ', _test.func_ret_int(101))
    print('ret func_ret_double: ', _test.func_ret_double(12.123456789))
    print('ret func_ret_str: ', _test.func_ret_str('Hello!'))
    print('ret func_many_args: ', _test.func_many_args(15, 18.1617, 'X', 32000))

    ##
    # Работа с переменными
    ##

    print('\nРабота с переменными:')
    print('ret a: ', _test.a)

    # Изменяем значение переменной.
    _test.a = 22
    print('new a: ', _test.a)
    print('ret b: ', _test.b)
    print('ret c: ', _test.c)

    ##
    # Работа со структурами
    ##

    print('\nРабота со структурами:')

    # Создаем структуру и заполняем её
    test_st = _test.test_st_t()
    test_st.val1 = 5
    test_st.val2 = 5.1234567
    test_st.val3 = 'Z'

    print('val1 = {}\nval2 = {}\nval3 = {}'.format(test_st.val1, test_st.val2, test_st.val3))

    ret = _test.func_ret_struct(test_st)

    # Полученные данные из C
    print('ret val1 = {}\nret val2 = {}\nret val3 = {}'.format(ret.val1, ret.val2, ret.val3))

    # Время работы
    ##print("--- {} seconds ---".format(time.time() - start_time))

print(timeit.timeit("main()", "from __main__ import main", number=1))

