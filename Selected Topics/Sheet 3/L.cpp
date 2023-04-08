// March Rain

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

bool isOk(vector<ll> &holes, ll mid, int k){
    ll last = holes[0];
    for(int i = 1; i < holes.size(); i++){
        if(holes[i] - last + 1 > mid){
            k--;
            last = holes[i];
            if(k < 0) return false;
        }
    }
    k--;
    return k >= 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> holes(n);
    inputVec(holes);
    ll lo = 0, hi=1e9, ans;
    while(lo <= hi){
        ll mid = (hi+lo)/2;
        if(isOk(holes, mid, k)){
            hi = mid-1;
            ans = mid;
        }else{
            lo = mid+1;
        }
    }
    print(ans);
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