#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <list>
#include "Blocks/IBlock.h"
#include <nlohmann/json.hpp>


class BlockParser
{
    using json = nlohmann::json;
public:
    BlockParser();
    std::list<IBlock*> parse_json(const json & o);
    std::list<IBlock*> read_file(const std::string & filename);
private:
    IBlock * read_simple(const json & o);
    IBlock * read_condition(const json & o);
    IBlock * read_func(const json & o);
    IBlock * read_while(const json & o);
    IBlock * type_switch(const json & o);
    IBlock * read_return(const json & o);
    IBlock * read_commands(const json & o);
};

#endif // JSON_PARSER_H