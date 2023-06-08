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

ll countSmaller(ll target, ll n, ll m){
    ll sum = 0;
    for(ll i = 1; i <= m; i++){
        sum += min(target/i, n);
    }
    return sum;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll lo = 0, hi = (n+1)*(m+1);
    while(lo < hi){
        ll mid = (lo+hi)/2;
        if(countSmaller(mid, n, m) < k) lo = mid+1;
        else hi = mid;
    }
    print(lo);
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