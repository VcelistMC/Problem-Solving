// Hamburgers
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define llui long long unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl


void solve()
{
    string recipe;
    cin >> recipe;
    int susageReq = 0, cheeseReq = 0, breadReq = 0;
    int susageHave, cheeseHave, breadHave;
    int susagePrice, cheesePrice, breadPrice;
    ll money;

    for(char p: recipe){
        if(p == 'B') breadReq++;
        if(p == 'S') susageReq++;
        if(p == 'C') cheeseReq++;
    }
    
    cin >> breadHave >> susageHave >> cheeseHave;
    cin >> breadPrice >> susagePrice >> cheesePrice;

    cin >> money;
    ll minBurgers = 0, maxBurgers = 1e15;
    ll count = 0;   
    while(minBurgers <= maxBurgers){
        ll midBurgers = (minBurgers + maxBurgers) / 2;

        ll breadBuy = max(0LL, breadReq*midBurgers - breadHave);
        ll susageBuy = max(0LL, susageReq*midBurgers - susageHave);
        ll cheeseBuy = max(0LL, cheeseReq*midBurgers - cheeseHave);

        ll totalPrice = (breadBuy * breadPrice) + (susageBuy * susagePrice) + (cheeseBuy * cheesePrice);
        if(money < totalPrice) maxBurgers = midBurgers-1;
        else if (money > totalPrice) {minBurgers = midBurgers+1; count=midBurgers;}
        else{count = midBurgers; break;}
    }
    cout << count;
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