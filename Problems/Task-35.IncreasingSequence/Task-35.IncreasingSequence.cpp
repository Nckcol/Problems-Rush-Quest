// Task-35.IncreasingSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;


queue<int> dfs(int ** matrix, int size, int n, queue<int> sequence);
queue<int> longestChain(int ** matrix, int size);


int main()
{
    int n;

    cout << "Enter number of pairs likely 'A < B': ";
    cin >> n;

    int ** adjacencyMatrix = new int * [2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        adjacencyMatrix[i] = new int[2 * n];
        for (int j = 0; j < 2 * n; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    

    string a;
    string b;
    map<string, int> elementToInt;
    map<int, string> intToElement;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> b;
        if (!elementToInt.count(a))
        {
            intToElement[count] = a;
            elementToInt[a] = count++;
        }
        if (!elementToInt.count(b))
        {
            intToElement[count] = b;
            elementToInt[b] = count++;
        }
        adjacencyMatrix[elementToInt[a]][elementToInt[b]] = 1;
    }

    queue<int> chain = longestChain(adjacencyMatrix, count);

    if (chain.size() == count)
    {
        cout << "Increasing sequence can be formed.";
    }

    cout << "Sequence:" << endl;
    while (!chain.empty())
    {
        cout << intToElement[chain.front()] << " ";
        chain.pop();
    }
    cout << endl;


    return 0;
}

queue<int> dfs(int ** matrix, int size, int n, queue<int> sequence)
{
    sequence.push(n);
    queue<int> max = sequence;

    for (int i = 0; i < size; i++)
    {
        if (matrix[n][i])
        {
            queue<int> buff = dfs(matrix, size, i, sequence);
            if (max.size() < buff.size()) max = buff;
        }
    }

    return max;
}

queue<int> longestChain(int ** matrix, int size)
{
    queue<int> max;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j])
            {
                queue<int> buff = dfs(matrix, size, i, queue<int>());
                if (max.size() < buff.size()) max = buff;
            }
    

    return max;
}

