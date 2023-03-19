#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll unsigned long long
#define llui unsigned long long int
#define endl "\n"
#define all(x) x.begin(), x.end()

void primeFactors(llui n, set<ll> &primes){
    while(n%2 == 0) {
        n=n/2;
        primes.insert(2);    
    }
    for(llui i = 3; i * i <= n; i += 2){
        while(n%i == 0) {
            n=n/i;
            primes.insert(i);
        }
    }
    if (n > 2) {primes.insert(n);}
}

void solve()
{
    int T; cin >> T;
    llui n, num;
    set<ll> primes;
    set<ll> visited;
    vector<ll> nums;
    for(int i = 0; i < T; i++){
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> num;
            nums.push_back(num);
        }
        for(ll i = 0; i < n; i++){
            primeFactors(nums[i], primes);
        }
        cout << "Case #" << (i+1) << ": " << primes.size() << endl;
        for(ll i: primes){
            cout << i << endl;
        }
        visited.clear();
        primes.clear();
        nums.clear();
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