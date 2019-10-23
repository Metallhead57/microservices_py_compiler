#include "blockparser.h"

#include <fstream>

#include "Blocks/SimpleBlock.h"
#include "Blocks/FunctionBlock.h"
#include "Blocks/ConditionBlock.h"
#include "Blocks/WhileBlock.h"
#include "Blocks/ReturnBlock.h"

using json = nlohmann::json;

BlockParser::BlockParser()
{
}

std::list<IBlock *> BlockParser::parse_json(const BlockParser::json &o)
{
    std::list<IBlock*> ret;
    auto functions = o["functions"];
    //NOTE исполняться всегда должен main
    for(const auto & i : functions){
        ret.push_back(read_func(i));
    }
    return ret;
}

std::list<IBlock *> BlockParser::read_file(const std::string &filename)
{
    auto o = json::parse(std::ifstream(filename));
    return parse_json(o);
}

IBlock *BlockParser::read_simple(const BlockParser::json &o)
{
    std::string command = o["command"];
    return new SimpleBlock(command);
}

IBlock *BlockParser::read_condition(const BlockParser::json &o)
{
    std::string condition = o["condition"];
    ConditionlBlock * cond = new ConditionlBlock(condition);
    if(o.find("true_state") != o.end()){
        cond->set_true_state(read_commands(o["true_state"]));
    }
    if(o.find("false_state") != o.end()){
        cond->set_false_state(read_commands(o["false_state"]));
    }
    return cond;
}

IBlock *BlockParser::read_func(const BlockParser::json &o)
{
    std::string name = o["name"];
    std::vector<std::string> args;
    if(o.find("args") != o.end()){
        for(const auto & i : o["args"]){
            args.push_back(i);
        }
    }
    auto func = new FunctionBlock(name, args);

    func->set_next(read_commands(o["commands"]));
    return func;
}

IBlock *BlockParser::read_while(const BlockParser::json &o)
{
    std::string condition = o["condition"];
    ConditionlBlock * cond = new ConditionlBlock(condition);
    cond->set_true_state(read_commands(o["true_state"]));
    return cond;
}

IBlock *BlockParser::type_switch(const BlockParser::json &o)
{
    enum BlockType{
        Simple,
        Condition,
        While,
        Return
    };
    static const std::map<std::string, BlockType> types_{
        {"simple", Simple},
        {"condition", Condition},
        {"while", While},
        {"return", Return}
    };
    BlockType type = types_.at(o["type"]);
    switch(type){
    case Simple:    return read_simple(o);
    case Condition: return read_condition(o);
    case While:     return read_while(o);
    case Return:    return read_return(o);
    }
}

IBlock *BlockParser::read_return(const BlockParser::json &o)
{
    std::string value = o["value"];
    bool is_main = false;
    if(o.find("is_main") != o.end() && o["is_main"] == true){
        is_main = true;
    }
    return new ReturnBlock(value, is_main);
}

IBlock *BlockParser::read_commands(const BlockParser::json &o)
{
    IBlock * head = nullptr;
    IBlock * working = nullptr;
    for(const auto & command : o){
        IBlock * current = type_switch(command);
        if(head == nullptr){
            head = current;
            working = current;
        }
        else{
            working->set_next(current);
            working = working->next();
        }
    }
    return head;
}
