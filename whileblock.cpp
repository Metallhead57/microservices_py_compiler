#include "whileblock.h"

WhileBlock::WhileBlock(const std::string &condition)
    : condition_(condition)
{

}

void WhileBlock::set_true_state(IBlock *block)
{
    true_state = block;
}


std::string WhileBlock::get_source(int tab) const
{
    std::string ret = tabs(tab) + "while " + condition_ + ":\n";
    if(true_state != nullptr){
        IBlock * head = true_state;
        while(head != nullptr){
            ret += head->get_source(tab + 1);
            head = head->next();
        }
    }
    return ret;
}
