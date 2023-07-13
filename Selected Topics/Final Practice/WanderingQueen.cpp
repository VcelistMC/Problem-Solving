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

string to_string(pii a){ return to_string(a.first) + " " + to_string(a.second); }

bool open(pii start, pii end, vvi &grid, int dir){
    int xs = start.first, ys = start.second;
    int xf = end.first, yf = end.second;

    if(!grid[xs][ys] || !grid[xf][yf]) return false;

    while((xs != xf) || (ys != yf)){
        xs += dirs8[dir][0];
        ys += dirs8[dir][1];
        if(!grid[xs][ys]) return false;
    }
    return true;
}


int bfs(pii start, pii end, vvi &grid, int len){
    int moves[8][2] = {
        {-len, 0},
        {len, 0},
        {0, -len},
        {0, len},
        {-len, -len},
        {-len, len},
        {len, -len},
        {len, len}
    };
    queue<pii> q;
    q.push(start);
    unordered_set<string> v;
    v.insert(to_string(start));
    int steps = 0;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            pii curr = q.front(); q.pop();

            if(curr == end) return steps;
            int i = 0;
            for(auto move: moves){
                pii next = make_pair(
                    curr.first + move[0],
                    curr.second + move[1]
                );

                bool inBound = inBounds(next, grid);
                bool exist = inBound && exists(to_string(next), v);
                bool isOpen = inBound? open(curr, next, grid, i): false;

                if(
                    inBound
                    && !exist
                    && isOpen)
                {
                    v.insert(to_string(next));
                    q.push(next);
                }
                i++;
            }
        }
        steps++;
    }
    return INT_MAX;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    pii start, end;
    vvi grid(n, vi(m, 1));
    char x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            switch (x)
            {
                case 'X':
                    grid[i][j] = 0;
                    break;
                case 'S':
                    start = make_pair(i, j);
                    break;
                case 'F':
                    end = make_pair(i, j);
                    break;
            }
        }
    }
    int ans = INT_MAX;
    for(int moveLen = 1; moveLen <= 8; moveLen++){
        ans = min(
            ans,
            bfs(start, end, grid, moveLen)
        );
    }
    ans == INT_MAX
        ? print(-1)
        : print(ans);
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