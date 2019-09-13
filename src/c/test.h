

typedef struct test_st_s test_st_t;

void show_test(test_st_t test);
void move_test(test_st_t test);
void move_test_by_ref(test_st_t *test);
test_st_t get_default_test(void);
test_st_t get_test(int x, int y);


struct test_st_s {
    int x;
    int y;
};
