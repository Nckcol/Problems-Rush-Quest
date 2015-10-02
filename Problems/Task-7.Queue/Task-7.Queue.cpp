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

    cout << "Calculate timing of insert sort..." << endl << endl;

    clock_t insertSortTiming = clock();

    for (int i = 0; i < 10000; i++)
    {
        Queue<int> *myQueue = new Queue<int>();

        for (int i = 0; i < 100; i++)
        {
            myQueue->push(new int(rand() % 100));
        }

        myQueue->isort();

        delete myQueue;
    }

    insertSortTiming = clock() - insertSortTiming;
    cout << "Result of 10000 iterations: " <<  (float) insertSortTiming / CLOCKS_PER_SEC << endl;
    cout << "Average time for iteration: " << (float)insertSortTiming / CLOCKS_PER_SEC / 10000 << endl << endl;

    cout << "Calculate timing of quick sort..." << endl << endl;
    clock_t quickSortTiming = clock();

    for (int i = 0; i < 10000; i++)
    {
        Queue<int> *myQueue = new Queue<int>();

        for (int i = 0; i < 100; i++)
        {
            myQueue->push(new int(rand() % 100));
        }

        myQueue->qsort();

        delete myQueue;
    }

    quickSortTiming = clock() - quickSortTiming;
    cout << "Result of 10000 iterations: " << (float) quickSortTiming / CLOCKS_PER_SEC << endl;
    cout << "Average time for iteration: " << (float)quickSortTiming / CLOCKS_PER_SEC / 10000 << endl << endl;

    return 0;
}

