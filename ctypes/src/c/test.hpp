#ifndef _TEST_HPP_
#define _TEST_HPP_

#include <iostream>
#include <string.h>

class test {
public:
    int a = 5;
    double b = 5.12345;
    char c = 'X';

    std::string ret_str(std::string val);
    int ret_int(int val);
    double ret_double(double val);
};

#ifdef __cplusplus
extern "C" {
#endif

    test *test_new();
    void test_del(test *test);
    char *test_ret_str(test *test, char *val);
    int test_ret_int(test *test, int val);
    double test_ret_double(test *test, double val);

    int test_get_a(test *test);
    double test_get_b(test *test);
    char test_get_c(test *test);

#ifdef __cplusplus
}
#endif

#endif