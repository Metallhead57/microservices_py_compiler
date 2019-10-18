#include "conditionalblock.h"

ConditionalBlock::ConditionalBlock(const std::string &condition)
    : condition_(condition)
{

}


std::string ConditionalBlock::get_source(int tab) const
{
    std::string ret = tabs(tab) + "if " + condition_ + ":\n";
    if(true_state != nullptr){
        IBlock * head = true_state;
        while(head != nullptr){
            ret += head->get_source(tab + 1);
            head = head->next();
        }
    }
    if(false_state != nullptr){
        ret += tabs(tab) + "else:\n";
        IBlock * head = false_state;
        while(head != nullptr){
            ret += head->get_source(tab + 1);
            head = head->next();
        }
    }
    return ret;
}

void ConditionalBlock::set_true_state(IBlock *block)
{
    true_state = block;
}

void ConditionalBlock::set_false_state(IBlock *block)
{
    false_state = block;
}
