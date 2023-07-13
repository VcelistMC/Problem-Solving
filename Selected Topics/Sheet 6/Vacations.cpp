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
#define max3(a, b, c) {}
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
#define DEBUG_TEST_CASES 3

int max(int a, int b, int c) {return max(max(a, b), c);}
int min(int a, int b, int c) {return min(min(a, b), c);}

void solve()
{
    int n; cin >> n;
    vi days(n);
    for(int i = 0; i < n; i++) cin >> days[i];

    vvi dp(n+1, vi(3, 0));
    for(int i = 1; i <= n; i++){
        bool isContest = (days[i-1] == 1 || days[i-1] == 3);
        bool isGym = (days[i-1] == 2 || days[i-1] == 3);


        dp[i][0] = min(dp[i-1][0], dp[i-1][1], dp[i-1][2]) + 1;
        
        if(isContest){
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }else{
            dp[i][1] = dp[i-1][1] + 1;
        }

        if(isGym){
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }else{
            dp[i][2] = dp[i-1][2] + 1;
        }
    }
    print(min(dp[n][0], dp[n][1], dp[n][2]));
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