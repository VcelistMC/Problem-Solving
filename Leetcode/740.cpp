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
#define DEBUG_TEST_CASES 2

int dp[20001];
int deleteAndEarn(vector<int> &nums, unordered_map<int, int> &freq){
    dp[0] = 0;
    dp[1] = nums[0] * freq[nums[0]];

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] == 1){
            dp[i+1] = max(dp[i], dp[i-1] + nums[i] * freq[nums[i]]);
        }else{
            dp[i+1] = dp[i] + nums[i] * freq[nums[i]];
        }
    }

    return dp[nums.size()];
}

int deleteAndEarn(vector<int>& nums) 
{
    unordered_map<int, int> freq;
    vector<int> newArr;
    for(int num: nums){
        if(freq.find(num) == freq.end()){
            freq[num] = 0;
            newArr.push_back(num);
        }
        freq[num]++;
    }
    sort(newArr.begin(), newArr.end());
    memset(dp, -1, sizeof dp);
    return deleteAndEarn(newArr, freq);
}

void solve()
{
    int n; cin >> n;
    vi nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    print(deleteAndEarn(nums));
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