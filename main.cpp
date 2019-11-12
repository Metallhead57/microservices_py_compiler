#include <iostream>
#include <list>

#include "codegenerator.h"
#include "runner.h"
#include "blockparser.h"
#include "testparser.h"

using namespace std;

int main()
{
    //TODO удаление всех блоков
    BlockParser parser;
    auto functions = parser.read_file("example.json");
    TestParser test_parser;
    auto tests = test_parser.from_file("test_example.json");
    CodeGenerator code;
    cout << code.get_prog(functions) << endl;
    Runner runner;
    auto res = runner.run(code.get_prog(functions), tests);
    for(const auto & i : res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
