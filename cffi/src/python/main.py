#!/usr/bin/python3
#-*- coding: utf-8 -*-

import sys
import time

# пути до модуля _test
sys.path.append('.')
sys.path.append('lib/')
sys.path.append('../../lib/')

# подключаем модуль скомпелированный cffi
import _test

###
## C
###

print("CFFI\n")
print("C\n")

start_time = time.time()

##
# Работа с функциями
##

print('Работа с функциями:')
print('ret func_ret_int: ', _test.lib.func_ret_int(101))
print('ret func_ret_double: ', _test.lib.func_ret_double(12.123456789))
# Необходимо строку привести из cdata к массиву байтов, и массив байтов к строке.
print('ret func_ret_str: ', _test.ffi.string(_test.lib.func_ret_str('Hello!'.encode('utf-8'))).decode("utf-8"))
print('ret func_many_args: ', _test.lib.func_many_args(15, 18.1617, 'X'.encode('utf-8'), 32000).decode("utf-8"))

##
# Работа с переменными
##

print('\nРабота с переменными:')
print('ret a: ', _test.lib.a)

# Изменяем значение переменной.
_test.lib.a = 22
print('new a: ', _test.lib.a)

print('ret b: ', _test.lib.b)

print('ret c: ', _test.lib.c.decode("utf-8"))

##
# Работа со структурами
##

print('\nРабота со структурами:')

# Создаем структуру и заполняем её
test_st = _test.ffi.new("test_st_t *")
test_st.val1 = 5
test_st.val2 = 5.1234567
test_st.val3 = 'Z'.encode('utf-8')

ret = _test.lib.func_ret_struct(test_st)

# Полученные данные из C
print('ret val1 = {}\nret val2 = {}\nret val3 = {}'.format(ret.val1, ret.val2, ret.val3.decode("utf-8")))

# Время работы
print("--- {} seconds ---".format((time.time() - start_time)))
