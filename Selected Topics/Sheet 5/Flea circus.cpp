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

void solve(int flea1, int flea2, vvi &adj, int &m1, int &m2){
    queue<vi> q;
    q.push(vi{flea1});
    unordered_set<int> v;
    v.insert(flea1);

    while(!q.empty()){
        vi curr = q.front(); q.pop();
        int last = curr.back();

        if(last == flea2){
            int s = curr.size();
            if(s & 1){
                m1 = curr[s/2];
                m2 = -1;
            }else{
                m1 = curr[(s-1)/2];
                m2 = curr[s/2];
            }
            return;
        }

        if(adj[last].size() == 0) continue;
        for(int neig: adj[last]){
            if(v.find(neig) != v.end()) continue;

            v.insert(neig);
            vi newP = vi(curr);
            newP.push_back(neig);
            q.push(newP);
        }
    }
}

void solve(int n)
{
    vvi adj(n+1);
    int p, r;
    for(int i = 0; i < n-1; i++){
        cin >> p >> r;
        adj[p].push_back(r);
        adj[r].push_back(p);
    }
    int q, flea1, flea2, m1, m2; 
    cin >> q;
    
    while(q--){
        cin >> flea1 >> flea2;
        solve(flea1, flea2, adj, m1, m2);
        if(m2 == -1){
            cout << "The fleas meet at " << m1 << ".\n";
        }else{
            cout << "The fleas jump forever between " << min(m1, m2) << " and " << max(m1, m2) << ".\n"; 
        }
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
    int n;
    while(cin >> n, n) {solve(n);}
    return 0;
}