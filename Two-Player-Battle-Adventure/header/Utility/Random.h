#pragma once
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time() to seed the number generator

namespace Utility
{
    class Random
    {
    public:
        static void Init() { srand(static_cast<unsigned int>(time(nullptr))); }
        static int GetRandomNumber(int min, int max) { return min + (rand() % (max - min + 1)); }
    };
}