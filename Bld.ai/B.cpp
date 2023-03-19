#include <iostream>
#include <map>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    int num;
    vector<int> arr;
    while(n--)
    {
        cin >> num;
        arr.push_back(num);
    }

    n = arr.size();
    int currMin = arr[n-1];
    int currFreq = 1;
    vector<int> ans(n);
    ans[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] == currMin)
        {
            currFreq++;
            ans[i] = currFreq;
        }
        else if(arr[i] < currMin)
        {
            currFreq = 1;
            currMin = arr[i];
            ans[i] = currFreq;
        }
        else{
            ans[i] = currFreq;
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

}