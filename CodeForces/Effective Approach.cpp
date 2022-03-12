#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    map<unsigned int, vector<unsigned int>> data;
    unsigned int vasyaApproach = 0, petyaApproach = 0;
    unsigned int n; cin >> n;
    for(unsigned int i = 1; i<=n; i++)
    {
        //each element holds a vector with two numbers, its position from each end, aka, how each fookin' team member's approach
        //would perform
        // 3 1 2
        // 3: {1, 3}
        // 1: {2, 2}
        // 2: {3, 1}
        unsigned int ele; cin >> ele; 
        data[ele] = {i, n-i+1};
    }
    unsigned int m; cin >> m;
    while(m)
    {
        unsigned int query; cin >> query;
        vasyaApproach += data[query][0];
        petyaApproach += data[query][1];
        m--;
    }
    cout << vasyaApproach << " " << petyaApproach;

}