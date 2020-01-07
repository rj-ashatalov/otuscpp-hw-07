#define BOOST_TEST_MODULE app_test_module

#include "../lib.h"
#include <boost/test/unit_test.hpp>
#include "Bulk.h"

BOOST_AUTO_TEST_SUITE(app_test_suite)

BOOST_AUTO_TEST_CASE(test_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_solution)
{
    char charIP = -1;
    BOOST_CHECK(toString(charIP) == "255");

    BOOST_CHECK(toString(static_cast<short>(65281)) == "255.1");

    BOOST_CHECK(toString(static_cast<int>(2130706433)) == "127.0.0.1");

    BOOST_CHECK(toString(8875824491850138409LL) == "123.45.67.89.101.112.131.41");

    BOOST_CHECK(toString(std::string{"192.168.1.1"}) == "192.168.1.1");

    std::list testList{1, 2, 3, 4};
    BOOST_CHECK(toString(testList) == "1.2.3.4");

    std::vector testVector{10, 20, 30, 40};
    BOOST_CHECK(toString(testVector) == "10.20.30.40");

    BOOST_CHECK(toString(std::make_tuple(static_cast<char>(50), static_cast<char>(100), static_cast<char>(200))) == "50.100.200");
}

BOOST_AUTO_TEST_SUITE_END()
