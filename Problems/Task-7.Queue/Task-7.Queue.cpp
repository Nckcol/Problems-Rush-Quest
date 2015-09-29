// Task-7.Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main()
{
    srand((int) time(NULL));
    Queue<int> myQueue;

    for (int i = 0; i < 20; i++)
    {
        int *random = new int(rand() % 10);
        cout << *random << " ";
        myQueue.push(random);
    }
    cout << endl;

    myQueue.qsort();

    while (int * tmp = myQueue.pop())
    {
        cout << *tmp << " ";
    }
    cout << endl;

    return 0;
}

