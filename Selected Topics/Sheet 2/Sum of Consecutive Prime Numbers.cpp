#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl

const int N = 10001;
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
    int n;
    while(cin >> n, n){
        int count = 0;
        if(n < 2) {cout << 0 << endl; continue;}
        if(n == 2 || n == 3) {cout << 1 << endl; continue;}

        for(int i = 0; i < primes.size(); i++){
            int sum = 0;
            for(int j = i; j < primes.size(); j++){
                sum += primes[j];
                if(sum == n){count++; break;}
                else if(sum > n) break;
            }
        }
        cout << count << endl;
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