#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int main()
{
    int n; cin >> n;
    set<char> letters;
    while(n--)
    {
        letters.clear();
        string str; cin >> str;
        for(int i = 0; i < str.size(); i++)
        {
            letters.insert(str[i]);
        }

        cout << ceil(letters.size() / 3 + 1) << endl;
    }
}