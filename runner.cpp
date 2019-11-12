#include "runner.h"
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;
using namespace std;

Runner::Runner()
{

}

std::vector<bool> Runner::run(const std::string &source, const TestCases &test_cases) const
{
    std::vector<bool> ret;
    ret.reserve(test_cases.size());
    ret.clear();
    Py_Initialize();
    PyObject *moduleMainString = PyUnicode_FromString("__main__");
    PyObject *moduleMain = PyImport_Import(moduleMainString);
    PyRun_SimpleStringFlags(source.c_str(), nullptr);
    PyObject *func = PyObject_GetAttrString(moduleMain, "main");
    for(const auto & test_case : test_cases){
        PyObject * args = set_args(test_case);
        PyObject * res = PyObject_CallObject(func, args);
        ret.push_back(PyUnicode_AsUTF8(res) == test_case.answer);
        Py_DecRef(res);
        Py_DecRef(args);
    }
    Py_Finalize();
    return ret;
}

PyObject *Runner::set_args(const TestCase &test_case) const
{
    auto size = test_case.arguments.size();
    PyObject * args = PyTuple_New(static_cast<ssize_t>(size));
    for(size_t i = 0; i < size; ++i){
        PyTuple_SetItem(args, static_cast<ssize_t>(i), test_case.arguments[i]->get_object());
    }
    return args;
}
