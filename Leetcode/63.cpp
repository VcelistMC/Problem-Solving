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

int uniquePathsWithObstacles(vector<vector<int>>& dp) {
    int n = dp.size();
    int m = dp[0].size();
    if(n == 1 && m == 1) {
        return dp[0][0] == 0;
    };
    if(dp[0][0] == 1) return 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dp[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            else {
                int fromTop = (i-1 >= 0? dp[i-1][j]: 0);
                int fromLeft = (j-1 >= 0? dp[i][j-1]: 0);

                dp[i][j] = fromTop + fromLeft;
            }
        }
    }
    return dp[n-1][m-1];
}

void solve()
{
    vvi grid = {
        {0,0},{1,1},{0,0}
    };

    print(uniquePathsWithObstacles(grid));
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