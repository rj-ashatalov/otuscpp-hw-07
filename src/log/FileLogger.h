#pragma once

//#include <iostream>
#include <string>

struct FileLogger
{
    void PrepareFilename(std::string fileName)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        //
    };

    void Log(std::string message)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
//        std::cout << message << std::endl;
    };
};