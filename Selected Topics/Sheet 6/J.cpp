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

int safeGet(
    vi &prices, vi &favors, int itemInd, int spent, vvi &dp
){
    return (spent - prices[itemInd-1] >= 0)
        ? favors[itemInd-1] + dp[itemInd-1][spent - prices[itemInd-1]]
        : 0;
}

void solve(int money, int list)
{
    int moneyWithBon = money+200;
    vi price(list), favor(list);
    for(int i = 0; i < list; i++){
        cin >> price[i] >> favor[i];
    }

    vvi dp(list+1, vi(money+1, 0));
    vvi dpBonus(list+1, vi(moneyWithBon + 1, 0));
    int currSpent = 0;

    for(int itemInd = 1; itemInd <= list; itemInd++){
        for(
            int spent = 1, spentBonus = 1; 
            spent <= money || spentBonus <= moneyWithBon;
            spent++, spentBonus++
        ){
            if(spent <= money){
                if(price[itemInd-1] <= money){
                    int leave = dp[itemInd-1][spent];
                    int take = safeGet(price, favor, itemInd, spent, dp);

                    if(take > leave){
                        dp[itemInd][spent] = take;
                        currSpent += price[itemInd-1];
                    }else{
                        dp[itemInd][spent] = leave;
                    }

                }else{
                    dp[itemInd][spent] = dp[itemInd-1][spent];
                }
            }

            if(spentBonus <= moneyWithBon){
                if(price[itemInd-1] <= moneyWithBon){
                    dpBonus[itemInd][spentBonus] = max(
                        dpBonus[itemInd-1][spentBonus],
                        safeGet(price, favor, itemInd, spentBonus, dpBonus)
                    );
                }else{
                    dpBonus[itemInd][spentBonus] = dpBonus[itemInd-1][spentBonus];
                }
            }
        }
    }

    // money >= 1800
    //     ? print(dpBonus[list][moneyWithBon])
    //     : print(dp[list][money]);

        print(dpBonus[list][moneyWithBon]);
        print(dp[list][money]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int money, list;
    while(cin >> money >> list) {solve(money, list);}
    return 0;
}