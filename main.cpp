#include <iostream>
#include <list>

#include "codegenerator.h"
#include "runner.h"
#include "json_parser.h"

using namespace std;

int main()
{
    //TODO удаление всех блоков
    json_parser parser;
    auto functions = parser.read_file("example.json");

    CodeGenerator code;
    cout << code.get_prog(functions) << endl;
    Runner runner;
    runner.run(code.get_prog(functions));

    return 0;
}
