#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<int> vi;

int correctPos = 0;
int totalPossible = 0;
int totalCorrect = 0;
void move(int currPos, int moves){
    if(moves == 0){
        totalPossible++;
        if (currPos == correctPos){
            totalCorrect++;
        }
        return;
    }
    move(currPos + 1, moves - 1);
    move(currPos - 1, moves - 1);
}
void solve()
{
    string real, recv;
    cin >> real >> recv;
    int currentPos = 0;
    int unrec = 0;
    for(int i = 0; i < real.size(); i++){
        if(real[i] == '+') correctPos++;
        else correctPos--;

        if(recv[i] == '+') currentPos++;
        else if(recv[i] == '-') currentPos--;
        else unrec++;
    }

    move(currentPos, unrec);

    cout << fixed << setprecision(12) << (float)totalCorrect / totalPossible;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}