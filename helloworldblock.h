#ifndef HELLOWORLDBLOCK_H
#define HELLOWORLDBLOCK_H

#include "IBlock.h"

class OutputBlock
        : public IBlock
{
public:
    OutputBlock(const std::string & out);
    std::string get_source(int tab) const override;

private:
    std::string out_;
};

#endif // HELLOWORLDBLOCK_H
