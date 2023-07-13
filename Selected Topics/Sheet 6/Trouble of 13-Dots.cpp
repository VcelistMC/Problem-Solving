#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
#define printGrid(vv) for(auto row: vv){for(auto cell: row){cout << cell << " ";}cout << endl;}
#define exists(x, v) (v.find(x) != v.end())
#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, vvi &grid){ return inBounds(p.first, p.second, grid); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

ll solve(int currInd, ll total, vpll &list, int money, vvll &dp){
    if(currInd == list.size()){
        return (total <= 2000 && total > money - 200)
            ? -1e9
            : 0;
    }

    ll &ret = dp[total][currInd];
    if(~ret) return ret;

    ret = solve(currInd+1, total, list, money, dp);

    if(total + list[currInd].first <= money){
        ret = max(ret, solve(currInd+1, total + list[currInd].first, list, money, dp) + list[currInd].second);
    }


    return ret; 
}

void solve(int money, int n)
{
    vpll l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i].first >> l[i].second;
    }
    vvll dp(money+201, vll(n+1, -1));
    print(
        solve(0, 0, l, money+200, dp)
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
    int money, list;
    while(cin >> money >> list) {solve(money, list);}
    return 0;
}