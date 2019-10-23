#ifndef TESTCASE_H
#define TESTCASE_H

#include <Python.h>

class IArgument
{
public:
    virtual PyObject * get_object() const = 0;
};

template<typename Type>
class InputArgument : public IArgument
{
public:
    InputArgument(Type value)
        : value_(value)
    {}

    PyObject * get_object() const override
    {
        return obj_impl();
    }

private:
    Type value_;
    PyObject * obj_impl() const;
};

#endif // TESTCASE_H
