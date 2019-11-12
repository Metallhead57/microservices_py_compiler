#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include "TestCase.h"

class Runner
{
public:
    Runner();
    std::vector<bool> run(const std::string & source, const TestCases & test_cases) const;

private:
    PyObject * set_args(const TestCase & test_case) const;
};

#endif // RUNNER_H
