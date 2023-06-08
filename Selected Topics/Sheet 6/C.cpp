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

int safeGet(vi &values, vi &weights, int itemInd, int weight, vector<vi> &dp){
    return (weight - weights[itemInd-1] >= 0? values[itemInd-1] + dp[itemInd-1][weight - weights[itemInd-1]]: 0);
}

void solve()
{
    int capacity, numItems;
    cin >> capacity >> numItems;
    vi weights(numItems), values(numItems);
    for(int i = 0; i < numItems; i++){
        cin >> weights[i] >> values[i];
    }

    vector<vi> dp(numItems+1, vi(capacity+1, 0));

    for(int itemInd = 1; itemInd <= numItems; itemInd++){
        for(int weight = 1; weight <= capacity; weight++){  
            if(weights[itemInd - 1] <= capacity)
                dp[itemInd][weight] = max(
                    dp[itemInd-1][weight], 
                    safeGet(values, weights, itemInd, weight, dp)
                );
            else
                dp[itemInd][weight] = dp[itemInd-1][weight];
        }
    }
    print(dp[numItems][capacity]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}