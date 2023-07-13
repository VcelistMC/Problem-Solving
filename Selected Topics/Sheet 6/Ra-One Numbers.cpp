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
#define len size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, vvi &grid){ return inBounds(p.first, p.second, grid.size(), grid[0].size()); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
int ctoi(char c){ return c - '0'; }


int dp[12][95][95][2];

int solve(int pos, int evenSum, int oddSum, int tight, vi &nums, int isOddLen){
    if(pos == nums.len){
        return (evenSum - oddSum == 1);
    }

    int &ret = dp[pos][evenSum][oddSum][tight];
    if(ret != -1) return ret;

    int ub = tight? nums[pos]: 9;
    ret = 0;
    for(int i = 0; i <= ub; i++){
        if((pos+isOddLen)&1)
            ret += solve(pos+1, evenSum, oddSum + i, tight&(ub==i), nums, isOddLen);
        else
            ret += solve(pos+1, evenSum + i, oddSum, tight&(ub==i), nums, isOddLen);
    }
    return ret;
}

int solve(string &s){
    vi nums(s.len);
    for(int i = 0; i < s.len; i++){
        nums[i] = ctoi(s[i]);
    }
    memset(dp, -1, sizeof dp);
    return solve(0, 0, 0, 1, nums, nums.len & 1);
}

void solve()
{
    ll n1, n2;
    cin >> n1 >> n2;
    n1--;
    string s1 = to_string(n1), s2 = to_string(n2);
    print(
        solve(s2) - solve(s1)
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