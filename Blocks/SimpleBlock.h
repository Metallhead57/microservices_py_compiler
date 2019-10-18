#ifndef HELLOWORLDBLOCK_H
#define HELLOWORLDBLOCK_H

#include "IBlock.h"

class SimpleBlock
        : public IBlock
{
public:
    SimpleBlock(const std::string & out);
    std::string get_source(int tab) const override;

private:
    std::string out_;
};

#endif // HELLOWORLDBLOCK_H
