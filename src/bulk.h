#pragma once

#include <iostream>

class Bulk
{
    public:
        Bulk(int commandBufCount)
            : _commandBufCount(commandBufCount)
        {
        };

        void Run()
        {
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
            while (true)
            {
                std::cout<<"Waiting for input:"<<std::endl;
                std::string command;
                std::cin>>command;
                if (std::cin.eof())
                {
                    break;
                }
                std::cout<<"Input is: " <<command<<std::endl;
            }
            std::cout<<"Input complete aborting"<<std::endl;
        };

    private:
        int _commandBufCount;
};
