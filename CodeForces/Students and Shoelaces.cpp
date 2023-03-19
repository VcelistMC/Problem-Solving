#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> students(n+1);
    int s1, s2;
    for(int i = 0; i < m; i++){
        cin >> s1 >> s2;
        students[s1].insert(s2);
        students[s2].insert(s1);
        
    }
    vi toBeRemoved;
    int groups = 0;
    while (true)
    {
        toBeRemoved.clear();
        for(int i = 1; i < n+1; i++){
            if(students[i].size() == 1) {
                toBeRemoved.push_back(i);
            }
        }
        
        if(toBeRemoved.size() == 0){
            cout << groups;
            return;
        }

        for(int student: toBeRemoved){
            int tiedTo = *(students[student].begin());
            students[tiedTo].erase(student);
            students[student].clear();
        }
        groups++;
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