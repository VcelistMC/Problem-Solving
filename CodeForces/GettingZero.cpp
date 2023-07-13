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
#define exists(x, v) (v.find(x) != v.end())
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
const int MOD = 32768;

unordered_map<int, int> dp;
int bfs(int num){
    if(exists(num, dp)) return dp[num];
    queue<int> q;
    q.push(num);
    unordered_set<int> v;
    v.insert(num);
    int steps = 0;

    while(!q.empty()){
        int s = q.size();
        while(s--){
            int curr = q.front(); q.pop();

            if(exists(curr, dp)){
                dp[num] = steps + dp[curr] - 1;
                return steps + dp[curr] - 1;
            }

            if(curr % MOD == 0){
                dp[num] = steps;
                return steps;
            };

            int next1 = (curr+1), next2 = curr*2;
            if(!exists(next1, v)){
                v.insert(next1);
                q.push(next1);
            }

            if(!exists(next2, v)){
                v.insert(next2);
                q.push(next2);
            }
        }
        steps++;
    }
}

void solve()
{
    int n, num; cin >> n;
    while(n--){
        cin >> num;
        cout << bfs(num);
        if(n) cout << "\n";
    }
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