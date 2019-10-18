#ifndef FUNCINPUTBLOCK_H
#define FUNCINPUTBLOCK_H

#include "IBlock.h"
#include <vector>

class FuncInputBlock
        : public IBlock
{
public:
    FuncInputBlock(const std::string & name,
                   const std::vector<std::string> & args);
    std::string get_source(int) const override;

private:
    std::string name_;
    std::vector<std::string> args_;

};

#endif // FUNCINPUTBLOCK_H
