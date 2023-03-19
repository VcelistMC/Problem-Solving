#include <iostream>
#include <unordered_map>
using namespace std;

bool checkAndAssign(int &var, unordered_map<int, bool> &taken, int target, int takenNumber){
    int pvar = target - takenNumber;
    if(taken[pvar] || pvar < 1|| pvar > 9) return false;

    var = pvar;
    taken[var] = true;
    return true;
    
}


int main()
{
    // unordered_map<int, bool> nums_taken {
    //     pair<int, bool>(1, false),
    //     pair<int, bool>(2, false),
    //     pair<int, bool>(3, false),
    //     pair<int, bool>(4, false),
    //     pair<int, bool>(5, false),
    //     pair<int, bool>(6, false),
    //     pair<int, bool>(7, false),
    //     pair<int, bool>(8, false),
    //     pair<int, bool>(9, false),
    // };

    int c1, c2, r1, r2, d1, d2;
    std::cin >> r1 >> r2;
    std::cin >> c1 >> c2;
    std::cin >> d1 >> d2;
    bool correct = true;
    int x1 = -1, x2 = -1, x3 = -1, x4 = -1;

    for(int i = 1; i <= 9; i++){
        x2 = -1; 
        x3 = -1; 
        x4 = -1;
        unordered_map<int, bool> nums_taken {
            pair<int, bool>(1, false),
            pair<int, bool>(2, false),
            pair<int, bool>(3, false),
            pair<int, bool>(4, false),
            pair<int, bool>(5, false),
            pair<int, bool>(6, false),
            pair<int, bool>(7, false),
            pair<int, bool>(8, false),
            pair<int, bool>(9, false),
        };
        x1 = i;

        nums_taken[i] = true;        

        if(!checkAndAssign(x2, nums_taken, r1, x1)) continue;
        if(!checkAndAssign(x3, nums_taken, c1, x1)) continue;
        if(!checkAndAssign(x4, nums_taken, r2, x3)) continue;

        correct = true;
        if(x1 + x2 != r1) correct = false;
        if(x3 + x4 != r2) correct = false;
        if(x1 + x3 != c1) correct = false;
        if(x2 + x4 != c2) correct = false;
        if(x1 + x4 != d1) correct = false;
        if(x2 + x3 != d2) correct = false;

        if(correct) break;
    }

    if(x1 == -1 || x2 == -1 || x3 == -1 || x4 == -1 || !correct) cout << -1;
    else cout << x1 << " " << x2 << "\n" << x3 << " " << x4;
}