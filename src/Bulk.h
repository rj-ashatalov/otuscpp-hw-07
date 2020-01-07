#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <typeindex>
#include "IInterpreter.h"
#include "Sequence.h"
#include "InfinitSequence.h"

class Sequence;

class Bulk
{
    private:
        std::map<std::type_index, std::shared_ptr<IInterpreter>> _typeToInterpreter;

    public:

        Bulk(int commandBufCount)
                : commandBufCount(commandBufCount)
        {
            SetState<Sequence>();
        };

        template<typename T>
        void SetState()
        {
            if(_currentState)
            {
                _currentState->Finalize();
            }

            auto typeIndex = std::type_index(typeid(std::remove_reference_t<T>));
            auto it = _typeToInterpreter.find(typeIndex);
            if (it == _typeToInterpreter.end())
            {
                std::tie(it, std::ignore) = _typeToInterpreter.try_emplace(typeIndex, new T{*this});
            }
            _currentState = it->second;

            _currentState->Initialize();
        }

        std::shared_ptr<IInterpreter> GetState()
        {
            return _currentState;
        }

        void Run()
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            while (true)
            {
                std::cout << "Waiting for input:" << std::endl;
                std::string command;
                std::cin >> command;
                if (std::cin.eof())
                {
                    _currentState->Finalize();
                    break;
                }
                //TODO @a.shatalov: process command
                _currentState->Exec(command);
                std::cout << "Input is: " << command << std::endl;
            }
            std::cout << "Input complete aborting" << std::endl;
        };

        int commandBufCount;
    private:
        std::shared_ptr<IInterpreter> _currentState;
};
