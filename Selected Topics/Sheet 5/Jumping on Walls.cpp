#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ll long long
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }

int inCanyon(pii p, vvi &grid){
    int s = p.second;
    int si = grid[0].size();
    if(s >= si) 
        return 1;
    else if(s < 0) 
        return 0;
    else 
        return grid[p.first][p.second];
}
bool dfs(vvi &walls, int x, int y, int w, int k, int n){
    if(y >= n) return true;

    if(!walls[x][y] || y < w) return false;

    walls[x][y] = 0;

    return dfs(walls, (x+1) % 2, y+k, w+1, k, n)
        || dfs(walls, x, y-1, w+1, k, n)
        || dfs(walls, x, y+1, w+1, k, n);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vvi walls(2, vi(n, 0));
    string wall; cin >> wall;
    for(int i = 0; i < n; i++){ walls[0][i] = (wall[i] == '-'); }
    cin >> wall;
    for(int i = 0; i < n; i++){ walls[1][i] = (wall[i] == '-'); }

    print((dfs(walls, 0, 0, 0, k, n)? "YES": "NO"));
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
    T=1;
    #else
    T=1;
    #endif
    while(T--) {solve();}
    return 0;
}