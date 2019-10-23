#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include "TestCase.h"

class Runner
{
public:
    Runner();
    void run(const std::string & source, const TestCases & test_cases) const;
};

#endif // RUNNER_H
