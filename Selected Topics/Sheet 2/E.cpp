#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print1(x) cout << x << endl
#define print2(a, b, del) cout << a << del << b << endl;

lli gcd(lli a, lli b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve()
{
    int n;
    while(cin >> n, ~n){
        lli u1=1, u2=1;
        lli ua, ub;
        while(n-- > 1){
            cin >> ua >> ub;
            u1 *= ua;
            u2 *= ub;
        }
        lli div = gcd(u1, u2);
        print2(u1/div, u2/div, " ");
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