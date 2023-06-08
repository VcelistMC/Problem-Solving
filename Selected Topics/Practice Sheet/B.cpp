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
#define DEBUG_TEST_CASES 1
typedef pair<unordered_set<string>, pii> psv;
typedef pair<pii, int> pd;
char grid[101][101];
int n, m, k;

string to_str(pii p){
    return to_string(p.first) + ", " + to_string(p.second);
}

bool search(int steps, pii curr, pii start, unordered_map<string, bool> &v){
    if(curr.first < 0 || curr.second < 0 || curr.first >= n || curr.second >= m) return false;
    if(steps >= k && curr == start) return true;
    if(v[to_str(curr)] || grid[curr.first][curr.second] == '*') return false;


    if(steps) v[to_str(curr)] = true;
    bool ans = false;
    for(auto dir: dirs4){
        pii next = make_pair(
            curr.first + dir[0],
            curr.second + dir[1]
        );

        ans |= search(steps+1, next, start, v);
    }
    v[to_str(curr)] = false;
    return ans;

}


void solve()
{
    cin >> n >> m;
    cin >> k;
    
    pii start;
    cin >> start.first >> start.second;
    start.first--;
    start.second--;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    unordered_map<string, bool> v;
    bool can = search(0, start, start, v);
    print((
        can? "YES" : "NO"
    ));

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