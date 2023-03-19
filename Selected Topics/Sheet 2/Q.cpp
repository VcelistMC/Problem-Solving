#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl

const int N = 1e5;
bool is_comp[N+1];
set<int> primes_set;
vector<int> primes;

void linearSieve(){
    memset(is_comp, false, N+1);
    is_comp[0]=is_comp[1]=1;
    for (ll i = 2; i < N; i++){
        if(!is_comp[i]) {
            primes.push_back(i);
            primes_set.insert(i);
        }
        
        for(int j = 0; j < primes.size() && i * primes[j] <= N; j++){
            is_comp[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void solve()
{
    string n;
    while(cin >> n, n != "0"){
        string str = n;
        ll currMaxPrime = -1;

        for(int i = 0; i < str.length(); i++){
            string currString = "";
            ll pMaxPrime;
            int maxS = min((int)str.length(), i+6);
            for(int j = i; j < maxS ; j++){
                currString += str.at(j);
                pMaxPrime = stoll(currString);
                if(primes_set.find(pMaxPrime) != primes_set.end()){
                    currMaxPrime = max(currMaxPrime, pMaxPrime);
                }
            }
        }
        print(currMaxPrime);
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