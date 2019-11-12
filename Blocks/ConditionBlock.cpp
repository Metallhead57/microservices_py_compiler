#include "ConditionBlock.h"

ConditionlBlock::ConditionlBlock(const std::string &condition)
    : condition_(condition)
{

}


std::string ConditionlBlock::get_source(int tab) const
{
    std::string ret = tabs(tab) + "if " + condition_ + ":\n";
    if(true_state != nullptr){
        Block head = true_state;
        while(head != nullptr){
            ret += head->get_source(tab + 1);
            head = head->next();
        }
    }
    if(false_state != nullptr){
        ret += tabs(tab) + "else:\n";
        Block head = false_state;
        while(head != nullptr){
            ret += head->get_source(tab + 1);
            head = head->next();
        }
    }
    return ret;
}

void ConditionlBlock::set_true_state(Block block)
{
    true_state = block;
}

void ConditionlBlock::set_false_state(Block block)
{
    false_state = block;
}
