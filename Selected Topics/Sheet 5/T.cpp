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
#define mp make_pair
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
bool inBounds(pii &p, vvi &grid){ return inBounds(p, grid.size(), grid[0].size()); }

inline int sq(int a){return a*a;}

int sqDistance(pii a, pii b){
    return (sq(a.first - b.first) + sq(a.second - b.second));
}

bool sortForP(const pii &a,
              const pii &b)
{
    if(a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

map<pii, pair<pii, pii>> getClosest(vector<pii> &stations){
    int stationCount = stations.size();
    map<pii, pair<pii, pii>> closest;
    for(int i = 0; i < stationCount; i++){
        closest[stations[i]] = mp(
            mp(-22, -22),
            mp(-22, -22)
        );
        int firstD = -1, secondD = -1;
        pii &firstN = closest[stations[i]].first, &secondN = closest[stations[i]].second;

        for(int j = 0; j < stationCount; j++){
            if(i == j) continue;
            int d = sqDistance(stations[i], stations[j]);
            if(firstD == -1 || d < firstD){
                secondN = firstN;
                secondD = firstD;

                firstN = stations[j];
                firstD = d;
            }
            else if(secondD == -1 || d < secondD){
                secondN = stations[j];
                secondD = d;
            }
        }
    }
    return closest;
}

pair<pii, pii> bfs(pii start, vvi &map){
    queue<pii> q;
    set<pii> v;
    q.push(start);
    v.insert(start);

    int dirs[8][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

    pii firstClosestStation = make_pair(-1, -1), secondClosestStation = make_pair(-1, -1);
    int firstClosestStationFound = 0;

    while(!q.empty()){
        int s = q.size();
        while(s--){
            pii curr = q.front();
            q.pop();

            if(map[curr.first][curr.second] && curr != start){
                if(!firstClosestStationFound){
                    firstClosestStation = curr;
                    firstClosestStationFound = true;
                }
                else{
                    secondClosestStation = curr;
                    return make_pair(firstClosestStation, secondClosestStation);
                }
            }

            for(auto dir: dirs){
                pii next(
                    curr.first + dir[0],
                    curr.second + dir[1]
                );

                if(inBounds(next, map) && v.find(next) == v.end()){
                    q.push(next);
                    v.insert(next);
                }
            }
        }
    }
    return make_pair(firstClosestStation, secondClosestStation);
}

int dfs(pii station, map<pii, pair<pii, pii>> &closest, set<pii> &visited){
    if(visited.find(station) != visited.end() || (station.first == -22 && station.second == -22)) return 0;

    visited.insert(station);

    return 1 + dfs(closest[station].first, closest, visited) + dfs(closest[station].second, closest, visited);
}

void solve(int n)
{
    // vvi map(41, vi(41, 0));
    vector<pii> stations(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        // x+=20, y+=20;
        // map[x][y] = 1;   
        stations[i] = make_pair(x, y);
    }
    sort(all(stations));
    auto closest = getClosest(stations);
    // for(auto station: closest){
    //     print("Stations closest to (" << station.first.first << ", " << station.first.second << ") are");
    //     print(station.second.first.first << " " << station.second.first.second);
    //     print(station.second.second.first << " " << station.second.second.second);
    // }
    
    // for(int i = 0; i <= 40; i++){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(int i = 0; i <= 40 ; i++){
    //     cout << i << " ";
    //     for(int cell: map[i]){
    //         cout << (cell? "X": "-") << " ";
    //     }
    //     cout << endl;
    // }
    // bool canReachAll = false;
    for(auto station: stations){
        set<pii> v;
        int reachable = dfs(station, closest, v);
        if(v.size() == n){
            print("All stations are reachable.");
            return;
        }
    } 
    print("There are stations that are unreachable.");
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T;
    while(cin >> T, T) {solve(T);}
    return 0;
}