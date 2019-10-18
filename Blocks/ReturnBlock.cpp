#include "ReturnBlock.h"

ReturnBlock::ReturnBlock(const std::string &value, bool is_main)
    : value_(value)
    , main_(is_main)
{

}


std::string ReturnBlock::get_source(int tab) const
{
    std::string ret = tabs(tab) + "return ";
    if(main_){
        ret += "str(" + value_ + ")";
    }
    else {
        ret += value_;
    }
    ret += "\n";
    return ret;
}
