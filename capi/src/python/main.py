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

start_time = time.time()


##
# Работа с функциями
##
    
print('Работа с функциями:')
print('ret func_hello: ', _test.func_hello())
print('ret func_ret_int: ', _test.func_ret_int(101))
print('ret func_ret_double: ', _test.func_ret_double(12.123456789))
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

# Создаем структуру
st = _test.test_st_t(1, 2.3456789, 88)

print('st.val1 = {}\nst.val2 = {}\nst.val3 = {}'.format(st.val1, st.val2, st.val3))
st = _test.func_ret_struct(st)
print("ret func_ret_struct:")
print('st.val1 = {}\nst.val2 = {}\nst.val3 = {}'.format(st.val1, st.val2, st.val3))
# Вызывай метод print нашей структуры, только по скольку C частично ООП
# То нужно в этод метод передать указатель на нашу структуру
st.print(st)


# Время работы
print("--- {} seconds ---".format((time.time() - start_time)))
