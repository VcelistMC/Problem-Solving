#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl


void getDivs(ll n, vector<ll> &divs){
    for(int i = 2; i * 1ll * i<=n; i++){
        if(!(n % i)) {
            divs.push_back(i);
            if (i != n / i) {
					divs.push_back(n / i);
            }
        }
    }
}

void solve()
{
    int n; cin >> n;
    ll num;
    vector<ll> nums;
    while(n--){
        cin >> num;
        nums.push_back(num);
    }        
    sort(all(nums));
    n = nums.size();
    ll actualMultiple = nums[0] * nums[n-1];
    vector<ll> divs;
    getDivs(actualMultiple, divs);
    sort(all(divs));
    print(
        ((divs == nums)
        ? actualMultiple
        : -1)
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