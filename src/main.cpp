#include <iostream>
#include "print_ip.h"

//! Main app funtion
int main(int, char const *[])
{
    //todo
    char charIP = -1;

    std::cout<<toString(charIP)<<std::endl;

    std::cout<<toString(static_cast<short>(0))<<std::endl;

    std::cout<<toString(static_cast<int>(2130706433))<<std::endl;

    std::cout<<toString(8875824491850138409LL)<<std::endl;

    std::cout<<toString(std::string{"192.168.1.1"})<<std::endl;

    std::list testList{1, 2, 3, 4};
    std::cout<<toString(testList)<<std::endl;

    std::vector testVector{10, 20, 30, 40};
    std::cout<<toString(testVector)<<std::endl;

//    std::cout<<toString(std::make_tuple(100, std::string{"200"}, 300, 400))<<std::endl;
    std::cout<<toString(std::make_tuple(static_cast<char>(50), static_cast<char>(100), static_cast<char>(200)))<<std::endl;
    return 0;
}