typedef struct test_st_s test_st_t;

extern int a;
extern double b;
extern char c;

int func_ret_int(int val);
double func_ret_double(double val);
char *func_ret_str(char *val);
char func_many_args(int val1, double val2, char val3, short val4);
test_st_t *func_ret_struct(test_st_t *test_st);

struct test_st_s {
    int val1;
    double val2;
    char val3;
};
