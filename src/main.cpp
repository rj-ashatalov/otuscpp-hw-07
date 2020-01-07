#include <iostream>
#include <regex>
#include "Bulk.h"
#include "log/ConsoleLogger.h"
#include "log/FileLogger.h"

//! Main app function
int main(int, char const* argv[])
{
    Bulk bulk{atoi(argv[1])};

    ConsoleLogger consoleLogger;
    bulk.Subscribe(Event::SEQUENCE_COMPLETE, [&](auto&& message)
    {
        consoleLogger.Log("bulk: " + message);
    });

    FileLogger fileLogger;
    bulk.Subscribe(Event::FIRST_COMMAND, [&](auto&& message)
    {
        fileLogger.PrepareFilename("bulk" + message);
    });
    bulk.Subscribe(Event::SEQUENCE_COMPLETE, [&](auto&& message)
    {
        fileLogger.Log(std::regex_replace(message, std::regex{", "}, "\n"));
    });

    bulk.Run();
    return 0;
}