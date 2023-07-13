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

int safeGet(vi &values, vi &weights, int itemInd, int weight, vector<vi> &dp){
    return (weight - weights[itemInd-1] >= 0? values[itemInd-1] + dp[itemInd-1][weight - weights[itemInd-1]]: 0);
}

void solve()
{
    int cap, num;
    cin >> cap >> num;
    vi values(num), weights(num);
    for(int i = 0; i < num; i++){ cin >> weights[i] >> values[i]; }

    vvi dp(num+1, vi(cap+1, 0));

    for(int bagInd = 1; bagInd <= num; bagInd++){
        for(int weight = 1; weight <= cap; weight++){
            if(weights[bagInd-1] <= cap){
                dp[bagInd][weight] = max(
                    dp[bagInd-1][weight],
                    safeGet(values, weights, bagInd, weight, dp)
                );
            }else{
                dp[bagInd][weight] = dp[bagInd-1][weight];
            }
        }
    }    
    printf("Hey stupid robber, you can get %d.\n", dp[num][cap]);
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