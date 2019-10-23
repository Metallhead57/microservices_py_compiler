#include "inputargument.h"

#include <string>

template<>
PyObject *InputArgument<int>::obj_impl() const
{
    return PyLong_FromLong(value_);
}

template<>
PyObject * InputArgument<float>::obj_impl() const
{
    return PyFloat_FromDouble(static_cast<double>(value_));
}

template<>
PyObject * InputArgument<std::string>::obj_impl() const
{
    return PyUnicode_FromString(value_.c_str());
}
