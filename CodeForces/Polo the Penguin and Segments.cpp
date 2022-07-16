#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void solve()
{
    int n, k;
    cin >> n >> k;
    int covered = 0;
    int start, end;
    while(n--)
    {
        cin >> start >> end;
        covered += (end - start + 1);
    }
    int rem = covered % k;

    cout << (rem? k - rem: 0) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}