#pragma once

#include <vector>
#include <string>
#include <memory>

#include "inputargument.h"

struct TestCase{
    std::vector<IArgument_ptr> arguments;
    std::string answer;
};

using TestCases = std::vector<TestCase>;
