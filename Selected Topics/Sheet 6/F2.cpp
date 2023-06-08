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
const int MAX = 900005;

vi oxy, nit, weights;
int dp[22][80][1001];
int solve(int currOxy, int currNit, int currWeight, int currInd){
    if(currOxy == 0 && currNit == 0) return currWeight;

    if(currInd == oxy.size()) return MAX;

    int &ret = dp[currOxy][currNit][currInd];
    if(~ret) return ret;

    int newOxy = max(currOxy - oxy[currInd], 0);
    int newNit = max(currNit - nit[currInd], 0);

    int take = solve(newOxy, newNit, currWeight + weights[currInd], currInd+1);
    int leave = solve(currOxy, currNit, currWeight, currInd+1);

    return ret = min(take, leave);
}

void solve()
{
    int neededOxy, neededNit;
    cin >> neededOxy >> neededNit;
    int n; cin >> n;
    int ox, ni, weight;
    oxy.clear();
    nit.clear();
    weights.clear();
    for(int i = 0; i < n; i++){
        cin >> ox >> ni >> weight;
        oxy.push_back(ox);
        nit.push_back(ni);
        weights.push_back(weight);
    }
    memset(dp, -1, sizeof dp);
    print(solve(neededOxy, neededNit, 0, 0));
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