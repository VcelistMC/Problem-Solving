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

int binSearch(vi arr, int x, int l, int h){
    if(x < arr[0]) return 0;
    if(x > arr[arr.size()-1]) return arr.size();
    int mid;
    int res;
    while(l <= h){
        mid = (l+h)/2;

        if(arr[mid] <= x) l = mid+1;
        else{
            res = mid;
            h = res-1;
        }
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    inputVec(a);
    int num;
    sort(all(a));
    while(m--){
        cin >> num;
        cout << (upper_bound(all(a), num) - a.begin()) << " ";
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