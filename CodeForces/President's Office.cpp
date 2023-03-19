#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;

int getNeighbors(int i, int j, vector<vi> dirs, vector<string> office_map, char pr, set<char> &taken){
    int dep = 0;

    for(vi dir: dirs){
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if(new_i < 0 
            || new_j < 0 
            || new_i >= office_map.size() 
            || new_j >= office_map[0].length()
            || taken.find(office_map[new_i][new_j]) != taken.end()) continue;

        dep += (office_map[new_i][new_j] != '.' && office_map[new_i][new_j] != pr);
        taken.insert(office_map[new_i][new_j]);
    }

    return dep;
}

void solve()
{
    int n, m;
    char pr;
    cin >> n >> m;
    cin >> pr;
    vector<vi> pIndices;
    vector<string> office_map;
    string row;
    for(int i = 0; i < n; i++){
        cin >> row;
        for(int j = 0; j < m; j++){
            if(row[j] == pr){
                pIndices.push_back({i, j});
            }
        }
        office_map.push_back(row);
    }

    vector<vi> dirs = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };

    int dep = 0;
    set<char> taken;
    for(vi index: pIndices){
        dep += getNeighbors(index[0], index[1], dirs, office_map, pr, taken);
    }

    cout << dep << "\n";
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