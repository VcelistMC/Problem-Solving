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

const int d1 = 1 << 18;
const int d2 = 1 << 17;


void solve()
{
    int n, x;
    cin >> n >> x;
    if(n == 1){
        cout << "YES\n" << x;
    }
    else if(n == 2){
        if(x == 0) cout << "NO";
        else cout << "YES\n0 " << x;
    }
    // else if(n == 3){
    //     cout << "YES\n0 1 ";
    //     if(x & 1) cout << x - 1;
    //     else cout << x + 1;
    // }
    // else if(n == 4){
    //     cout << "YES\n0 1 " << x << " ";
    //     if(x & 1) cout << x - 1;
    //     else cout << x + 1;
    // }
    else {
        int res = 0;
        vi ans;
        
        
        for(int i = 1; i <= n-3; i++){
            res ^= i;
            ans.push_back(i);
        }
        
        cout << "YES\n";
        if(res == x){
            ans.push_back(d1+d2);
            ans.push_back(d1);
            ans.push_back(d2);
        }else{
            ans.push_back(d2);
            ans.push_back((d2^x)^res);
            ans.push_back(0);
        }
        for(auto i: ans){
            cout << i << " ";
        }
    }
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