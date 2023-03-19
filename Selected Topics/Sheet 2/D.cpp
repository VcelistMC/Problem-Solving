#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define repeat(i, n) for(i = 0; i < n; i++)

const int N = 100000000+1;
ll leastPrime[N+1];
vector<int> primes;

void sieve()
{
    for (ll i=2; i<=N; ++i)
    {
        if (leastPrime[i] == 0)
        {
            leastPrime[i] = i;
            primes.push_back(i);
        }

        int s = (int)primes.size();

        for (ll j=0; j<s && primes[j]<=leastPrime[i] && i*primes[j]<=N; ++j){
            leastPrime[i * primes[j]] = primes[j];
        }
    }
}


void solve()
{
    int n; 
    sieve();
    while(cin >> n, n){
        cout << leastPrime[n] << endl;
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