#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int num;
    while(n--){
        cin >> num;
        if (num < 0) num++;
        cout << num << " ";
    }
}