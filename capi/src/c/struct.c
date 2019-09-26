#include "test.h"
#include "struct.h"

// Освобождение структуры
static void
test_st_t_dealloc(test_st_t* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}

// Создание структуры
static PyObject *
test_st_t_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    test_st_t *self;

    self = (test_st_t *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->val1 = 0;
        self->val2 = 0.0;
        self->val3 = 0;
    }

    return (PyObject *)self;
}

// Инициализация структуры, заполняем её переданными значениями
static int
test_st_t_init(test_st_t *self, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {"val1", "val2", "val3", NULL};

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "|idb", kwlist, &self->val1, &self->val2, &self->val3))
        return -1;

    return 0;
}

// Описываем аттрибуты из которых состоит структура
static PyMemberDef test_st_t_members[] = {
    {"val1", T_INT, offsetof(test_st_t, val1), 0, "int"},
    {"val2", T_DOUBLE, offsetof(test_st_t, val2), 0, "double"},
    {"val3", T_CHAR, offsetof(test_st_t, val3), 0, "char"},
    {NULL}
};

// Метод структуры, который печатает структуру
static PyObject* test_st_print(PyObject *self, PyObject *args)
{
    test_st_t *st;
    
    // Получаем структуру из Python
    if (!PyArg_ParseTuple(args, "O", &st)) // O - объект данных
        Py_RETURN_NONE;
    
    printf("method: val1 - %d, val2 - %f, val3 - %d\n", st->val1++, st->val2++, st->val3++);
    Py_RETURN_NONE;
}

// Описание методов стрктуры, но у классической структуры не может быть методов!
// А здесь может!
static PyMethodDef test_st_t_methods[] = {
    {"print", test_st_print, METH_VARARGS, "doc string"},
    {NULL}  /* Sentinel */
};

// Структура описывающая нашу структуру. Какие атрибуты, методы, конструкторы, деструкторы и т.д. и т.п.
PyTypeObject test_st_t_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "_test.test_st_t",         /* tp_name */
    sizeof(test_st_t),         /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor) test_st_t_dealloc, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "test_st_t objects",       /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    test_st_t_methods,         /* tp_methods */
    test_st_t_members,         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc) test_st_t_init, /* tp_init */
    0,                         /* tp_alloc */
    test_st_t_new,             /* tp_new */
};
