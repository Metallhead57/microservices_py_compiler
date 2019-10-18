#ifndef RETURNBLOCK_H
#define RETURNBLOCK_H

#include "IBlock.h"

class ReturnBlock
        : public IBlock
{
public:
    ReturnBlock(const std::string & value, bool is_main = false);
    std::string get_source(int tab) const override;
private:
    std::string value_;
    bool main_;
};

#endif // RETURNBLOCK_H
