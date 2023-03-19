#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;

struct cell {
    int row = 0;
    int col = 0;
    cell(int r, int c){
        row = r;
        col = c;
    }
    friend bool operator< (const cell &c1,const cell &c2);

    const bool operator == (const cell &c){
        return row == c.row && col == c.col;
    }
};

bool operator< (const cell &c1,const cell &c2)
{
    if(c1.row != c2.row) return c1.row < c2.row;
    else return c1.col < c2.col;
}

void solve()
{
    set<cell> cells;
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    while(k--){
        int r, c;
        cin >> r >> c;
        cell c(r, c);
        cells.insert(c, opeartor<);
    }

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