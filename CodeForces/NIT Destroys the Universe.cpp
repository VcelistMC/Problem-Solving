#include <iostream>
#include <vector>
using namespace std;

int solve()
{
    int n;
    cin >> n;
    vector<int> zeros_indices;
    int zeroCount = 0;
    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 0)
        {
            zeroCount++;
            zeros_indices.push_back(i);
        }
    }

    if(zeroCount == n) return 0;
    if(n == 1 || zeroCount == 0) return 1;

    int ans = zeros_indices[0] != 0? 1 : 0;
    if(zeros_indices[zeroCount-1] != n-1) ans++;

    for(int i = 0; i < zeroCount - 1; i++){
        if(zeros_indices[i] != zeros_indices[i+1] - 1) ans++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << solve() << endl;
}