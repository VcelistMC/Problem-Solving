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
    int n; cin >> n;
    vi a(n);
    int maxNum = -1;
    int currGcd = -1;
    set<int> visited;
    map<int, int> freq;
    vi b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxNum = max(a[i], maxNum);
        freq[a[i]]++;
    }
    b.push_back(maxNum);
    freq[maxNum]--;
    currGcd = maxNum;

    while(b.size() != n){
        int pMaxNum = -1;
        int pMaxGcd = -1;
        for(int i = 0; i < n; i++){
            if(!freq[a[i]]) continue;

            int gcd = __gcd(currGcd, a[i]);
            if(gcd > pMaxGcd){
                pMaxGcd = gcd;
                pMaxNum = a[i];
            }
        }
        b.push_back(pMaxNum);
        currGcd = pMaxGcd;
        freq[pMaxNum]--;
    }
    for(auto i: b){
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T; cin >> T;
    while(T--) {solve();}
    return 0;
}