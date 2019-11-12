#ifndef WHILEBLOCK_H
#define WHILEBLOCK_H

#include "IBlock.h"

class WhileBlock
        : public IBlock
{
public:
    WhileBlock(const std::string & condition);
    void set_true_state(Block block);
private:
    Block true_state;
    std::string condition_;
    std::string get_source(int tab) const override;

};

#endif // WHILEBLOCK_H
