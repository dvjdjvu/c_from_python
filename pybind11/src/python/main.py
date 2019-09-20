#!/usr/bin/python3
#-*- coding: utf-8 -*-

import sys
import time

# Пути до модуля _test
sys.path.append('lib/')

# подключаем модуль
import _test

###
## C
###

print("pybind11\n")
print("C\n")

start_time = time.time()

##
# Работа с функциями
##

print('Работа с функциями:')
print('ret func_ret_int: ', _test.func_ret_int(101))
print('ret func_ret_double: ', _test.func_ret_double(12.123456789))
# Необходимо строку привести из cdata к массиву байтов, и массив байтов к строке.
print('ret func_ret_str: ', _test.func_ret_str('Hello!'.encode('utf-8')))
print('ret func_many_args: ', _test.func_many_args(15, 18.1617, 'X'.encode('utf-8'), 32000))

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
_test_st = _test.test_st_t()
#print(dir(_test_st))
_test_st.val1 = 5
_test_st.val2 = 5.1234567
_test_st.val3 = 'Z'.encode('utf-8')

ret = _test.func_ret_struct(_test_st)

# Полученные данные из C
print('ret val1 = {}\nret val2 = {}\nret val3 = {}'.format(ret.val1, ret.val2, ret.val3))

# Время работы
print("--- {} seconds ---".format((time.time() - start_time)))
