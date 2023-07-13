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
#define exists(x, v) (v.find(x) != v.end())
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

const int NO_PATH = -2;

int bfs(int start, int end, int jump, vi &dp, int n){
    if(~dp[start]) return dp[start];

    int moves[2] = {jump, -jump};
    queue<int> q;
    q.push(start);
    unordered_set<int> v;
    v.insert(start);
    int dist = 0;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            int curr = q.front(); q.pop();
            if(~dp[curr]) {
                dp[start] = dp[curr] + dist;
                return dp[start];
            }
            if(curr == end){
                dp[start] = dist;
                return dist;
            }

            for(int move: moves){
                int next = curr + move;
                if(next >= 0 && next < n && !exists(next, v)){
                    v.insert(next);
                    q.push(next);
                }
            }
        }
        dist++;
    }
    dp[start] = NO_PATH;
    return NO_PATH;
}

void solve()
{
    int n; cin >> n;
    vi dist(n);
    inputVec(dist);
    vi dp(n+1, -1);
    vi ans(n, 0);
    for(int i = n-1; i >= 0; i--){
        int d = bfs(i, n-1, dist[i], dp, n);
        d = (d == NO_PATH? -1: d);
        ans[i] = d;

    }
    for(int i = 0; i < n; i++){
        print(ans[i]);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #else
    freopen("jumping.in", "r", stdin);
    #endif
    int T; cin >> T;
    while(T--) {solve();}
    return 0;
}