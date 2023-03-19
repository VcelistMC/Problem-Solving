#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

void solve()
{
    int n, num;
    cin >> n;
    vi arr, sorted_arr;
    while (n--)
    {
        cin >> num;
        arr.push_back(num);
        sorted_arr.push_back(num);
    }



    sort(sorted_arr.begin(), sorted_arr.end());
    n = arr.size();

    int diffStart = -1, diffEnd = -1;

    for (int i = 0; i < n; i++)
    {
        int n1 = arr[i];
        int n2 = sorted_arr[i];

        if (n1 != n2)
        {
            diffStart = i;
            break;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        int n1 = arr[i];
        int n2 = sorted_arr[i];

        if (n1 != n2)
        {
            diffEnd = i;
            break;
        }
    }

    

    reverse(arr.begin() + diffStart, arr.begin() + diffEnd + 1);
    if(is_sorted(arr.begin(), arr.end())){
        if(diffStart == -1) cout << "yes\n1 1";
        else cout << "yes\n" << diffStart + 1 << " " << diffEnd + 1;
    }
    else cout << "no";

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