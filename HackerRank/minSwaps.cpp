#include <bits/stdc++.h>

using namespace std;


int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    int num1 = arr[0];
    int i = 0;
    while(num1-1 == i)
    {
        i++;
        num1 = arr[i];
    }
    int og = num1;
    do
    {
        swaps++;
        num1 = arr[num1-1];
    } while (num1 != arr[num1-1] && num1 != og);
    
    return swaps;
}

int main() 
{
    vector<int> arr;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int ele; cin >> ele;
        arr.push_back(ele);
    }
    cout << minimumSwaps(arr);
}