// Task-14.HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;


void rHeapSort(int * begin, int * end);
int * _leftChild(int * begin, int * parent);
int * _rightChild(int * begin, int * parent);
void _shiftDown(int * begin, int * end);
void swap(int & a, int & b);
int & min(int & a, int & b);
void heapSort(int* a, int n);

int main()
{
    int const n = 20;
    int *a = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand()%10;
        cout << a[i] << " ";
    }
    cout << endl;

    // heapSort(a, n); // Iterative version
    rHeapSort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

int & min(int & a, int & b)
{
    if (b < a)
        return b;
    return a;
}

int & max(int & a, int & b)
{
    if (b > a)
        return b;
    return a;
}

void rHeapSort(int * begin, int * end)
{
    for (int * i = begin + distance(begin, end) / 2; i >= begin; i--)
        _shiftDown(i, end);

    for (int * i = end - 1; i > begin; i--)
    {
        swap(*begin, *i);
        _shiftDown(begin, i);
    }
}

int * _leftChild(int * begin, int * parent)
{
    return begin + 2 * distance(begin, parent) + 1;
}

int * _rightChild(int * begin, int * parent)
{
    return begin + 2 * distance(begin, parent) + 2;
}

void _shiftDown(int * begin, int * end)
{
    int *current = begin;
    int * maxChild = _leftChild(begin, current);
    
    while (maxChild < end)
    {
        
        if (_rightChild(begin, current) < end)
        {
            if (*_leftChild(begin, current) < *_rightChild(begin, current))
            {
                maxChild = _rightChild(begin, current);
            }
        }

        if (*current < *maxChild)
        {
            swap(*current, *maxChild);
        }
        else
        {
            break;
        }

        current = maxChild;
        maxChild = _leftChild(begin, current);
    }
}

void heapSort(int * a, int n)
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
                    swap(a[parent], min(a[firstChild], a[secondChild]));
                    repeat = true;
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
