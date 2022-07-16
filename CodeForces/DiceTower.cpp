#include <iostream>
using namespace std;

int main()
{
    int n, x, y, z;
    cin >> n >> z;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if(x == z || x == 7-z || y == z || y == 7-z) {cout << "NO"; return 0;}
    }
    cout << "YES";

}