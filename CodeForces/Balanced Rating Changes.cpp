#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef vector<int> vi;

void solve()
{
    int n; cin >> n;
    int num;
    int flag = 1;
    while (n--)
    {
        cin >> num;
        if(num % 2 == 0) cout << num/2 << "\n";
        else
        {
            cout << (num + flag) / 2 << "\n";
            flag *= -1;
        }
        
    }
    
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