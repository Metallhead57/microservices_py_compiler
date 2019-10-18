#include "FunctionBlock.h"

FunctionBlock::FunctionBlock(const std::string &name, const std::vector<std::string> &args)
    : name_(name)
    , args_(args)
{

}

std::string FunctionBlock::get_source(int) const
{
    std::string ret = "def " + name_ + "(";
    if(args_.size() > 0){
        size_t last = args_.size() - 1;
        for(size_t i = 0; ; ++i){
            ret += args_[i];
            if(i == last){
                break;
            }
            ret += ", ";
        }
    }
    ret += "):\n";
    return ret;
}
