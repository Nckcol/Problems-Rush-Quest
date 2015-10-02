// Task-25.Palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

string max(string a, string b);
string makePalindrome(string input);

int main()
{
    string input , output;

    cin >> input;
    output = makePalindrome(input);
    cout << output << endl;
    cout << "Removed " << input.size() - output.size() << " symbols.";
    return 0;
}

string max(string a, string b)
{
    if (b.size() > a.size())
    {
        return b;
    }
    return a;
}

string makePalindrome(string input)
{
    if (input.size() <= 1) return input;
    if (input[0] == input[input.size()-1])
        return input[0] + makePalindrome(input.substr(1, input.size()-2)) + input[input.size() - 1];

    return max(makePalindrome(input.substr(0, input.size() - 1)), makePalindrome(input.substr(1, input.size() - 1)));
}

