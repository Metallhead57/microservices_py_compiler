#include "runner.h"
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;
using namespace std;

Runner::Runner()
{

}

void Runner::run(const std::string &source, const TestCases &test_cases) const
{
    Py_Initialize();
    PyObject *moduleMainString = PyUnicode_FromString("__main__");
    PyObject *moduleMain = PyImport_Import(moduleMainString);
    PyRun_SimpleStringFlags(source.c_str(), nullptr);
    PyObject *func = PyObject_GetAttrString(moduleMain, "main");
    for(const auto & test_case : test_cases){
        PyObject *args = PyTuple_Pack(2, PyFloat_FromDouble(85), PyFloat_FromDouble(20));
    }
    PyObject * res = PyObject_CallObject(func, args);
    cout << "output: " << PyUnicode_AsUTF8(res) << endl;
    Py_FinalizeEx();
}
