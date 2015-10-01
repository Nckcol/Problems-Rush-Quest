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

    myQueue.qsort();

    while (int * tmp = myQueue.pop())
    {
        cout << *tmp << " ";
    }
    cout << endl;

    cout << "Calculate timing of insert sort..." << endl;

    clock_t insertSortTiming = clock();

    for (int i = 0; i < 10000; i++)
    {
        Queue<int> *myQueue = new Queue<int>();

        for (int i = 0; i < 100; i++)
        {
            myQueue->push(new int(rand() % 1000));
        }

        myQueue->isort();

        delete myQueue;
    }
    insertSortTiming = clock() - insertSortTiming;
    cout << "Result: " <<  (float) insertSortTiming / CLOCKS_PER_SEC << endl;
    cout << "Calculate timing of quick sort..." << endl;
    clock_t quickSortTiming = clock();
    for (int i = 0; i < 10000; i++)
    {
        Queue<int> *myQueue = new Queue<int>();

        for (int i = 0; i < 100; i++)
        {
            myQueue->push(new int(rand() % 1000));
        }

        myQueue->qsort();

        delete myQueue;
    }

    quickSortTiming = clock() - quickSortTiming;
    cout << "Result: " << (float) quickSortTiming / CLOCKS_PER_SEC << endl;

    return 0;
}

