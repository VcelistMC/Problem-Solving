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
bool inBounds(pii &p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
bool inBounds(pii &p, vvi &grid){ return inBounds(p, grid.size(), grid[0].size()); }
#define max(a, b, c) max(a, max(b, c))

map<pii, vi> dist;
vvi grid(202, vi(202, 1));

void clear(){
	dist.clear();
	for(auto &row: grid){
		for(auto &cell: row){
			cell = 1;
		}
	}
}

void bfs(vvi &grid, pii &start, int person, int m, int n){
	queue<pii> q;
	set<pii> v;
	ll distance = 0;
	q.push(start);
	v.insert(start);
	while(!q.empty()){
		int s = q.size();
		while(s--){
			pii curr = q.front();
			
			if(dist.find(curr) == dist.end()){
				dist[curr] = vi(3, 0);
			}
			dist[curr][person] = distance;

			q.pop();

			for(auto dir: dirs4){
				pii next = make_pair(
					curr.first + dir[0],
					curr.second + dir[1]
				);

				if(inBounds(next, m, n) 
					&& grid[next.first][next.second]
					&& v.find(next) == v.end()	
				){
					q.push(next);
					v.insert(next);
				}
			}
		}
		distance++;
	}
}

void solve()
{
	clear();
	pii p1, p2, p3;	
    int n, m; cin >> m >> n;
    int grid_n = n+2;
    int grid_m = m+2;
    cin.ignore();
    string line;
	for(int i = 0; i < m; i++){
        getline(cin, line);
        for(int j = 0; j < n; j++){
            switch (line[j])
            {
                case '#':
                    grid[i+1][j+1] = 0;
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
	int minTime = INT32_MAX;

	bfs(grid, p1, 0, grid_m, grid_n);
	bfs(grid, p2, 1, grid_m, grid_n);
	bfs(grid, p3, 2, grid_m, grid_n);

	for(auto cell: dist){
		minTime = min (
			minTime,
			max(cell.second[0], cell.second[1], cell.second[2])
		);
	}
	
	print(minTime);
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