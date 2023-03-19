#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define llui long long unsigned int
#define endl "\n"


void solve()
{
    char num[20];
    int pairs[1024] = {0};
    int T;
    scanf("%d", &T);
    lli count = 0;
    while(T--){
        int rep = 0;
        scanf("%s", num);
        for(int i = 0; i < num[i] != '\0'; i++){
            int ind = num[i] - '0';
            rep |= (1 << ind);
        }
        count += pairs[rep];
        pairs[rep]++;
    }
    for(int i = 0; i < 1024; i++){
        for(int j = i+1; j < 1024; j++){
            if(i & j) count += pairs[i]* pairs[j];
        }
    }
    printf("%lli\n", count);
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