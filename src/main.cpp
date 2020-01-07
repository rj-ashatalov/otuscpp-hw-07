#include <iostream>
#include "Bulk.h"

//! Main app function
int main(int, char const *argv[])
{
    Bulk bulk{atoi(argv[1])};
    bulk.Run();
    //todo
    return 0;
}