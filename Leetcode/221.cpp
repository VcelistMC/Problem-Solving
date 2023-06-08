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


int min(int a, int b, int c){
    return min(a, min(b, c));
}

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = (matrix[i][j] == '1');
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            if(matrix[i][j] == '1')
                dp[i][j] = min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]) + 1;
        }
    }

    int ans = dp[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    return ans*ans;
}

void solve()
{
    vector<vector<char>> mat = {
        {'1','1','1','1','0'},
        {'1','1','1','1','0'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'0','0','1','1','1'}
    };
    print(maximalSquare(mat));
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