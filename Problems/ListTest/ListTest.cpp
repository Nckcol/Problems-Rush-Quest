// ListTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include "List.h"


int main()
{
    srand(time(NULL));
    List<int> myList;
    for (int i = 0; i < 20; i++)
    {
        myList.pushBack(new int(rand() % 10));
    }
    std::cout << myList << std::endl;
    return 0;
}

