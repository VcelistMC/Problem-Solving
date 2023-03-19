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
#define mp make_pair
#define pii pair<int, int>

const int N = 2e7;
bool is_comp[N+1];
vector<int> primes;
vector<pii> twins;

void linearSieve(){
    memset(is_comp, false, N+1);
    is_comp[0]=is_comp[1]=1;
    for(ll i = 2; i <= N; i++){
        if(!is_comp[i]){
            primes.push_back(i);
            if(!is_comp[i-2]){
                twins.push_back(mp(i-2, i));
            }
        }

        for(int j = 0; j < primes.size() && i * primes[j] <= N; j++){
            is_comp[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}


void solve()
{
    int n;
    while(cin >> n){
        pii desired = twins[n-1];
        cout << "(" << desired.first << ", " << desired.second << ")\n";
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