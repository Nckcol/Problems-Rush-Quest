// Task-32.TwoStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string a, b, r;

    cin >> a >> b;

    for (string::iterator i = a.begin(); i != a.end(); i++)
    {
        for (string::iterator j = b.begin(); j != b.end(); j++)
        {
            if (*i == *j)
            {
                r.push_back(*i);
                b.erase(j);
                break;
            }
        }

    }

    cout << r << endl;
    
    return 0;
}

