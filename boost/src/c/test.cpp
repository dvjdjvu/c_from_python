#include "test.hpp"

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

object
func_ret_str(char *val) {
    printf("C get func_ret_str: %s\n", val);
    
    return object(string(val));
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

// _test имя нашего модуля
BOOST_PYTHON_MODULE(_test) {

    /*
     * Функции библиотеки
     */
    
    def("func_ret_int", func_ret_int);
    def("func_ret_double", func_ret_double);
    def("func_ret_str", &func_ret_str);
    def("func_many_args", func_many_args);
    
    // Очень важно
    // manage_new_object C функция возвращает новый объект
    // reference_existing_object C функция возвращает существующий объект
    def("func_ret_struct", &func_ret_struct, return_value_policy<reference_existing_object>());

    
    /*
     * Глобальные переменные библиотеки
     */
    scope().attr("a") = a;
    scope().attr("b") = b;
    scope().attr("c") = c;
    
    
    /*
     * Структуры
     */
    class_<test_st_t>("test_st_t")
        .def_readwrite("val1", &test_st_t::val1)
        .def_readwrite("val2", &test_st_t::val2)
        .def_readwrite("val3", &test_st_t::val3)
    ;

}
