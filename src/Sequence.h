#pragma once
#include <string>
#include <vector>
#include "IInterpreter.h"

class Sequence: public IInterpreter
{
    public:
        Sequence(Bulk& bulk);
        virtual void Exec(std::string ctx) override;
        virtual void Initialize() override;
        virtual void Finalize() override;

    private:
        Group _commands;
};
