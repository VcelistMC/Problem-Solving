#include<iostream>
#include<vector>
using namespace std;
//unsolved

void parseInput(vector<int> &pylons, int &n)
{
    cin >> n;
    pylons.push_back(0); 
    for(int i = 0; i < n; i++)
    {
        int pylon; cin >> pylon;
        pylons.push_back(pylon);
    }
}

/// My first approach is to treat this problem
/// as subbing problem, u know? when we 
/// divide the problem into smaller problems
/// so we treat each next pylon as the the last one, and decide there 
/// if we can reach it or not
int solve()
{
    vector<int> pylons;
    int energy = 0, n, currPos = 0, dollarsSpent = 0;
    parseInput(pylons, n);



    for(currPos = 0; currPos < n; currPos++)
    {
        int currPylon = pylons[currPos];
        int nextPylon = pylons[currPos + 1];

        if(currPylon >= nextPylon)
            energy += (currPylon - nextPylon);
        else 
        {
            int diff = abs(currPylon - nextPylon);
            if(energy - diff < 0)
            {
                dollarsSpent += (diff - energy);
            }
            else
            {
                energy -= diff;
            }
        }
    }
    return dollarsSpent;
}


int main(){
    
    cout << solve();


    return 0;
}