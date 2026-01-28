#include <iostream>
#include <string>
#include "Array.hpp"

static void testIntArray()
{
    std::cout << "== int array ==" << std::endl;

    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i) * 10;

    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    std::cout << std::endl;
}

static void testCopyIndependence()
{
    std::cout << "== deep copy ==" << std::endl;

    Array<int> a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;

    Array<int> b(a);        // copy ctor
    Array<int> c; c = a;    // assignment

    a[1] = 999;             // modify original

    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "b[1] = " << b[1] << " (should stay 2)" << std::endl;
    std::cout << "c[1] = " << c[1] << " (should stay 2)" << std::endl;

    std::cout << std::endl;
}

static void testStringArray()
{
    std::cout << "== string array ==" << std::endl;

    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";

    std::cout << s[0] << " " << s[1] << std::endl;
    std::cout << std::endl;
}

static void testBounds()
{
    std::cout << "== bounds check ==" << std::endl;

    Array<int> a(2);
    a[0] = 10; a[1] = 20;

    try
    {
        std::cout << a[2] << std::endl; // out of bounds
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testEmpty()
{
    std::cout << "== empty array ==" << std::endl;

    Array<int> e;
    std::cout << "size = " << e.size() << std::endl;

    try
    {
        e[0] = 1;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    testEmpty();
    testIntArray();
    testCopyIndependence();
    testStringArray();
    testBounds();
    return 0;
}
