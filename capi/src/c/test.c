/*
 * gcc -fPIC -shared -o libtest.so test.c
 */

#include <Python.h>

#include "test.h"

// Список функций модуля
static PyMethodDef methods[] = {
    {"func_hello", func_hello, METH_NOARGS, "func_hello"},
    {"func_ret_int", func_ret_int, METH_VARARGS, "func_ret_int"},
    {"func_ret_double", func_ret_double, METH_VARARGS, "func_ret_double"},
    {"func_ret_str", func_ret_str, METH_VARARGS, "func_ret_str"},
    {"func_many_args", func_many_args, METH_VARARGS, "func_many_args"},
    //{"func_ret_struct", myprint, METH_NOARGS, "func_ret_struct"},
    {NULL, NULL, 0, NULL}
};

// Описание модуля
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "_test", "Test module", -1, methods
};

// Описание структуры test_st_t
PyTypeObject test_st_t_type = {
    PyVarObject_HEAD_INIT(NULL, 0)
};

// Определяем инициализацию структуры test_st_t

static int test_st_t_init(test_st_t *self, PyObject *args, PyObject *kwargs) {
    self->val1 = 0;
    self->val2 = 0.0;
    self->val3 = 0;
    if (!PyArg_ParseTuple(args, "|idb:test_st_t.__init__()", &self->val1, &self->val2, &self->val3))
        return -1;
    return 0;
}

static PyObject *test_st_t_dump(test_st_t *self) {
    printf("%d %f %c\n", self->val1, self->val2, self->val3);
    Py_RETURN_NONE;
}


// Инициализация модуля

PyMODINIT_FUNC PyInit__test(void) {
    PyObject *mod = PyModule_Create(&module);

    // Добавляем глобальные переменные
    PyModule_AddObject(mod, "a", PyLong_FromLong(a)); // int
    PyModule_AddObject(mod, "b", PyFloat_FromDouble(b)); // double
    PyModule_AddObject(mod, "c", Py_BuildValue("b", c)); // char

    // Добавление структуры
    PyTypeObject *type = &test_st_t_type;
    type->tp_name = "myc.test_st_t";
    type->tp_basicsize = sizeof(test_st_t);
    type->tp_flags = Py_TPFLAGS_DEFAULT;
    type->tp_new = PyType_GenericNew;
    PyModule_AddObject(mod, "test_st_t", (PyObject *) type);

    return mod;
}

/**
 * Тестовые функции, тестовые переменные.
 */

int a = 5;
double b = 5.12345;
char c = 'X'; // 88

static PyObject *
func_hello(PyObject *self) {
    puts("Hello!");
    Py_RETURN_NONE;
}

/**
 * Получение значения переменной содержащей значение типа int и возврат его.
 */
static PyObject *
func_ret_int(PyObject *self, PyObject *args) {
    int val;

    if (PyTuple_Size(args) != 1) {
        PyErr_SetString(self, "func_ret_int args error");
    }

    PyArg_ParseTuple(args, "i", &val);
    /* 
     * Альтернативный вариант.
     * 
    PyObject *obj = PyTuple_GetItem(args, 0);
    if (PyLong_Check(obj)) {
        PyErr_Print();
    }
    
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

    Py_ssize_t pos = 0;

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
    /*
    if (test_st) {
        printf("C get test_st: val1 - %d, val2 - %f, val3 - %c\n", test_st->val1, test_st->val2, test_st->val3);
    }

    return test_st;
    */
}


