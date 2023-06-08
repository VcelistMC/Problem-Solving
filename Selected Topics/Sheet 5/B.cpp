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



void solve()
{
    int n, comrade, comradeLen; cin >> n;
    vector<vi> adj(n);
    for(int i = 0; i < n; i++){
        cin >> comrade >> comradeLen;
        vi connections(comradeLen);
        inputVec(connections);
        adj[comrade] = connections;
    }
    int asking, asked;
    cin >> asking >> asked; 
    queue<int> q;
    set<int> visited;
    int steps = 0;
    q.push(asking);
    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            int curr = q.front();
            q.pop();
            visited.insert(curr);
            if(curr == asked){
                cout << asking << " " << asked << " " << steps-1 << endl;
                return;
            }
            for(auto connection: adj[curr]){
                if(visited.find(connection) == visited.end()){
                    q.push(connection);
                }
            }

        }
        steps++;
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
        cin.ignore();
        solve();
        if(T != 0) cout << endl;
    }
    return 0;
}