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
bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
bool inBounds(pii p, vvi &grid){ return inBounds(p, grid.size(), grid[0].size()); }

int dfs(vvi &grid, int startX, int startY){
    int size = 0;
    stack<int> sx;
    stack<int> sy;
    sx.push(startX);
    sy.push(startY);
    grid[startX][startY] = 0;
    while(!sy.empty()){
        int currX = sx.top(), currY = sy.top();
        sx.pop(); sy.pop();
        size++;
        for(auto dir: dirs4){
            int nextX = currX + dir[0];
            int nextY = currY + dir[1];
            
            if(inBounds(nextX, nextY, grid) && grid[nextX][nextY]){
                sx.push(nextX);
                sy.push(nextY);
                grid[nextX][nextY] = 0;
            }
        }
    }
    return size;
}

void solve()
{
    int waterRow, waterCol;
    cin >> waterRow >> waterCol;
    waterRow--;
    waterCol--;
    cin.ignore();
    vvi grid;
    string line;
    while(getline(cin, line)){
        if(line == "") break;
        vi row;
        for(char c: line){
            row.push_back(c == '0');
        }
        grid.push_back(row);
    }
    print(dfs(grid, waterRow, waterCol));   
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
    cin.ignore();
    cin.ignore();
    while(T--) {
        solve();
        if(T != 0) cout << endl;
    }
    return 0;
}