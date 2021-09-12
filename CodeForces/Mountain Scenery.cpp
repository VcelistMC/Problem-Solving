//solved

#include <iostream>
#include <vector>
using namespace std;

bool isValid(int peak, vector<int> picture)
{
    return (
        picture[peak-1] < picture[peak] &&
        picture[peak] > picture[peak+1]
    );
}

bool solveRecurs(int peak, int &k, vector<int> &picture)
{
    if(k == 0)
        return true;
    
    picture[peak-1]--;
    if(isValid(peak-1, picture))
        k--;
    else
        picture[peak-1]++;
    return solveRecurs(peak+2, k, picture);
}

int main()
{
    int n, k;
    vector<int>picture;
    cin >> n >> k;
    for(int i = 0; i < 2*n+1; i++)
    {
        int peak; cin >> peak;
        picture.push_back(peak);
    }
    solveRecurs(2, k, picture);
    for(int i : picture)
        cout << i << " ";
}