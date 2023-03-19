#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0;
    int n = arr.size();
    for(int i = 1; i < n; i += 2)
    {
        for(int j = 0; j < n; j+= i)
        {
            sum += arr[j];
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}