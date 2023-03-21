/*
 * gcc -fPIC -shared -o libtest.so test.c
 */

#include "test.h"

int a = 5;
double b = 5.12345;
char c = 'X';

int 
func_ret_int(int val) {
    #ifdef __ANDROID__
        // Android Headers
    #elif __APPLE__
        // iOS Headers
        printf("C get func_ret_int: %d\n", val);
    #else
        printf("C get func_ret_int: %d\n", val);
    #endif

    return val;
} 

double 
func_ret_double(double val) {
    #ifdef __ANDROID__
        // Android Headers
    #elif __APPLE__
        // iOS Headers
        printf("C get func_ret_double: %f\n", val);
    #else
        printf("C get func_ret_double: %f\n", val);
    #endif

    return val;
} 

char *
func_ret_str(char *val) {
    #ifdef __ANDROID__
        // Android Headers
    #elif __APPLE__
        // iOS Headers
        printf("C get func_ret_str: %s\n", val);
    #else
        printf("C get func_ret_str: %s\n", val);
    #endif

    return val;
} 

char
func_many_args(int val1, double val2, char val3, short val4) {
    #ifdef __ANDROID__
        // Android Headers
    #elif __APPLE__
        // iOS Headers
        printf("C get func_many_args: int - %d, double - %f, char - %c, short - %d\n", val1, val2, val3, val4);
    #else
        printf("C get func_many_args: int - %d, double - %f, char - %c, short - %d\n", val1, val2, val3, val4);
    #endif

    return val3;
} 

test_st_t *
func_ret_struct(test_st_t *test_st) {     
    if (test_st) {
        #ifdef __ANDROID__
            // Android Headers
        #elif __APPLE__
            // iOS Headers
            printf("C get test_st: val1 - %d, val2 - %f, val3 - %c\n", test_st->val1, test_st->val2, test_st->val3);
        #else
            printf("C get test_st: val1 - %d, val2 - %f, val3 - %c\n", test_st->val1, test_st->val2, test_st->val3);
        #endif
    }
    
    return test_st;
}

void
func_callback(int (*f)(int, int)) {
    int a = 3, b = 7;
    puts("00000");
    printf("f = %p\n", f);
    int ret = f(a, b);
    puts("11111");
    #ifdef __ANDROID__
        // Android Headers
    #elif __APPLE__
        // iOS Headers
        printf("C get func_callback: %d\n", ret);
    #else
        printf("C get func_callback: %d\n", ret);
    #endif
}
