//solved
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    for(int i = num-1; i > 1; i--)
        if(num % i == 0)
            return false;
    return true;
}

bool solve(int n, int m)
{
    if(!isPrime(m))
        return false;
    for(int i = m-1; i != n; i--)
    {
        if(isPrime(i))
            return false;
    }
    return true;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    cout << (solve(n, m)? "YES" : "NO");
}
