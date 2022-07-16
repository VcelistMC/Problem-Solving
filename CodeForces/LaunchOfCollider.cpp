#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;

    string s; cin >> s;

    vector<int> t;
    int num;
    while(n--){cin >> num; t.push_back(num);}

    int firstMoment = 1e9;

    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == 'R' && s[i+1] == 'L')
            firstMoment = min(firstMoment, (t[i+1] - t[i]) / 2);
    } 

    firstMoment != 1e9? cout << firstMoment: cout << -1;
}