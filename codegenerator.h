#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <list>
#include "IBlock.h"


class CodeGenerator
{
public:
    CodeGenerator();
    std::string get_prog(const std::list<IBlock*> & functions) const;

};

#endif // CODEGENERATOR_H
