// Task-14.HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

void swap(int &n1, int &n2);
void heapSort(int* a, int n);

int main()
{
    int const n = 20;
    int *a = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand()%100;
        cout << a[i] << " ";
    }
    cout << endl;

    heapSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void heapSort(int* a, int n)
{
    int offset = 0;
    bool repeat = false;

    for (;;)
    {
        repeat = false;
        for (int i = 0; i < n; i++)
        {
            int parent = i + offset;
            int firstChild = 2 * i + offset + 1;
            int secondChild = 2 * i + offset + 2;

            if (secondChild < n)
            {
                if ((a[parent] > a[firstChild]) ||
                    (a[parent] > a[secondChild]))
                {
                    if (a[firstChild] < a[secondChild])
                    {
                        swap(a[parent], a[firstChild]);
                        repeat = true;
                    }
                    else if (a[secondChild] < a[firstChild])
                    {
                        swap(a[parent], a[secondChild]);
                        repeat = true;
                    }
                }
                
                if (a[secondChild] < a[firstChild])
                {
                    swap(a[firstChild], a[secondChild]);
                    repeat = true;
                }
            }
            else if (firstChild < n)
            {
                if (a[parent] > a[firstChild])
                {
                    swap(a[parent], a[firstChild]);
                    repeat = true;
                }
            }
        }
        if (!repeat) offset++;
        if (offset + 2 == n) break;
    }
}
