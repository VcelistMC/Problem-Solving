#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void coutAns(int a, int b){ cout << a << " " << b << "\n"; }
void solve()
{
    int n; cin >> n;
    string road; cin >> road;
    int start, end;

    for(int i = 0; i < n; i++){
        if(road[i] != '.')
        {
            start = i;
            break;
        } 
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(road[i] != '.')
        {
            end = i;
            break;
        }
    }

    if(road[start] == 'R' && road[end] == 'R') coutAns(start+1, end+2);
    else if(road[start] == 'L' && road[end] == 'L') coutAns(end+1, start);
    else
    {
        for(int i = start; i < n; i++)
        {
            end = i;
            if(road[i] == 'L') break;
        }
        coutAns(start+1, end);
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