#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int pivotIndex(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int wholeSum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        wholeSum += arr[i];
    }

    
    int leftSum = 0;
    int pivotIndex = -1;
    int i = 0;
    while(i < n){
        cout << leftSum << " " << wholeSum << "\n";
        if(i-1 >= 0) leftSum += arr[i-1];
        wholeSum -= arr[i];
        if(i-1 >= 0) wholeSum -= arr[i-1];
        if(leftSum == wholeSum){
            pivotIndex = i;
            break;
        }
        i++;
    }

    return pivotIndex;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr{1,7,3,6,5,6};
    cout << pivotIndex(arr);
    return 0;
}