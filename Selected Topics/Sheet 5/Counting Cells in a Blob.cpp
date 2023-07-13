#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
int dirs4[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int dirs8[8][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
    {-1, -1},
    {-1, 1},
    {1, -1},
    {1, 1}
};


bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }

int dfs(vector<vi> &grid, int x, int y, int n, int m){
    stack<int> xs, ys;
    xs.push(x);
    ys.push(y);
    int size = 0;
    grid[x][y] = 0;
    while(!xs.empty() && !ys.empty()){
        int currX = xs.top(), currY = ys.top();
        xs.pop(), ys.pop();
        size++;

        for(auto dir: dirs8){
            int nextX = currX + dir[0];
            int nextY = currY + dir[1];
            if(inBounds(nextX, nextY, n, m) && grid[nextX][nextY] == 1){
                grid[nextX][nextY] = 0;
                xs.push(nextX);
                ys.push(nextY);
            }
        }
    }
    return size;
}

void solve()
{
    vector<vi> grid;
    string line;
    while(getline(cin, line)){
        if(line == "") break;
        vi row;
        for(char cell: line){
            if(cell == '1') row.push_back(1);
            else row.push_back(0);
        }
        grid.push_back(row);
    }
    int maxSize = 0;
    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                maxSize = max(maxSize, dfs(grid, i, j, n, m));
            }
        }
    }
    print(maxSize);
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