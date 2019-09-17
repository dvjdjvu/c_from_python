#include "test.hpp"

/**
 * Методы класса
 **/
std::string test::ret_str(std::string val) {
    std::cout << "C get ret_str: " << val << std::endl;
    return val;
}

int test::ret_int(int val) {
    std::cout << "C get ret_int: " << val << std::endl;
    return val;
}

double test::ret_double(double val) {
    std::cout << "C get ret_double: " << val << std::endl;
    return val;
}

/**
 * Обвязка C для методов класса C++
 **/

// Создаем класс test, и получаем указатель на него.
test *test_new() {
    return new test();
}

// Удаляем класс test.
void test_del(test *test) {
    delete test;
}

/*
 * Вызов методов класса.
 */

// Обертка над методом ret_str
char *test_ret_str(test *test, char *val) {
    // char * к std::string
    std::string str = test->ret_str(std::string(val));
    
    // std::string к char *
    char *ret = new char[str.length() + 1];
    strcpy(ret, str.c_str());
    
    return ret;
}

// Обертка над методом ret_int
int test_ret_int(test *test, int val) {
    return test->ret_int(val);
}

// Обертка над методом ret_double
double test_ret_double(test *test, double val) {
    return test->ret_double(val);
}

/*
 * Получение переменных класса.
 */

// Обертка для получения a
int test_get_a(test *test) {
    return test->a;
}

// Обертка для получения b
double test_get_b(test *test) {
    return test->b;
}

// Обертка для получения c
char test_get_c(test *test) {
    return test->c;
}
