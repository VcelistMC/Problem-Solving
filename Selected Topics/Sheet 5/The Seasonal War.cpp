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

void dfsr(vector<vi> &grid, int x, int y, int n){
    grid[x][y]=0;
    for(auto dir: dirs8){
        int nextX = x + dir[0];
        int nextY = y + dir[1];

        if(inBounds(nextX, nextY, n, n) && grid[nextX][nextY]){
            dfsr(grid, nextX, nextY, n);
        }
    }
}


void dfs(vector<vi> &grid, int x, int y, int n){
    stack<int> sx;
    stack<int> sy;
    sx.push(x);
    sy.push(y);
    grid[x][y] = 0;
    while(!sx.empty()){
        int currX = sx.top(), currY = sy.top();
        sx.pop(), sy.pop();
        
        for(auto dir: dirs8){
            int nextX = currX + dir[0];
            int nextY = currY + dir[1];

            if(inBounds(nextX, nextY, n, n) && grid[nextX][nextY]){
                sx.push(nextX);
                sy.push(nextY);
                grid[nextX][nextY] = 0;
            }
        }
    }
}

int solve(int n)
{
    vector<vi> grid(n, vi(n, 0));
    string line;
    for(int i = 0; i < n; i++){
        getline(cin, line);
        for(int j = 0; j < n; j++){
            grid[i][j] = (line[j] == '1');
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]){
                count++;
                dfsr(grid, i, j, n);
            }
        }
    }
    return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T=1, n;
    while(cin >> n) {
        cin.ignore();
        printf("Image number %d contains %d war eagles.\n", T, solve(n));
        T++;
    }
    return 0;
}