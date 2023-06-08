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
int dirs[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

typedef pair<int, int> pii;

bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }



bool empty(vector<queue<pii>> qs){
    bool empty = true;
    for(auto q: qs) empty &= q.empty();
    return empty;
}

void solve()
{
    pii p1, p2, p3;
    int n, m; cin >> m >> n;
    int grid_n = n+2;
    int grid_m = m+2;
    vector<vector<char>> grid(grid_m, vector<char>(grid_n, '.'));   
    cin.ignore();
    for(int i = 0; i < m; i++){
        string line; getline(cin, line);
        for(int j = 0; j < n; j++){
            switch (line[j])
            {
                case '#':
                    grid[i+1][j+1] = line[j];
                    break;
                case '1':
                    p1 = make_pair(i+1, j+1);
                    break;
                case '2':
                    p2 = make_pair(i+1, j+1);
                    break;
                case '3':
                    p3 = make_pair(i+1, j+1);
                    break;
            }
        }
    }

    map<pii, set<int>> allPossible;
    vector<queue<pii>> qs(3);
    vector<set<pii>> visited(3);
    int time = 0;
    qs[0].push(p1);
    qs[1].push(p2);
    qs[2].push(p3);
    visited[0].insert(p1);
    visited[1].insert(p2);
    visited[2].insert(p3);

    while(!empty(qs)){    
        for(int i = 0; i<3; i++){
            int s = qs[i].size();
            while(s--){
                pii curr = qs[i].front();
                qs[i].pop();
                allPossible[curr].insert(i+1);
                
                if(allPossible[curr].size() == 3){
                    print(time);
                    return;
                } 

                for(auto dir: dirs){
                    pii next = make_pair(
                        curr.first + dir[0],
                        curr.second + dir[1]
                    );
                    if(inBounds(next, grid_m, grid_n) 
                        && visited[i].find(next) == visited[i].end() 
                        && grid[next.first][next.second] == '.'
                    ){
                        qs[i].push(next);
                        visited[i].insert(next);
                    }
                }
            }
        }
        time++;
    }
    
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