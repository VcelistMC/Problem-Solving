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

bool isOk(pair<ll, ll> f1, pair<ll, ll> f2, int d){
    ll diff = f1.first - f2.first;
    if(diff < 0) diff *= -1;

    return diff < d;
}

void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<pair<ll,ll>> friends;
    while(n--){
        pair<ll, ll> frnd;
        cin >> frnd.first >> frnd.second;
        friends.push_back(frnd);
    }
    n = friends.size();
    sort(all(friends));
    ll maxF = 0;
    ll currF = 0;
    int i = 0, j = 0;

    while(i < n && j < n){
        pair<ll, ll> f1 = friends[i];
        pair<ll, ll> f2 = friends[j];
        if(isOk(f1, f2, d)){
            currF += f2.second;
            j++;
        }
        else {
            maxF = max(maxF, currF);
            currF -= f1.second;
            i++;
        }
    }
    print(max(maxF, currF));
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