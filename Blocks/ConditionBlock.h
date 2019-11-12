#ifndef CONDITIONALBLOCK_H
#define CONDITIONALBLOCK_H

#include "IBlock.h"

class ConditionlBlock
        : public IBlock
{
public:
    ConditionlBlock(const std::string & condition);
    std::string get_source(int tab) const;

    void set_true_state(Block block);
    void set_false_state(Block block);

private:
    std::string condition_;
    Block true_state = nullptr;
    Block false_state = nullptr;
};

#endif // CONDITIONALBLOCK_H
