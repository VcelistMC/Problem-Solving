#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ll long long
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
#define printGrid(vv) for(auto row: vv){for(auto cell: row){cout << cell << " ";}cout << endl;}
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
bool inBounds(pii &p, vvi &grid){ return inBounds(p, grid.size(), grid[0].size()); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


const int N = 1e5;
bool is_comp[N+1];
vector<int> primes;

void linearSieve(){
    memset(is_comp, false, N+1);
    is_comp[0]=is_comp[1]=1;
    for (ll i = 2; i < N; i++){
        if(!is_comp[i]) primes.push_back(i);
        
        for(int j = 0; j < primes.size() && i * primes[j] <= N; j++){
            is_comp[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int dp[1121][15] = {};
void solve()
{
    dp[0][0] = 1;

    for(int i = 0; i < primes.size(); i++){
        for(int j = 1120; j >= primes[i]; j--){
            for(int k = 14; k >= 1; k--){
                dp[j][k] += dp[j-primes[i]][k-1];
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
    int n, k;
    linearSieve();
    solve();
    while(cin >> n >> k, n, k) {print(dp[n][k]);}
    return 0;
}