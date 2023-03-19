#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    
    while (true)
    {
        int sum = numbers[i] + numbers[j];
        if(sum == target)
            return vector<int>{i+1, j+1};
        else if(sum > target)
            j--;
        else
            i++;
    }
    
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
