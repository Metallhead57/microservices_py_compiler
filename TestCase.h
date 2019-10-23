#pragma once

#include <vector>
#include <string>

#include "inputargument.h"

struct TestCase{
    std::vector<IArgument*> arguments;
    std::string answer;
    ~TestCase(){
        for(auto & i : arguments){
            delete i;
        }
    }
};

using TestCases = std::vector<TestCase>;
