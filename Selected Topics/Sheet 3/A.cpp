//A - Cellular Network

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

int bs(int target, vector<int> &arr)
{
    int lo = 0;
    int hi = arr.size()-1;
    if(target <= arr[0]) return arr[lo];
    if(target >= arr[hi]) return arr[hi];

    while(lo <= hi){
        int mid = (lo+hi) / 2;

        if(target < arr[mid]) hi = mid-1;
        else if(target > arr[mid]) lo = mid+1;
        else return target;
    }
    return (arr[lo] - target) < (target - arr[hi])
        ? arr[lo]
        : arr[hi];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vi cities(n), towers(m);
    for(int i = 0; i < n; i++){
        cin >> cities[i];
    }
    for(int i = 0; i < m; i++){
        cin >> towers[i];
    }
    int currMax = -1;
    for(int city: cities){
        int nearestTower = bs(city, towers);
        currMax = max(currMax, abs(nearestTower - city));
    }
    print(currMax);
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