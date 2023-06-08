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

int dfs(int i, int j, vvi &grid, int n){
    pii start = make_pair(i, j);
    int num = grid[i][j];
    stack<pii> s;
    s.push(start);
    grid[i][j] = 0;
    int d = 0;
    while(!s.empty()){
        pii curr = s.top();
        s.pop();
        d++;

        for(auto dir: dirs4){
            pii next = make_pair(
                curr.first + dir[0],
                curr.second + dir[1]
            );
            
            if(inBounds(next, n, n) && grid[next.first][next.second] == num){
                s.push(next);
                grid[next.first][next.second] = 0;
            }
        }
    }
    return d;
}

void solve(int n)
{
    vvi grid(n, vi(n, n));
    int x, y;
    string s;
    cin.ignore();
    for(int i = 1; i < n; i++){
        // for(int j = 0; j < n; j++){
            getline(cin, s);
            stringstream ss(s);
            while(ss >> x >> y){
                grid[x-1][y-1] = i;
            }
        // }
    }
    set<int> visited;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cell = grid[i][j];
            if(visited.find(cell) != visited.end()) {
                print("wrong");
                return;
            }
            if(cell){
                visited.insert(cell);
                int l = dfs(i, j, grid, n);
                if(l != n){
                    print("wrong");
                    return;
                }
            }
        }
    }
    print("good");
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int N;
    while(cin >> N, N) {solve(N);}
    return 0;
}