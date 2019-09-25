/*
 * gcc -fPIC -shared -o libtest.so test.c
 */

#include <Python.h>

#include "test.h"
#include "struct.h"

// Список функций модуля
static PyMethodDef methods[] = {
    {"func_hello", func_hello, METH_NOARGS, "func_hello"}, // Функция без аргументов
    {"func_ret_int", func_ret_int, METH_VARARGS, "func_ret_int"}, // Функция с аргументами
    {"func_ret_double", func_ret_double, METH_VARARGS, "func_ret_double"},
    {"func_ret_str", func_ret_str, METH_VARARGS, "func_ret_str"},
    {"func_many_args", func_many_args, METH_VARARGS, "func_many_args"},
    {"func_ret_struct", func_ret_struct, METH_VARARGS, "func_ret_struct"},
    {NULL, NULL, 0, NULL}
};

// Описание модуля
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "_test", "Test module", -1, methods
};

// Инициализация модуля
PyMODINIT_FUNC 
PyInit__test(void) {
    PyObject *mod = PyModule_Create(&module);

    // Добавляем глобальные переменные
    PyModule_AddObject(mod, "a", PyLong_FromLong(a)); // int
    PyModule_AddObject(mod, "b", PyFloat_FromDouble(b)); // double
    PyModule_AddObject(mod, "c", Py_BuildValue("b", c)); // char

    // Добавляем структуру
    
    // Завершение инициализации структуры
    if (PyType_Ready(&test_st_t_Type) < 0)
        return NULL;
    
    Py_INCREF(&test_st_t_Type);
    PyModule_AddObject(mod, "test_st_t", (PyObject *) &test_st_t_Type);
    
    return mod;
}

/**
 * Тестовые функции, тестовые переменные.
 */

int a = 5;
double b = 5.12345;
char c = 'X'; // 88

static PyObject *
func_hello(PyObject *self, PyObject *args) { // Можно без args, но будет warning при компиляции.
    puts("Hello!");
    Py_RETURN_NONE;
}

/**
 * Получение значения переменной содержащей значение типа int и возврат его.
 */
static PyObject *
func_ret_int(PyObject *self, PyObject *args) {
    int val;

    // Проверка кол-ва аргументов
    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_int args error");
    }

    PyArg_ParseTuple(args, "i", &val);
    /* 
     * Альтернативный вариант.
     * 
    // Получаем аргумент
    PyObject *obj = PyTuple_GetItem(args, 0);
    // Проверяем его на тип int/long
    if (PyLong_Check(obj)) {
        PyErr_Print();
    }
    // Приводим (PyObject *) к int
    val = _PyLong_AsInt(obj);
     */
    printf("C get func_ret_int: %d\n", val);
    return Py_BuildValue("i", val);
}

/**
 * Получение значения переменной содержащей значение типа double и возврат его.
 */
static PyObject *
func_ret_double(PyObject *self, PyObject *args) {
    double val;

    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_double args error");
    }

    PyArg_ParseTuple(args, "d", &val);

    printf("C get func_ret_double: %f\n", val);
    return Py_BuildValue("f", val);
}

/**
 * Получение string и возврат его.
 */
static PyObject *
func_ret_str(PyObject *self, PyObject *args) {
    char *val;

    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_str args error");
    }

    PyArg_ParseTuple(args, "s", &val);
    /* 
     * Альтернативный вариант.
     * 
    PyObject *obj = PyTuple_GetItem(args, 0);
    
    PyObject* pResultRepr = PyObject_Repr(obj);
    val = PyBytes_AS_STRING(PyUnicode_AsEncodedString(pResultRepr, "utf-8", "ERROR"));
     */
    printf("C get func_ret_str: %s\n", val);
    return Py_BuildValue("s", val);
}

/**
 * Получение значения переменных содержащих значения типа int, double, char *.
 */
static PyObject *
func_many_args(PyObject *self, PyObject *args) {
    int val1;
    double val2;
    char *val3;

    if (PyTuple_Size(args) != 3) {
        PyErr_SetString(self, "func_ret_str args error");
    }

    PyArg_ParseTuple(args, "ids", &val1, &val2, &val3);

    printf("C get func_many_args: int - %d, double - %f, string - %s\n", val1, val2, val3);
    return Py_BuildValue("ifs", val1, val2, val3);
}

static PyObject *
func_ret_struct(PyObject *self, PyObject *args) {
    
    test_st_t *st;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "O", &st)) // O - объект данных
        Py_RETURN_NONE;
    
    printf("C get test_st: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);

    return Py_BuildValue("O", st);
}
