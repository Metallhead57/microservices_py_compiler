#ifndef IBLOCK_H
#define IBLOCK_H

#include <string>
#include <memory>

class IBlock;
using Block = std::shared_ptr<IBlock>;

class IBlock
{
public:
    IBlock();
    virtual std::string get_source(int tab) const = 0;
    void set_next(Block block);
    Block next() const;

protected:
    std::string tabs(int tabs) const;
private:
    Block next_ = nullptr;
};


#endif // IBLOCK_H
