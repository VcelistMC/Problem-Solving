// solved
#include <iostream>
#include <vector>
using namespace std;

int runBCD(vector<bool> cities, int limakCity, int n)
{
    int criminals = 0;
    int leftPointer = limakCity - 1;
    int rightPointer = limakCity + 1;
    while(leftPointer >= 1 || rightPointer <= n)
    {
        bool leftCriminal = (leftPointer >= 1)? cities[leftPointer]: false;
        bool rightCriminal = (rightPointer <= n)? cities[rightPointer]: false;

        if(leftCriminal && rightCriminal) // if there're two criminals, then limak is sure that he could catch them
            criminals+=2;
        else if(leftCriminal || rightCriminal) // if there's only one criminal detected, and one pointer is out of bounds, then limak can catch them
        {
            if((leftPointer < 1 || rightPointer > n))
                criminals++;
        }
        
        leftPointer--;
        rightPointer++;
    }
    return (cities[limakCity])? criminals+1 : criminals;
}

int solve()
{
    vector<bool> cities;
    cities.push_back(0); //to make it a 1-indexed array to make solving easier
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        bool city; cin >> city;
        cities.push_back(city);
    }
    return runBCD(cities, k, n);
}


int main(int argc, char const *argv[])
{
    cout << solve();
    return 0;
}
