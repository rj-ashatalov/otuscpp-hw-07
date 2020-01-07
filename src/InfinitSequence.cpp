#include "InfinitSequence.h"
#include "Bulk.h"
#include <iostream>

InfinitSequence::InfinitSequence(Bulk& bulk)
        : IInterpreterState(bulk)
{

}

void InfinitSequence::Initialize()
{
    IInterpreterState::Initialize();
    if (_rootGroup == nullptr)
    {
        _currentGroup = std::make_shared<Group>();
        _rootGroup = _currentGroup;
        _awaitFirstCommand = true;
    }
}

void InfinitSequence::Finalize()
{
    IInterpreterState::Finalize();
    if (_currentGroup == nullptr)
    {
        std::cout << __PRETTY_FUNCTION__ << " Expression complete" << std::endl;
        _bulk.Dispatch(Event::SEQUENCE_COMPLETE, static_cast<std::string>(*_rootGroup));
        _rootGroup = nullptr;
    }
}

void InfinitSequence::Exec(std::string ctx)
{
    if (ctx == "{")
    {
        auto group = std::make_shared<Group>();
        group->parent = _currentGroup;
        _currentGroup = group;
        _bulk.SetState<InfinitSequence>();
        return;
    }

    if (ctx == "}")
    {
        if (_currentGroup->parent == nullptr)
        {
            _currentGroup = nullptr;
            _bulk.SetState<Sequence>();
        }
        else
        {
            _currentGroup->parent->expressions.push_back(_currentGroup);
            _currentGroup = _currentGroup->parent;
            _bulk.SetState<InfinitSequence>();
        }
        return;
    }

    auto command = std::make_shared<Command>();
    command->value = ctx;
    _currentGroup->expressions.push_back(command);
    if (_awaitFirstCommand)
    {
        _awaitFirstCommand = false;
        _bulk.Dispatch(Event::FIRST_COMMAND, "123");
    }
}

