#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void show_test(test_st_t test) {
    printf("test_st_t in C is (%d, %d)\n", test.x, test.y);
}

void move_test(test_st_t test) {
    show_test(test);
    test.x++;
    test.y++;
    show_test(test);
}

void move_test_by_ref(test_st_t *test) {
    show_test(*test);
    test->x++;
    test->y++;
    show_test(*test);
}

test_st_t get_default_test(void) {
    static int x_counter = 0;
    static int y_counter = 100;
    x_counter++;
    y_counter--;
    return get_test(x_counter, y_counter);
}

test_st_t get_test(int x, int y) {
    test_st_t test = { x, y };
    printf("Returning test_st_t (%d, %d)\n", test.x, test.y);
    return test;
}
