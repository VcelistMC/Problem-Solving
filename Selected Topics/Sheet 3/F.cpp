// Sagheer and Nubian Market
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

ll adjust(vi &items, vector<ll> &adjusted, int k){
    for(int i = 0; i < items.size(); i++){
        adjusted[i] = items[i] + (i+1)*((ll)k);
    }
    sort(all(adjusted));
    ll c = 0;
    for(int i = 0; i < k; i++) c += adjusted[i];

    return c;
}

void solve()
{
    int n, s;
    cin >> n >> s;
    vi items(n);
    vector<ll> adjusted(n);
    for(int i = 0; i < n; i++){
        cin >> items[i];
        adjusted[i] = items[i];
    }

    int l = 0, r = n+1;
    while(l < r-1){
        int mid = (l+r)/2;
        ll pCost = adjust(items, adjusted, mid);

        if(pCost <= s) l = mid;
        else r = mid;
    }
    ll cCost = adjust(items, adjusted, l);
    cout << l << " " << cCost << endl;
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