// Easy Longest Increasing Subsequence
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


void solve()
{
    int n; cin >> n;
    if(n == 1){
        print(1);
        return;
    }
    vi nums(n);
    inputVec(nums);
    vi countSoFar(n, 1);

    int i = 0, j = 1;
    while(j < n){
        while(i != j){
            if(nums[j] > nums[i]){
                countSoFar[j] = max(countSoFar[j], countSoFar[i]+1);
            }
            i++;
        }
        i = 0;
        j++;
    }
    int maxSoFar = countSoFar[0];
    for(auto i: countSoFar) maxSoFar = max(maxSoFar, i);
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