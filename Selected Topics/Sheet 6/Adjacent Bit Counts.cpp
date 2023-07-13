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

int dp[101][101][2];

int solve(int pos, int count, int isSet){
    if(pos == 0){
        if(count == 0 && !isSet) return 1;
        else return 0;
    }
    if(~dp[pos][count][isSet]) return dp[pos][count][isSet]; 
    if(isSet){
        dp[pos][count][isSet] = solve(pos-1, count, 0) + solve(pos-1, count-1, 1);
    }else{
        dp[pos][count][isSet] = solve(pos-1, count, 0) + solve(pos-1, count, 1);
    }

    return dp[pos][count][isSet];
}

int dp2[101][2][101];
int solve2(int pos, int prevBit, int currCount, int n, int k){
    if(pos == n){
        return currCount == k;
    }
    int &ret = dp2[pos][prevBit][currCount];
    if(~ret) return ret;

    ret = 0;
    if(prevBit){
        ret = solve2(pos+1, 0, currCount, n, k) + solve2(pos+1, 1, currCount+1, n, k);
    }else{
        ret = solve2(pos+1, 0, currCount, n, k) + solve2(pos+1, 1, currCount, n, k);
    }

    return ret;
}

void solve()
{
    memset(dp2, -1, sizeof dp2);
    int d, n, k;
    cin >> d >> n >> k;
    print(
        d << " " << solve2(1, 0, 0, n, k) + solve2(1, 1, 0, n, k)
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
    int T; cin >> T;
    while(T--) {solve();}
    return 0;
}