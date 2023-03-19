#include<iostream>
#include<map>
#include<stack>
using namespace std;

bool isClosingBracket(char open, char close){
    map<char, char> brackets = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
    return brackets[open] == close;
}

string isBalanced(string s) {
    stack<char> charStack;
    for(char bracket : s){
        if(bracket == '(' || bracket == '[' || bracket == '{')
            charStack.push(bracket);
        else{
            if(charStack.size() == 0)
                return "NO";
            char poppedBracket = charStack.top();
            charStack.pop();
            if(!isClosingBracket(poppedBracket, bracket))
                return "NO";
        }
    }
    return (charStack.size() == 0? "YES": "NO");
}