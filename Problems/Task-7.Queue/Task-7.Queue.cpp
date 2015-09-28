// Task-7.Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main()
{
	Queue<int> myQueue;

	myQueue.push(new int(1));
	myQueue.push(new int(2));
	myQueue.push(new int(3));
	myQueue.push(new int(4));
	myQueue.push(new int(5));


	while (int * tmp = myQueue.pop())
	{
		cout << *tmp << " ";
	}

    return 0;
}

