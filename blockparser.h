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
    std::list<Block> parse_json(const json & o);
    std::list<Block> read_file(const std::string & filename);
private:
    Block read_simple(const json & o);
    Block read_condition(const json & o);
    Block read_func(const json & o);
    Block read_while(const json & o);
    Block type_switch(const json & o);
    Block read_return(const json & o);
    Block read_commands(const json & o);
};

#endif // JSON_PARSER_H
