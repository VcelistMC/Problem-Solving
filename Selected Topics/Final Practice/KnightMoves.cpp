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
bool inBounds(pii &p, int n, int m){ return inBounds(p.first, p.second, n, m); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

int moves[8][2] = {
    {-2, -1},
    {-2, +1},
    {-1, -2},
    {-1, +2},
    {+1, -2},
    {+1, +2},
    {+2, -1},
    {+2, +1}
};


int bfs(pii a, pii b){
    queue<pii> q;
    set<pii> v;
    q.push(a);
    v.insert(a);
    int steps = 0;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            pii curr = q.front(); q.pop();
            if(curr == b) return steps;

            for(auto move: moves){
                pii next = make_pair(
                    curr.first + move[0],
                    curr.second + move[1]
                );
                if(inBounds(next, 8, 8) && !exists(next, v)){
                    v.insert(next);
                    q.push(next);
                }
            }
        }
        steps++;
    }
}

void solve(string a, string b)
{
    int y1 = a[0] - 'a', x1 = (a[1] - '0')-1;
    int y2 = b[0] - 'a', x2 = (b[1] - '0')-1;
    pii s1 = make_pair(x1, y1), s2 = make_pair(x2, y2);

    print("To get from " << a << " to " << b << " takes " << bfs(s1, s2) << " knight moves.");
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    string a, b;
    while(cin >> a >> b) {solve(a, b);}
    return 0;
}