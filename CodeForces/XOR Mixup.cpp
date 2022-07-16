#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> arr)
{
    return arr[0];
}

int main()
{
    int n; cin >> n;
    vector<int> arr;
    int num;
    int m;
    while (n--)
    {
        arr.clear();
        cin >> m;
        while(m--)
        {
            cin >> num;
            arr.push_back(num);    
        }

        cout << solve(arr) << endl;
    }
    
    return 0;
}