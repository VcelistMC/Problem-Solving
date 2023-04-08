// Hotels Along the Croatian Coast
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

int bs(int start, vector<ll> &prefix, ll target){
    int lo = start+1, hi = prefix.size()-1;
    while(lo <= hi){
        int mid = lo+(hi-lo)/2;
        ll sum = prefix[mid] - prefix[start];
        if(sum < target) lo = mid+1;
        else if(sum > target) hi = mid-1;
        else return mid;
    }
    return hi;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    inputVec(nums);
    vector<ll> prefixSum(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum == m){
            print(m);
            return;
        }
        prefixSum[i] = sum;
    }
    if(prefixSum[n-1] <= m){
        print(m);
    }
    ll maxSoFar = -1;
    for(int i = 0; i < n; i++){
        int j = bs(i, prefixSum, m);
        ll pSum = prefixSum[j]-prefixSum[i];
        if(pSum <= m)
            maxSoFar = max(maxSoFar, prefixSum[j]-prefixSum[i]);
    }
    print(maxSoFar);
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