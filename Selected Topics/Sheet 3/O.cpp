//pipeline
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define llui long long unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl

ll sumUpTo(ll k){return k * (k+1LL)/2LL;}

ll sumFromTo(ll k1, ll k2){
    return (k1 <= k2)
        ? sumUpTo(k2) - sumUpTo(k1-1)
        : 0;
}

ll bs(ll n, ll k){
    ll lo = 1;
    ll hi = k;
    while(lo < hi){
        ll mid = (hi+lo) / 2;
        ll s = sumFromTo(mid, k);
        if (s == n) {
            return k - mid + 1;
        } else if (s > n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return k - lo + 2;
}


void solve()
{
    ll n, k;
    cin >> n >> k;
    if(n == 1){print(0);}
    else if(n <= k){print(1);}
    else{
        n--;
        k--;

        if(sumUpTo(k) < n){print(-1);}
        else{print(bs(n, k));}
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