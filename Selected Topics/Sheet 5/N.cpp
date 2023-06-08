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
typedef pair<char, int> pic;

map<string, bool> R;

string build(vector<pic> sv){
    string s = "";
    for(pic p: sv){
        for(int i = 0; i < p.second; i++) s += p.first;
    }
    return s;
}

bool dfs(vector<pic> sv){
    if(sv.empty()) return true;

    string s = build(sv);


    map<string, bool>:: iterator it = R.find(s);
    if(it != R.end()){
        return it->second;
    }

    bool &ret = R[s];

    for(int i = 0; i < sv.size(); i++){
        if(sv[i].second < 2) continue;
        vector<pic> newSv(sv);
        int before = i-1;
        int after = i+1;
        int pos = 0;
        if(before >= 0 && after < sv.size()){
            if(newSv[before].first == newSv[after].first){
                newSv[before].second += newSv[after].second;
                newSv.erase(newSv.begin() + (after));
                pos += 1;
            }
        }

        newSv.erase(newSv.begin() + (i));
        ret |= dfs(newSv);
    }
    return ret;
}

void solve()
{
    string s; cin >> s;
    vector<pic> sv;
    char currC = s[0];
    int count = 0;
    for(char c: s){
        if(c == currC) count++;
        else{
            sv.push_back(make_pair(currC, count));
            currC = c;
            count = 1;
        }
    }
    sv.push_back(make_pair(currC, count));

    dfs(sv)
        ? print(1)
        : print(0);
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