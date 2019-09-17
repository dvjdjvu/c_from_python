#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "test.hpp"

namespace py = pybind11;

// _test имя нашего модуля
PYBIND11_MODULE(_test, m) {
    /*
     * Функции библиотеки
     */
    
    m.def("func_ret_int", &func_ret_int);
    m.def("func_ret_double", &func_ret_double);
    m.def("func_ret_str", &func_ret_str);
    m.def("func_many_args", &func_many_args);
    m.def("func_ret_struct", &func_ret_struct);
    
    /*
     * Глобальные переменные библиотеки
     */
    
    m.attr("a") = a;
    m.attr("b") = b;
    m.attr("c") = c;
    
    /*
     * Структуры
     */
    
    py::class_<test_st_t>(m, "test_st_t")
    .def(py::init()) // Указываем конструктор. Которого у структуры нет, но он нужен python.
    .def_readwrite("val1", &test_st_t::val1) // переменные структуры
    .def_readwrite("val2", &test_st_t::val2)
    .def_readwrite("val3", &test_st_t::val3); 
};

int a = 5;
double b = 5.12345;
char c = 'X';

int 
func_ret_int(int val) { 
    printf("C get func_ret_int: %d\n", val);
    return val;
} 

double 
func_ret_double(double val) { 
    printf("C get func_ret_double: %f\n", val);
    return val;
} 

char *
func_ret_str(char *val) { 
    printf("C get func_ret_str: %s\n", val);
    return val;
} 

char
func_many_args(int val1, double val2, char val3, short val4) { 
    printf("C get func_many_args: int - %d, double - %f, char - %c, short - %d\n", val1, val2, val3, val4);
    return val3;
} 

test_st_t *
func_ret_struct(test_st_t *test_st) {     
    if (test_st) {
        printf("C get test_st: val1 - %d, val2 - %f, val3 - %c\n", test_st->val1, test_st->val2, test_st->val3);
    }
    
    return test_st;
} 
