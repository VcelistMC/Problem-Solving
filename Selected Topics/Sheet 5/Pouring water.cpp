#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ll long long
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
#define ui unsigned int
typedef pair<ui, ui> puii;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
#define mp make_pair
#define pb push_back
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }

int gcd(int a, int b){
	return ((a%b == 0)
        ? b
        : gcd(b, a%b));
}

void visit(ui a, ui b, queue<puii> &q, set<puii> &v){
    puii next = mp(a, b);
    if(v.find(next) == v.end()){
        q.push(next);
        v.insert(next);
    }
}

int bfs(ui a, ui b, ui c){
    puii first = mp(0, 0);
    queue<puii> q;
    set<puii> v;
    q.push(first);
    v.insert(first);
    int steps = 0;
    while(!q.empty()){
        int s = q.size();
        while(s--){
            puii curr = q.front();
            q.pop();
            if(c == curr.first || c == curr.second){
                return steps;
            }

            visit(0, curr.second, q, v);
            visit(curr.first, 0, q, v);
            visit(a, curr.second, q, v);
            visit(curr.first, b, q, v);

            ui newb = min(b, curr.first + curr.second);
            ui newa = curr.first - (newb - curr.second);
            visit(newa, newb, q, v);

            newa = min(a, curr.first + curr.second);
            newb = curr.second - (newa - curr.first);
            visit(newa, newb, q, v);    
        }
        steps++;
    }
    return -1;
}

void solve()
{
    ui a, b, c;
    cin >> a >> b >> c;
    (c % gcd(a, b) == 0 && c <= max(a, b))
        ? print(bfs(a, b, c))
        : print(-1);
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