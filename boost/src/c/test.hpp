#ifndef _TEST_H_
#define	_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <boost/python/ptr.hpp>
#include <boost/python/object_core.hpp>
#include <boost/python/class.hpp>
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;
using namespace std;

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef struct test_st_s test_st_t;
typedef char * char_p;

extern int a;
extern double b;
extern char c;

int func_ret_int(int val);
double func_ret_double(double val);

object func_ret_str(char *val);
char func_many_args(int val1, double val2, char val3, short val4);
test_st_t *func_ret_struct(test_st_t *test_st);

struct test_st_s {
    int val1;
    double val2;
    char val3;
};

#ifdef	__cplusplus
}
#endif

#endif	/* _TEST_H_ */