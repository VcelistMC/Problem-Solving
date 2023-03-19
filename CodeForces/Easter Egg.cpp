#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void solve()
{
    char colors[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    int n; cin >> n;
    int i = 0;
    int step = 0;
    for(int egg = 0; egg < n; egg++)
    {
        if(egg < 7)
            cout << colors[egg];
        else
        {
            cout << colors[(egg - 4) % 7];
        }
        i++;
    }
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