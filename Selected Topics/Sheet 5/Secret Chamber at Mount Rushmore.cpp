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

typedef map<char, vector<char>> mcv;

bool dfs(char start, char end, mcv &dic, set<pair<char, char>> &v){
    if(start == end) return true;
    if(dic.find(start) == dic.end()) return false;
    if(v.find(make_pair(start, end)) != v.end()) return false;

    v.insert(make_pair(start, end));

    for(char child: dic[start]){
        if(dfs(child, end, dic, v)) 
            return true;
    }
    return false;
}

bool check(string wordA, string wordB, mcv &ab){
    if(wordA.size() != wordB.size()) return false;

    int n = wordA.size();


    for(int i = 0; i < n; i++){
        set<pair<char, char>> visited;
        char a = wordA[i], b = wordB[i];
        if(a == b) continue; 
        if(ab.find(a) == ab.end()) return false;
        
        if(!dfs(a, b, ab, visited)) return false;
    }
    return true;
}

void solve(int m, int n)
{
    mcv ab;
    // mcv ba;
    char a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        ab[a].push_back(b);
        // ba[b].push_back(a);
    }

    string wordA, wordB;
    for(int i = 0; i < n; i++){
        cin >> wordA >> wordB;
        if(wordA == wordB) print("yes");
        else {
            check(wordA, wordB, ab)
                ? print("yes")
                : print("no");
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
    int m, n;
    while(cin >> m >> n) {
        solve(m, n);
    }
    return 0;
}