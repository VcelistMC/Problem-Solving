#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define llui long long unsigned int
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl

const int N = 1e5;
bool is_comp[N+1];
vector<int> primes;

void linearSieve(){
    memset(is_comp, false, N+1);
    is_comp[0]=is_comp[1]=1;
    for (ll i = 2; i < N; i++){
        if(!is_comp[i]) primes.push_back(i);
        
        for(int j = 0; j < primes.size() && i * primes[j] <= N; j++){
            is_comp[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void solve()
{
    ll n; 
    while(cin >> n, n){
        bool neg = false;
        if(n < 0){
            n = -n;
            neg = true;
        }
        ll gcd = 0;
        for(auto i: primes){
            ll ct = 0;
            while(n%i == 0){
                n /= i;
                ct++;
            }
            gcd = __gcd(gcd, ct);
        }
        if(n!=1) gcd = 1;
        if(neg){
            while(!(gcd%2)) gcd /= 2;
        }
        print(gcd);
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
    linearSieve();
    solve();
    return 0;
}