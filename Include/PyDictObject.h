#include <map>

using namespace std;

typedef struct tagPyDictobject {
    PyObject_HEAD;
    map<long, PyObject*> dict;
} PyDictObject;

extern PyTypeObject PyDict_Type;
extern PyObject *PyDict_Create();
extern PyObject *PyDict_GetItem(PyObject *target, PyObject *key);
extern int PyDict_SetItem(PyObject *target, PyObject *key, PyObject *value);