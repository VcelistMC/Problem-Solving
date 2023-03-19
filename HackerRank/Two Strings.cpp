//unsolved

#include<iostream>
#include <map>
using namespace std;

map<char, bool> parseInput(string s)
{
    map<char, bool> returnVal;
    for(char c : s)
        returnVal[c] =  true;
    return returnVal;
}

string solve(map<char, bool> m, string s)
{
    for(char c : s)
    {
        if(m[c]);
            return "YES";
    }
    return "NO";
}

void twoStrings(string s1, string s2) 
{
    if(s1.length() > s2.length())
    {
        map<char, bool> biggerWord = parseInput(s1);
        cout << solve(biggerWord, s2);
    }
    else
    {
        map<char, bool> biggerWord = parseInput(s2);
        cout << solve(biggerWord, s1);
    }
}