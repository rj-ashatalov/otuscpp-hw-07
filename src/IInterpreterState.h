#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <memory>

class Bulk;

class IInterpreterState
{
    public:
        IInterpreterState(Bulk& bulk)
                : _bulk(bulk)
        {
        }

        virtual ~IInterpreterState()
        {
        }

        virtual void Initialize() {};
        virtual void Exec(std::string ctx) = 0;
        virtual void Finalize() {};

//        virtual operator std::string() const {return "";};

    protected:
        Bulk& _bulk;
};


struct IExpression
{
    virtual ~IExpression()
    {
    }

    virtual operator std::string() const = 0;
};

struct Command: public IExpression
{
    std::string value;

    virtual operator std::string() const override
    {
        return value;
    }
};

struct Group: public IExpression
{
    std::shared_ptr<Group> parent;
    std::vector<std::shared_ptr<IExpression>> expressions;

    virtual operator std::string() const override
    {
        if (expressions.size() <= 0)
        {
            return "";
        }

        std::stringstream output;
        std::for_each(expressions.begin(), std::prev(expressions.end()), [&output](auto &item)
        {
            output << static_cast<std::string>(*item) << ", ";
        });
        output << static_cast<std::string>(*expressions.back());
        return output.str();
    }
};
