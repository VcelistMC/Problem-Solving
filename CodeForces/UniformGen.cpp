#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int curr = 0, step, mod;
    while(cin >> step >> mod)
    {
        bool visited[mod] = {false};
        bool badChoice = false;
        for(int i = 0; i < mod; i++){
            int gen = (curr + step) % mod;
            if(visited[gen]){
                badChoice = true;
                break;
            }
            visited[gen] = 1;
            curr = gen;
        }
        cout << setw(10) << step << setw(10) << mod << "    ";
        badChoice ? cout << "Bad Choice\n\n" : cout << "Good Choice\n\n";
    }
}