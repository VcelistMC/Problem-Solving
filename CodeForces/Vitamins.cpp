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
typedef vector<char> vc;
typedef vector<vc> vvc;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, vvi &grid){ return inBounds(p.first, p.second, grid); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
#define DEBUG_TEST_CASES 6

ll get(string a, map<string, ll> &vits){
    return vits.find(a) == vits.end()
        ? LLONG_MAX
        : vits[a];
}

ll get(string a, string b, map<string, ll> &vits){
    return vits.find(a) == vits.end() || vits.find(b) == vits.end()
        ? LLONG_MAX
        : vits[a] + vits[b];
}

ll get(string a, string b, string c, map<string, ll> &vits){
    return vits.find(a) == vits.end() || vits.find(b) == vits.end() || vits.find(c) == vits.end()
        ? LLONG_MAX
        : vits[a] + vits[b] + vits[c];
}

void solve()
{
    int n; cin >> n;
    map<string, ll> vits;
    ll p; string v;
    for(int i = 0; i < n; i++){
        cin >> p >> v;
        sort(all(v));
        if(vits.find(v) == vits.end()) vits[v] = LLONG_MAX;
        vits[v] = min(vits[v], p);
    }

    ll res = LLONG_MAX;
    
    res = min({
        res,
        get("A", "B", "C", vits),

        get("ABC", vits),
        
        get("AB", "C", vits),
        get("BC", "A", vits),
        get("AC", "B", vits),
        
        get("AB", "BC", vits),
        get("AC", "BC", vits),
        get("AC", "AB", vits)
    });
    
    res == LLONG_MAX
        ? print(-1)
        : print(res);
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