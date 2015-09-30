// Task-5.List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "list.cpp"
#include <ctime>

using namespace std;

void fillRandom(List<int> &list, int count);
void relocate(List<int> &list, List<int> &more, List<int> &less, int N);

int main()
{
    int N;
    List<int> numbers;
    List<int> lessThanN;
    List<int> moreThanN;

    fillRandom(numbers, 20);

    cout << numbers << endl;

    cout << "Enter N: ";
    cin >> N;

    relocate(numbers, moreThanN, lessThanN, N);
    cout << "More than N: " << moreThanN << endl;
    cout << "Less than N: " << lessThanN << endl;

    return 0;
}

void fillRandom(List<int> &list, int count)
{
    srand(time(0));
    while (count)
    {
        list.pushBack(new int(rand() % 200 - 100));
        count--;
    }
}

void relocate(List<int> &list, List<int> &more, List<int> &less, int N)
{
    while (int* currentData = list.popBack())
    {
        if (*currentData > N)
        {
            more.pushBack(currentData);
        }
        else
        {
            less.pushBack(currentData);
        }
    }
}

