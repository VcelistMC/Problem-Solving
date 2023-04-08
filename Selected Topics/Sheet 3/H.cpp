#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define llui long long unsigned int
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl


bool isEnough(ll numCookie, vector<ll> &has, vector<ll> &need, ll magic){
    ll magick = 0;
    ll n = has.size();
    for(ui i = 0; i < n; i++){
        if(numCookie * need[i] > has[i]){
            magick += ((numCookie * need[i]) - has[i]);
            if(magick > magic) return false;
        }
    }
    return true;
}


void solve()
{
    ui n, k;
    cin >> n >> k;
    vector<ll> need(n), has(n);
    for(ui i = 0; i < n; i++){
        cin >> need[i];
    }
    for(ui i = 0; i < n; i++){
        cin >> has[i];
    }
    ll loCookie = 0, hiCookie = UINT32_MAX, ans=0;
    while(loCookie <= hiCookie){
        ll midCookie = (hiCookie+loCookie)/2;
        if(isEnough(midCookie, has, need, k)) {
            ans = midCookie;
            loCookie = midCookie+1;
        }
        else hiCookie = midCookie-1;

    }
    cout << ans << endl;
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