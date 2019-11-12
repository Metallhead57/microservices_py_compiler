#ifndef TESTPARSER_H
#define TESTPARSER_H

#include <nlohmann/json.hpp>
#include "TestCase.h"

class TestParser
{
public:
    using json = nlohmann::json;
    TestParser();
    TestCases parse_json(const json & o);
    TestCases from_file(const std::string & filename);

private:
    std::vector<IArgument_ptr> get_arguments(const json & o);
};

#endif // TESTPARSER_H
