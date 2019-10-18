#include "IBlock.h"

IBlock::IBlock()
{

}

void IBlock::set_next(IBlock *block)
{
    next_ = block;
}

IBlock *IBlock::next() const
{
    return next_;
}

std::string IBlock::tabs(int tabs) const
{
    std::string ret = "";
    for(int i = 0; i < tabs; ++i){
        ret += "    ";
    }
    return ret;
}
