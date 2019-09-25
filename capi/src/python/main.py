#!/usr/bin/python3
#-*- coding: utf-8 -*-

import sys
import time

# пути до модуля _test
sys.path.append('.')
sys.path.append('lib/')
sys.path.append('../../lib/')

import _test 
 
###
## C
###

print("C API\n")
print("C\n")

#print(dir(_test))

start_time = time.time()

##
# Работа с функциями
##
    
print('Работа с функциями:')
print('ret func_hello: ', _test.func_hello())
print('ret func_ret_int: ', _test.func_ret_int(101))
print('ret func_ret_double: ', _test.func_ret_double(12.123456789))
# Необходимо строку привести из cdata к массиву байтов, и массив байтов к строке.
print('ret func_ret_str: ', _test.func_ret_str('Hello!'))
print('ret func_many_args: ', _test.func_many_args(15, 18.1617, "Many arguments!"))

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

st = _test.test_st_t(1, 2.3456789, 88)

print('ret val1 = {}\nret val2 = {}\nret val3 = {}'.format(st.val1, st.val2, st.val3))

# Время работы
print("--- {} seconds ---".format((time.time() - start_time)))
