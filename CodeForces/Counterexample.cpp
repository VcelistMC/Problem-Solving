#include <iostream>
using namespace std;

int main()
{
    long long l, r;
    cin >> l >> r;
    
    if(l%2 != 0)
        l++;
    if(abs(l - r) < 2)
        cout << "-1";
    else{
        long long one = l;
        long long two = l + 1;
        long long three = l + 2;
        cout << one << " " << two << " " << three;
    }
}