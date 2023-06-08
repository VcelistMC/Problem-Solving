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
bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
typedef map<char, vector<char>> mcc;

vector<char> bfs(char a, char b, mcc &m){
    queue<vector<char>> q;
    q.push(vector<char>{a});
    set<char> v;
    v.insert(a);
    while(!q.empty()){
        vector<char> curr = q.front(); q.pop();
        char node = curr.back();
        if(node == b){
            return curr;
        }

        if(m[node].size() == 0) continue;
        for(char adj: m[node]){
            if(v.find(adj) == v.end()){
                v.insert(adj);
                vector<char> newpath = vector<char>(curr);
                newpath.push_back(adj);
                q.push(newpath);
            }
        }
    }
    return vector<char>();
}

void solve()
{
    int n, m;
    mcc a1;
    cin >> n >> m;
    string city1, city2;
    for(int i = 0; i < n; i++){
        cin >> city1 >> city2;
        char a = city1[0], b = city2[0];
        a1[a].push_back(b);
        a1[b].push_back(a);
    }
    for(int i = 0; i< m; i++){
        cin >> city1 >> city2;
        vector<char> path1 = bfs(city1[0], city2[0], a1);
        for(int i = 0; i < path1.size(); i++){
            cout << path1[i];
        }
        cout << endl;
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
    while(T--) {
        solve();
        if(T) cout << endl;
    }
    return 0;
}