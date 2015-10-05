// Task-3.FoldedRibbon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

char isCorrect(string b);
string restoreFolding(string bending);
string getBendings(string folding);
string bend(string & folding, string::iterator current, bool invert);


#define PUSH 'O' 
#define PULL 'K'
#define FRONT 'P'
#define BACK 'Z'
#define PUSH_S "O" 
#define PULL_S "K"
#define FRONT_S "P"
#define BACK_S "Z"

int main()
{
    string folding;
    string bendings;
    string part;
    
    cout << "A. Restore of folding by bendings" << endl;
    cout << "B. Get bendings by folding algorithm" << endl;

    cin >> part;
    if (part == "A")
    {
        cin >> bendings;
        cout << restoreFolding(bendings) << endl;
    }
    else if (part == "B")
    {
        cin >> folding;
        cout << getBendings(folding) << endl;
    }
    return 0;
}

char isCorrect(string b)
{
    if (b.size() == 1)
    {
        if (b[0] == PUSH) return -1;
        if (b[0] == PULL) return 1;
    }

    if (isCorrect(b.substr(0, b.size() / 2)) * 
        isCorrect(b.substr(b.size() / 2, b.size() / 2)) < 0)
    {
        if (b[b.size() / 2] == PUSH) return -1;
        if (b[b.size() / 2] == PULL) return 1;
    }
    return 0;
}

string restoreFolding(string bendings)
{
    if (!isCorrect(bendings))
    {
        return "Input is incorrect";
    }
    
    int n = bendings.size();
    char next;
    string folding;

    while (n > 0)
    {
        n = n / 2;
        next = bendings[n];
        if (!folding.empty())
        {
            if (folding.back() == BACK)
            {
                next = bendings[bendings.size() - n];
            }
        }

        if (next == PUSH)
        {
            folding.push_back(BACK);
        }
        else
        {
            folding.push_back(FRONT);
        }
    }

    return folding;
}

string getBendings(string folding)
{
    return bend(folding, folding.begin(), false);
}

string bend(string & folding, string::iterator current, bool invert)
{
    if (current == folding.end()) return "";

    if ((*current == BACK && !invert) || (*current == FRONT && invert))
    {
        return bend(folding, current + 1, invert) + PULL_S + bend(folding, current + 1, !invert);
    }
    else
    {
        return bend(folding, current + 1, !invert) + PUSH_S + bend(folding, current + 1, invert);
    }
}
