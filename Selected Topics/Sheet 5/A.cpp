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

int dfs(map<int, vi> &tree, int employee, int T){
    if(tree.find(employee) == tree.end()) return 1;

    int subCount = tree[employee].size();
    vi neededForEach;
    for(int i = 0; i < subCount; i++){
        neededForEach.push_back(
            dfs(tree, tree[employee][i], T)
        );
    }

    sort(all(neededForEach));
    int neededForCurrEmployee = (subCount*T-1)/100+1;

    int ans = 0;
    for (int i = 0 ;i < neededForCurrEmployee; i++)
        ans+= neededForEach[i];
    return ans;
}

void solve(int n, int t)
{
    map<int, vi> tree;
    int employeeBoss;
    for(int i = 1; i <= n; i++){
        cin >> employeeBoss;
        if(i == employeeBoss) continue;

        tree[employeeBoss].push_back(i);
    }

    print(dfs(tree, 0, t));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int n, t;
    while(cin >> n >> t) {
        if(n == 0 && t == 0) break;
        solve(n, t);
    }
    return 0;
}