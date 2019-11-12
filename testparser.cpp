#include "testparser.h"
#include <fstream>

TestParser::TestParser()
{

}

TestCases TestParser::parse_json(const TestParser::json &o)
{
    TestCases ret;
    for(const auto & i : o["tests"]){
        TestCase test_case;
        if(i.find("args") != i.end()){
            test_case.arguments = get_arguments(i["args"]);
        }
        test_case.answer = i["answer"];
        ret.push_back(std::move(test_case));
    }
    return ret;
}

TestCases TestParser::from_file(const std::string &filename)
{
    auto o = json::parse(std::ifstream(filename));
    return parse_json(o);
}

std::vector<IArgument_ptr> TestParser::get_arguments(const TestParser::json &o)
{
    std::vector<IArgument_ptr> ret;
    for(const auto & i : o){
        if(i["type"] == "Integer"){
            int val = i["value"];
            ret.push_back(std::make_shared<InputArgument<int>>(val));
        }
        else if (i["type"] == "Float"){
            float val = i["value"];
            ret.push_back(std::make_shared<InputArgument<float>>(val));
        }
        else {
            std::string val = i["value"];
            ret.push_back(std::make_shared<InputArgument<std::string>>(val));
        }
    }
    return ret;
}
