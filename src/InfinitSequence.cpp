#include "InfinitSequence.h"
#include "Bulk.h"
#include <iostream>

InfinitSequence::InfinitSequence(Bulk& bulk)
        : IInterpreter(bulk)
{

}

void InfinitSequence::Initialize()
{
    IInterpreter::Initialize();
    if (_rootGroup == nullptr)
    {
        _rootGroup = std::make_shared<Group>();
        _parentGroup = nullptr;
        _currentGroup = _rootGroup;
    }
}

void InfinitSequence::Finalize()
{
    IInterpreter::Finalize();
    if (_currentGroup->parent == nullptr)
    {
        std::cout << __PRETTY_FUNCTION__ << " Expression complete" << std::endl;
        //TODO @a.shatalov: send message
        std::cout << "bulk: " << static_cast<std::string>(*_rootGroup) << std::endl;
        _rootGroup = nullptr;
    }
}

void InfinitSequence::Exec(std::string ctx)
{
    if (ctx == "{")
    {
        _parentGroup = _currentGroup;
        _currentGroup = std::make_shared<Group>();
        _bulk.SetState<InfinitSequence>();
        return;
    }

    if (ctx == "}")
    {
        if (_rootGroup == _currentGroup)
        {
            _currentGroup = nullptr;
            _bulk.SetState<Sequence>();
        }
        else
        {
            _parentGroup->expressions.push_back(_currentGroup);
            _currentGroup = _parentGroup;
            _bulk.SetState<InfinitSequence>();
        }
        return;
    }

    auto command = std::make_shared<Command>();
    command->value = ctx;
    _currentGroup->expressions.push_back(command);
}

