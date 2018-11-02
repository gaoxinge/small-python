#include <iostream>
#include <stdlib.h>
#include "PyObject.h"
#include "PyIntObject.h"
#include "PyStrObject.h"
#include "PyDictObject.h"

using namespace std;

PyObject *m_LocalEnvironment = PyDict_Create();
const char *info = "********** Python Research **********\n";
const char *prompt = ">>> ";

bool IsSourceAllDigit(string& source) {
    int len = source.size();
    for (int i = 0; i < len; i++)
        if (!isdigit(source[i]))
            return false;
    return true;
}

PyObject *GetObjectBySymbol(string& symbol) {
    PyObject *key = PyStr_Create(symbol.c_str());
    PyObject *value = PyDict_GetItem(m_LocalEnvironment, key);
    if (value == NULL) {
        cout << "[Error] : " << symbol << " is not defined!!" << endl;
        return NULL;
    }
}

void ExecutePrint(string symbol) {
    PyObject *object = GetObjectBySymbol(symbol);
    if (object != NULL) {
        PyTypeObject *type = object->type;
        type->print(object);
    }
}

void ExecuteAdd(string& target, string& source) {
    string::size_type pos;
    PyObject *strValue = NULL;
    PyObject *resultValue = NULL;
    if (IsSourceAllDigit(source)) {
        PyObject *intValue = PyInt_Create(atoi(source.c_str()));
        PyObject *key = PyStr_Create(target.c_str());
        PyDict_SetItem(m_LocalEnvironment, key, intValue);
    } else if ((pos = source.find("\"")) != string::npos) {
        strValue = PyStr_Create(source.substr(1, source.size() - 2).c_str());
        PyObject *key = PyStr_Create(target.c_str());
        PyDict_SetItem(m_LocalEnvironment, key, strValue);
    } else if ((pos = source.find("+")) != string::npos) {
        string left = source.substr(0, pos);
        string right = source.substr(pos + 1);
        PyObject *leftObject = GetObjectBySymbol(left);
        PyObject *rightObject = GetObjectBySymbol(right);
        if (leftObject != NULL && rightObject != NULL && leftObject->type == rightObject->type) {
            resultValue = (leftObject->type)->add(leftObject, rightObject);
            PyObject *key = PyStr_Create(target.c_str());
            PyDict_SetItem(m_LocalEnvironment, key, resultValue);
        }
    }
}

void ExecuteCommand(string& command) {
    string::size_type pos = 0;
    if ((pos = command.find("print ")) != string::npos) {
        ExecutePrint(command.substr(6));
    } else if ((pos = command.find(" = ")) != string::npos) {
        string target = command.substr(0, pos);
        string source = command.substr(pos + 3);
        ExecuteAdd(target, source);
    }
}

void Execute() {
    string m_Command;
    cout << info;
    cout << prompt;
    while (getline(cin, m_Command)) {
        if (m_Command.size() == 0) {
            cout << prompt;
            continue;
        } else if (m_Command == "exit") {
            return;
        } else {
            ExecuteCommand(m_Command);
        }
        cout << prompt;
    }
}

int main() {
    Execute();
    return 0;
}