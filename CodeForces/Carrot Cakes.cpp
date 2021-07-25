#include <iostream>
using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d; // 2, 3, 6, 1
    int g = (n + k - 1) / k;

    int oven1 = 0, oven2 = d;
    for(int i = 0; i < g; i++)
        oven1 <= oven2 ? oven1 += t : oven2 += t;
    
    max(oven1, oven2) < g * t ? cout << "YES" : cout << "NO";
}