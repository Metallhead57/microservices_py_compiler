#ifndef TESTCASE_H
#define TESTCASE_H

#include <Python.h>
#include <memory>

class IArgument
{
public:
    virtual PyObject * get_object() const = 0;
    virtual ~IArgument() = default;
};

using IArgument_ptr = std::shared_ptr<IArgument>;

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
