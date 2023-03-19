#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;

void solve()
{
    int n; cin >> n;
    map<int, int> freqMap;
    int i = n, num;
    bool ok = true;
    while (i--)
    {
        cin >> num;
        freqMap[num]++;
    }

    for(map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); it++)
    {
        if(it->second != 1 && it->second - 1 > n - it->second) ok = false;
    }

    cout << (ok? "YES\n" : "NO\n");
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    solve();
    return 0;
}