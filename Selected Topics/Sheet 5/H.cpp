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

int bfs(pii start, pii end, vvi &grid){
    queue<pii> q;
    set<pii> v;
    q.push(start);
    v.insert(start);
    int dist = 0;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            pii curr = q.front();
            q.pop();

            if(curr == end){
                return dist;
            }

            for(auto dir: dirs4){
                pii next = make_pair(
                    curr.first + dir[0],
                    curr.second + dir[1]
                );
                if(inBounds(next, grid)
                    && v.find(next) == v.end()
                    && grid[next.first][next.second]
                ){
                    q.push(next);
                    v.insert(next);
                }
            }
        }
        dist++;
    }

    return INT_MAX;
}

int calcDistance(pii myLocation, pii start, map<pii, pii> &breeders, vvi &grid){
    int myDistance = 0;
    int currDistance = 0;
    int breedersFound = 0;
    queue<pii> q;
    set<pii> v;
    q.push(start);
    v.insert(start);
    while(!q.empty()){
        int s = q.size();
        while(s--){
            pii curr = q.front();
            q.pop();
            if(curr == myLocation){
                myDistance = currDistance;
                breedersFound++;
            }

            if(breeders.find(curr) != breeders.end()){
                breeders[curr].second = currDistance;
                breedersFound++;
            }

            if(breedersFound == breeders.size() +1){
                return myDistance;
            }

            for(auto dir: dirs4){
                pii next = make_pair(
                    curr.first + dir[0],
                    curr.second + dir[1]
                );

                if(inBounds(next, grid)
                    && v.find(next) == v.end()
                    && grid[next.first][next.second]
                ){
                    q.push(next);
                    v.insert(next);
                }
            }
        }
        currDistance++;
    }
    return myDistance;
}

void solve()
{
    int r, c;
    cin >> r >> c;
    vvi grid(r, vi(c, 1));
    pii start, end;
    map<pii, pii> breedersAt;
    string row;
    cin.ignore();
    for(int i = 0; i < r; i++){
        getline(cin, row);
        for(int j = 0; j < c; j++){
            switch (row[j])
            {
                case 'E':
                    end = make_pair(i, j);
                    break;
                case 'S':
                    start = make_pair(i, j);
                    break;
                case 'T':
                    grid[i][j] = 0;
                    break;
                
                default: {
                    int num = row[j] - '0';
                    if(num > 0){
                        breedersAt[make_pair(i, j)] = make_pair(num, -1);
                    }

                }
            }
        }
    }
    int myDistance = calcDistance(start, end, breedersAt, grid);
    int battles = 0;

    for(auto breeders: breedersAt){
        if(breeders.second.second == -1) continue;
        if(breeders.second.second <= myDistance) battles += breeders.second.first;
    }
    print(battles);
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
    T=1;
    #else
    T=1;
    #endif
    while(T--) {solve();}
    return 0;
}