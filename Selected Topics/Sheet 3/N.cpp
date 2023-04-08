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

bool check(int ll x, ll y){
    ll x1 = abs(x-y);
    ll y1 = abs(x+y);
    x = abs(x);
    y = abs(y);

    
}

void solve()
{
    int n;
    vector<ll> guesses(n);
    for(int i = 0; i < n; i++) cin >> guesses[i];

    sort(all(guesses));
    
    int legendTrue = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j) continue;

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
    int T; cin >> T;
    while(T--) {solve();}
    return 0;
}