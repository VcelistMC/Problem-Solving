#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl

long long safeGet(deque<long long> &arr, int idx){
    return ((idx >= arr.size())? 0: arr[idx]);
}

void solve()
{
    int n; cin >> n;
    vi arr(n);
    inputVec(arr);
    deque<long long> suffixSum(n);
    suffixSum[n-1] = arr[n-1];
    for(int i = arr.size()-2; i >= 0 ; i--){
        suffixSum[i] = suffixSum[i+1] + arr[i];
    }
    int q; cin >> q;
    int op, x, i, j;
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> i >> j;
            cout << safeGet(suffixSum, i-1) - safeGet(suffixSum, j) << endl;
        }else{
            cin >> x;
            long long top = suffixSum.front();
            suffixSum.push_front(x+top);
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