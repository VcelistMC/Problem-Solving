#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl

int solve(int i, int currSum, int total, vector<vi> &dp, int n, vi &coins){
    if(i == n) return abs(currSum - (total - currSum));
    int &val = dp[i][currSum];
    if(val != -1) return val;
    val = min(
        solve(i+1, currSum, total, dp, n, coins),
        solve(i+1, currSum+coins[i], total, dp, n, coins)
    );

    return val;
}

void solve()
{
    int n; cin >> n;
    vi coins(n);
    int total = 0;
    vector<vi> dp(105, vi(50005, -1));
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        total += coins[i];
    }
    print(
        solve(0, 0, total, dp, n, coins)
    );
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T; cin >> T;
    while(T--) {solve();}
    return 0;
}