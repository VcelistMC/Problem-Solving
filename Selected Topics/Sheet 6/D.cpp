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


ll dp[205][11][205];
ll getCount(int currSum, int taken, int currInd, int k, int n, vi &nums){
    if(taken == n){ return (currSum == 0? 1LL: 0LL); }  

    if(currInd == nums.size()){
        return 0LL;
    };

    ll& ans = dp[currInd][taken][currSum];
    if(~ans) return ans;

    ll take = getCount((currSum + nums[currInd]) % k, taken+1, currInd+1, k, n, nums);
    ll leave = getCount(currSum, taken, currInd+1, k, n, nums);

    return ans = (take + leave);
}      

void solve(int n, int q)
{
    vi nums(n);
    inputVec(nums);
    memset(dp, -1, sizeof dp);
    int m, d;
    int i = 1;
    while(q--){
        cin >> d >> m;
        memset(dp, -1, sizeof dp);
        cout << "QUERY " << i << ": ";
        i++;
        print(getCount(0, 0, 0, d, m, nums));
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
    int N, Q, i = 1;
    while(cin >> N >> Q, N, Q) {
        cout << "SET " << i << ":" << endl;
        i++;
        solve(N, Q);
    }
    return 0;
}