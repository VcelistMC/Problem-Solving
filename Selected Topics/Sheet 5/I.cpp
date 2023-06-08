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
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
bool inBounds(pii &p, vvi &grid){ return inBounds(p, grid.size(), grid[0].size()); }
#define DEBUG_TEST_CASES 1

void topsort(vvi &graph, set<int> &v, int curr, vi &topo){
    v.insert(curr);
    for(int i = 0; i < graph[curr].size(); i++){
        if(v.find(graph[curr][i]) == v.end()){
            topsort(graph, v, graph[curr][i], topo);
        }
    }
    topo.push_back(curr);
}

void solve()
{
    int n, k, count, supTo;
    cin >> n >> k;
    vvi adjList(n+1);
    for(int i = 1; i <= k; i++){
        cin >> count;
        while(count--){
            cin >> supTo;
            adjList[i].push_back(supTo);
        }
    }
    vi order;
    set<int> v;
    for(int i = 1; i <= n; i++){
        if(v.find(i) == v.end()){
            topsort(adjList, v, i, order);
        }
    }
    vi boss(n+1);
    int b = 0;
    for(int i = n-1; i >= 0; i--){
        boss[order[i]] = b;
        b = order[i];
    }
    for(int i = 1; i <= n; i++){print(boss[i]);}
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