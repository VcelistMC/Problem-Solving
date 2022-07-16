#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a>b){
        int temp = b;
        b = a;
        a = temp;
    }
    double avg = (a+b) / 2;
    int count = (b-a) + 1;

    int sum = avg * count;
    
    sum % 2 == 0? cout << "Nasser": cout << "Hoss";
}