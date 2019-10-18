#ifndef IBLOCK_H
#define IBLOCK_H

#include <string>

class IBlock
{
public:
    IBlock();
    virtual std::string get_source(int tab) const = 0;
    void set_next(IBlock * block);
    IBlock * next() const;

protected:
    std::string tabs(int tabs) const;
private:
    IBlock * next_ = nullptr;
};

#endif // IBLOCK_H
