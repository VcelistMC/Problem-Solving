#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
int MOD = 10e8 + 7;
void solve()
{
    string word;
    cin >> word;
    char prevLetter;
    int n = word.length();
    vi dp(n+1);
    set<char> possible = {'n', 'u'};
    set<char> impossible = {'m', 'w'};
    for(int i = 0; i < n; i++){
        if(impossible.find(word[i]) != impossible.end()){
            print(0);
            return;
        }

        if(i == 0){
            dp[i] = 1;
            prevLetter = word[i];      
            continue;  
        }

        if(word[i] == prevLetter && possible.find(word[i]) != possible.end()){
            if(i == 1){
                dp[i] = 2;
            }else{
                dp[i] = (dp[i-1] + dp[i-2]) % MOD;                
            }
        }
        else{
            dp[i] = dp[i-1];
        }
        prevLetter = word[i];        
    }


    print(dp[n-1]);
    // print(MOD);
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
    T = 4;
#else
    T = 1;
#endif
    while(T--) {solve();}
    return 0;
}