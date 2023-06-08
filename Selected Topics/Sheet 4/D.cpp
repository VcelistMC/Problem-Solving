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

bool isPossible(vi &nums, int currVal, int currPos){
    if(currPos == 5) return currVal == 23;


    return isPossible(nums, currVal + nums[currPos], currPos+1)
        || isPossible(nums, currVal - nums[currPos], currPos+1)
        || isPossible(nums, currVal * nums[currPos], currPos+1);
}

void solve(int a, int b, int c, int d, int e)
{
    vi nums = {a, b, c, d, e};
    sort(all(nums));

    do{
        if(isPossible(nums, nums[0], 1)){
            print("Possible");
            return;
        }

    }while(next_permutation(all(nums)));
    print("Impossible");
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
    int a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e && (a||b||c||d||e)) solve(a, b, c, d, e);
    return 0;
}