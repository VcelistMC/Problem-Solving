#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, z;
        cin >> n >> z;
        vector<int> arr(n);
        vector<int> arr2(n);
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > m)
            {
                m = arr[i];
            }
            int p = arr[i] | z;
            arr2[i] = p;
        }
        int max = m;
        for (int i = 0; i < n; i++)
        {
            if (arr2[i] > max)
            {
                max = arr2[i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
