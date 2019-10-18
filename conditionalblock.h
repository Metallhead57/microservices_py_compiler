#ifndef CONDITIONALBLOCK_H
#define CONDITIONALBLOCK_H

#include "IBlock.h"

class ConditionalBlock
        : public IBlock
{
public:
    ConditionalBlock(const std::string & condition);
    std::string get_source(int tab) const;

    void set_true_state(IBlock * block);
    void set_false_state(IBlock * block);

private:
    std::string condition_;
    IBlock * true_state = nullptr;
    IBlock * false_state = nullptr;
};

#endif // CONDITIONALBLOCK_H
