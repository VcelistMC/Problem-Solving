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
#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, vvi &grid){ return inBounds(p.first, p.second, grid); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
#define DEBUG_TEST_CASES 1
const int MOD = 1e8;

ll dp[11][11][101][101];

ll count(int currF, int currH, int totalF, int totalH, int f, int h, int k1, int k2){
    if(currF > k1) return 0;
    if(currH > k2) return 0;
    if(totalF+totalH == (f + h)) return 1;

    ll &ans = dp[currF][currH][totalF][totalH];
    if(~ans) return ans;

    ans = 0;
    ll a1 = 0, a2 = 0;
    if(totalF < f){
        a1 = count(currF+1, 0,  totalF+1, totalH, f, h, k1, k2);
    }
    if(totalH < h){
        a2 = count(0, currH+1,  totalF, totalH+1, f, h, k1, k2);
    }

    return ans = (a1+a2) % MOD;
}

void solve()
{
    int f, h, k1, k2;
    cin >> f >> h >> k1 >> k2;
    memset(dp, -1, sizeof dp);
    print(count(0, 0, 0, 0, f, h, k1, k2));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    T=DEBUG_TEST_CASES;
    #else
    T=1;
    #endif
    while(T--) {solve();}
    return 0;
}