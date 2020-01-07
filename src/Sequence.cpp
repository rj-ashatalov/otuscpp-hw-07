#include "Sequence.h"
#include "Bulk.h"
#include <iostream>

Sequence::Sequence(Bulk& bulk)
        : IInterpreterState(bulk)
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

    if (_commands.expressions.size() == 1)
    {
        std::stringstream currentTime;
        currentTime << std::time(nullptr);
        _bulk.Dispatch(Event::FIRST_COMMAND, currentTime.str());
    }

    if (_commands.expressions.size() >= static_cast<size_t>(_bulk.commandBufCount))
    {
        _bulk.SetState<Sequence>();
    }
}

void Sequence::Initialize()
{
    IInterpreterState::Initialize();
    _commands.expressions.clear();
}

void Sequence::Finalize()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    IInterpreterState::Finalize();
    if (_commands.expressions.size() > 0)
    {
        _bulk.Dispatch(Event::SEQUENCE_COMPLETE, static_cast<std::string>(_commands));
    }
}




