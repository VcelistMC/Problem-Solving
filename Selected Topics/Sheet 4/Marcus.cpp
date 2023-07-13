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
typedef pair<int, int> pii;
typedef pair<int, char> pic;

const string dirsStr[3] = {"forth", "left", "right"};
const int dirs[3][2] = { {-1, 0}, {0, -1}, {0, 1} };
vector<string> path;
vector<string> validPath;

bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }


void dfs(vector<vi> &grid, pii curr, pii end, bool &found, int n, int m){
    if(curr == end || found){
        found == true;
        validPath = vector<string>(path);
        return;
    }

    for(int i = 0; i < 3; i++){
        pii next = make_pair(curr.first + dirs[i][0], curr.second + dirs[i][1]);
        if(inBounds(next.first, next.second, n, m) && grid[next.first][next.second]){
            grid[next.first][next.second] = 0;
            path.push_back(dirsStr[i]);
            dfs(grid, next, end, found, n, m);
            path.pop_back();
        }
    }
}

void solve()
{
    path.clear();
    int n, m;
    string line;
    cin >> n >> m;
    pii start, end;
    set<char> allowedChars = {'I', 'E', 'H', 'O', 'V', 'A'};
    vector<vi> grid(n, vector<int>(m, 1));
    for(int i = 0; i < n; i++){
        vector<char> row;
        cin >> line;
        for(int j = 0; j < m; j++){
            if(line[j] == '@') start = make_pair(i, j);
            else if (line[j] == '#') end = make_pair(i, j);
            else grid[i][j] = (allowedChars.find(line[j]) != allowedChars.end());
        }
    }
    bool found = false;
    dfs(grid, start, end, found, n, m);
    for(int i = 0; i < validPath.size(); i++){
        cout << validPath[i];
        if(i != validPath.size()-1) cout << " ";
    }
    cout << endl;
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