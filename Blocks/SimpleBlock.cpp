#include "SimpleBlock.h"

SimpleBlock::SimpleBlock(const std::string &out)
    : out_(out)
{

}


std::string SimpleBlock::get_source(int tab) const
{
    return tabs(tab) + out_ + "\n";
}
