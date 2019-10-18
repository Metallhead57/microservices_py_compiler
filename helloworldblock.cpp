#include "helloworldblock.h"

OutputBlock::OutputBlock(const std::string &out)
    : out_(out)
{

}


std::string OutputBlock::get_source(int tab) const
{
    return tabs(tab) + out_ + "\n";
}
