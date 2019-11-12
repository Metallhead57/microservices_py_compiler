#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <list>
#include "Blocks/IBlock.h"


class CodeGenerator
{
public:
    CodeGenerator();
    std::string get_prog(const std::list<Block> & functions) const;

};

#endif // CODEGENERATOR_H
