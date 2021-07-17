#include <iostream>
using namespace std;
#define ll long long

void solve(ll n)
{
    if(n % 2 != 0)
        {n++; n = -n;}
    
    cout << (n / 2);
}

int main()
{
    ll n; cin >> n;
    solve(n);
    return 0;
}