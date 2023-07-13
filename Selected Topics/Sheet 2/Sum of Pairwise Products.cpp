#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl


void solve()
{
    int n; cin >> n;
    vector<ll> arr(n);
    inputVec(arr);
    vector<ll> prefixSum(n), pairwiseSum(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        prefixSum[i] = sum;
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i] * arr[i];
        pairwiseSum[i] = sum;
    }

    int q; cin >> q;
    int i, j;
    while(q--){
        cin >> i >> j;
        ll rangeSum = prefixSum[j];
        if(i) rangeSum -= prefixSum[i-1];

        ll squareSum = pairwiseSum[j];
        if(i) squareSum -= pairwiseSum[i-1];
        
        rangeSum = rangeSum * rangeSum;
        print(
            (rangeSum + squareSum)/2
        );
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