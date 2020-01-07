#include "Sequence.h"
#include "Bulk.h"
#include <iostream>

Sequence::Sequence(Bulk& bulk)
        : IInterpreter(bulk)
{

}

void Sequence::Exec(std::string ctx)
{
    if (ctx == "{")
    {
        _bulk.SetState<InfinitSequence>();
        return;
    }

    auto command = std::make_shared<Command>();
    command->value = ctx;
    _commands.expressions.push_back(command);

    if (_commands.expressions.size() >= static_cast<size_t>(_bulk.commandBufCount))
    {
        _bulk.SetState<Sequence>();
    }
}

void Sequence::Initialize()
{
    IInterpreter::Initialize();
    _commands.expressions.clear();
}

void Sequence::Finalize()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    IInterpreter::Finalize();
    //TODO @a.shatalov: message send commands;
    std::cout << "bulk: " << static_cast<std::string>(_commands) << std::endl;
}




