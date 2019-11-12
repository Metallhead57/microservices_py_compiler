#include "codegenerator.h"

CodeGenerator::CodeGenerator()
{

}

std::string CodeGenerator::get_prog(const std::list<Block> &functions) const
{
    std::string ret = "";
    int current_tab = 1;
    for(const auto & i : functions){
        auto head = i;
        while (head != nullptr) {
            ret += head->get_source(current_tab);
            head = head->next();
        }
        ret += "\n";
    }
    return ret;
}
