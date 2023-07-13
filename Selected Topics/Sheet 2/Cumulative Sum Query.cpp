#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl


void solve()
{
    int T; cin >> T;
    int num;
    vector<int> arr;
    int sum = 0;
    for(int i = 0; i < T; i++){
        cin >> num;
        sum += num;
        arr.push_back(sum);
    }
    cin >> T;
    int i, j;
    while(T--){
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << endl;
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