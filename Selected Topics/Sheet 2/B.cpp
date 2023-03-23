#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define all(x) x.begin(), x.end()


void solve()
{
    int T; cin >> T;
    int n;
    while(T--){
        cin >> n;
        int currPowerOfTwo = 2, nextPowerOfTwo = 4;
        vi dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i < n+1; i++){
            if(i == nextPowerOfTwo){
                currPowerOfTwo = nextPowerOfTwo;
                nextPowerOfTwo = nextPowerOfTwo << 1;
            }
            dp[i] = 1 + dp[i-currPowerOfTwo];
        }
        int total= 0;
        for(int i = 0; i < n+1; i++){
            total += dp[i];
        }
        cout << total << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}