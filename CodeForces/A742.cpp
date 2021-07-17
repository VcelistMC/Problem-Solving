#include <iostream>
#include <math.h>
using namespace std;

int solve(int n)
{
    if(n == 0)
        return 1;
    if(n % 4 == 1)
        return 8;
    if(n % 4 == 2)
        return 4;
    else if(n % 4 == 3)
        return 2;
    else if (n % 4 == 0)
        return 6;
}

//there's a pattern 8 4 2 6
//the trick is to find how many "8 4 2 6"s in the power

// int solve(int n)
// {
//     if(n == 0)
//         return 1;
//     if(n == 1)
//         return 8;
//     int digit = 1;
//     for(int i = 1; i <= n; i++)
//         digit = (digit * 8) % 10, cout << i << " - " << digit << "/" << test(i) << endl;
//     return digit >= 10? digit % 10 : digit;
// }

int main()
{
    int n; cin >> n;
    cout << solve(n);
}