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
#define um unordered_map
#define us unordered_set
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
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

bool bfs(int soldierInd, vector<pii> &soldiers, um<int, vi> &cities, um<int, us<int>> &protectedBy){
    queue<int> q;
    us<int> v;
    pii soldier = soldiers[soldierInd];
    int startCity = soldier.first;
    int power = soldier.second;

    q.push(startCity);
    v.insert(startCity);

    while(!q.empty() && power >= 0){
        int s = q.size();
        while(s--){
            int curr = q.front(); q.pop();
            auto &soldiersProtecting = protectedBy[curr];
            soldiersProtecting.insert(soldierInd);

            if(soldiersProtecting.size() > 1){return false;}

            for(int adjCity: cities[curr]){
                if(v.find(adjCity) != v.end()) continue;

                q.push(adjCity);
                v.insert(adjCity);
            }
        }
        power--;
    }
    return true;
}

void solve()
{
    int n, r, m;
    scanf("%d %d %d", &n, &r, &m);
    um<int, vi> cities;
    vector<pii> soldiers(m);
    um<int, us<int>> protectedCities;
    int c1, c2;
    for(int i = 0; i < r; i++){
        scanf("%d %d", &c1, &c2);
        cities[c1].push_back(c2);
        cities[c2].push_back(c1);
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d", &soldiers[i].first, &soldiers[i].second);
    }

    for(int i = 0; i < m; i++){
        if(!bfs(i, soldiers, cities, protectedCities)){
            printf("No\n");
            return;
        }
    }
    protectedCities.size() == n
        ? printf("Yes\n")
        : printf("No\n");
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T; scanf("%d", &T);
    while(T--) {solve();}
    return 0;
}