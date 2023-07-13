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


void solve()
{
    ll c, d;
    cin >> c >> d;
    if(c&d != c || c|d != d){
        print(-1);
        return;
    }
    bitset<32> a(c);
    bitset<32> b(d);
    ll min_a = c, min_b = d, min_diff = abs(c-d);
    for(int i = 0; i < 32; i++){
        // we need to find a way to test all possible combs of bit flips
        if(a.test(i) != b.test(i)){
            a.flip(i);
            b.flip(i);
            ll a_c = a.to_ullong();
            ll b_c = b.to_ullong();
            ll diff = abs(a_c - b_c);
            if(diff < min_diff){
                min_a = a_c;
                min_b = b_c;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T=1;// cin >> T;
    while(T--) {solve();}
    return 0;
}