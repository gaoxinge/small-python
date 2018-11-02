typedef struct tagPyIntObject {
    PyObject_HEAD;
    int value;
} PyIntObject;

extern PyTypeObject PyInt_Type;
extern PyObject *PyInt_Create(int value);