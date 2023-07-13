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
const int INF_WEIGHT = 100000000;

void solve()
{
    int oxyNeeded, nitNeeded;
    cin >> oxyNeeded >> nitNeeded;
    int cylCount; cin >> cylCount;
    vi oxyTanks(cylCount), nitTanks(cylCount), weightTanks(cylCount);
    for(int i = 0; i < cylCount; i++){
        cin >> oxyTanks[i] >> nitTanks[i] >> weightTanks[i];
    }
    vector<vvi> dp(cylCount+1, vvi(oxyNeeded+1, vi(nitNeeded+1, 0)));
    
    for(int i = cylCount; i >= 0; i--){
        for(int j = 0; j <= oxyNeeded; j++){
            for(int k = 0; k <= nitNeeded; k++){
                if(j == 0 && k == 0){
                    dp[i][j][k] = 0;
                    continue;
                }
                else if (i == cylCount){
                    dp[i][j][k] = INF_WEIGHT;
                    continue;
                }
                int leave = dp[i+1][j][k];
                int oxyInd = max(j - oxyTanks[i], 0);
                int nitInd = max(k - nitTanks[i], 0);
                int take = weightTanks[i] + dp[i+1][oxyInd][nitInd];

                dp[i][j][k] = min(leave, take);
            }
        }
    }
    print(dp[0][oxyNeeded][nitNeeded]);
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