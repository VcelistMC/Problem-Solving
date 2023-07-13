#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ll long long
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl


void solve()
{
    int n; cin >> n;
    vector<ll> r1(n), r2(n);
    inputVec(r1); inputVec(r2);

    vll dp1(n+1, 0), dp2(n+1, 0);

    for(int i = 1; i <= n; i++){
        dp1[i] = max(dp1[i-1], dp2[i-1] + r1[i-1]);
        dp2[i] = max(dp2[i-1], dp1[i-1] + r2[i-1]);
    }

    print(max(dp1[n], dp2[n]));
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