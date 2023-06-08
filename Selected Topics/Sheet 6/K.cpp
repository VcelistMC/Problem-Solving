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
typedef set<int> si;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, vvi &grid){ return inBounds(p.first, p.second, grid); }
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
#define DEBUG_TEST_CASES 1

void solve(vll values, vll cost, int n_tres, int t, si &takenItems){
    ll dp[n_tres + 1][t + 1];
    memset(dp, 0, sizeof dp);

    for(int tres = 1; tres <= n_tres; tres++){
        for(int time = 1; time <= t; time++){
            if(cost[tres-1] <= t){
                ll take = (time - cost[tres-1] >= 0? values[tres-1] + dp[tres-1][time - cost[tres-1]]: 0);
                ll leave = dp[tres-1][time];

                if(take > leave){
                    dp[tres][time] = take;
                }else{
                    dp[tres][time] = leave;
                }
            }else{
                dp[tres][time] = dp[tres-1][time];
            }
        }
    }    
    ll ans = dp[n_tres][t];
    print(ans);

    ll maxC = t;
    for(int i = n_tres; i > 0 && ans > 0; i--){
        if(ans == dp[i-1][maxC]) continue;
        else{
            takenItems.insert(i-1);
            ans -= values[i-1];
            maxC -= cost[i-1];
        }
    }

}

void solve()
{
    int t, w, n_tres;
    ll depth, value;
    bool first = true;
    while(cin >> t >> w){
        if(!first){
            cout << endl;
        }
        
        first = false;
        cin >> n_tres;
        vll values, cost, depths;
        si taken;
        while(n_tres--){
            cin >> depth >> value;
            values.push_back(value);
            depths.push_back(depth);
            cost.push_back(
                (w * depth) * 3
            );
        }
        n_tres = values.size();
        solve(values, cost, n_tres, t, taken);
        print(taken.size());
        for(int ind: taken){
            print(depths[ind] << " " << values[ind]);
        }
    }
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
    T=DEBUG_TEST_CASES;
    #else
    T=1;
    #endif
    while(T--) {solve();}
    return 0;
}