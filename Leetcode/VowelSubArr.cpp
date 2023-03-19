#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.size();
    if(len < 5){return 0;}
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int i = 0, j = 0;
    int foundVowels = 0;
    int foundSubStr = 0;
    while(i < len - 5){
        char curr = str[j];
        if(vowels.find(curr) != vowels.end()){
            j++;
            foundVowels++;
            if(foundVowels >= 5) foundSubStr++;
        }
        else{
            if(foundVowels < 5){
                j++;
                i = j;
                foundVowels = 0;
            }
            else{
                i++;
                j = i + 5;
                foundVowels = 5;
            }
        }
    }
    return foundSubStr;
}