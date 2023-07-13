//Bear and Finding Criminals
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
    int n, c;
    cin >> n >> c;
    vi actualCriminals(n);
    actualCriminals.push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> actualCriminals[i];
    }
    int i = c-1, j = c+1;
    int ans = actualCriminals[c];
    int city1HasCrim = 0;
    int city2HasCrim = 0;
    while(true){
        if(i <= 0 && j > n) break;
        if(i <= 0) city1HasCrim = 1;
        else city1HasCrim = actualCriminals[i];

        if(j > n) city2HasCrim = 1;
        else city2HasCrim = actualCriminals[j];

        if(city1HasCrim && city2HasCrim){
            if(i <= 0 || j > n) ans++;
            else ans += 2;
        }
        i--;
        j++;
    }
    print(ans);

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