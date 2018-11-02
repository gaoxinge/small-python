typedef struct tagPyStrObject {
    PyObject_HEAD;
    int length;
    long hashValue;
    char value[50];
} PyStringObject;

extern PyTypeObject PyString_Type;
extern PyObject *PyStr_Create(const char *value);