#include <bits/stdc++.h>

using namespace std;


void checkMagazine(vector<string> magazine, vector<string> note) {
    map<string, int> hashMap;
    for(string word: magazine)
        hashMap[word]++;
    
    
    for(string word: note)
    {
        try
        {
            bool isUsedUp = hashMap.at(word);
            if(!isUsedUp) {cout << "No"; return;}
            hashMap[word]--;
        }
        catch(std::out_of_range& e){cout << "No"; return;}
    }
}

int main()
{
    int j, k;
    cin >> j >> k;
    vector<string> mag;
    vector<string> notee;
    for(int i = 0; i < j; i++)
    {
        string ele; cin >> ele;
        mag.push_back(ele);
    }
    for(int i = 0; i < k; i++)
    {
        string ele; cin >> ele;
        notee.push_back(ele);
    }

    checkMagazine(mag, notee);
}