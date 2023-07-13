#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
#define printGrid(vv) for(auto row: vv){for(auto cell: row){cout << cell << " ";}cout << endl;}
#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(int x, int y, vvi &grid){ return inBounds(x, y, grid.size(), grid[0].size()); }
bool inBounds(pii &p, vvi &grid){ return inBounds(p.first, p.second, grid); }
#define DEBUG_TEST_CASES 3

bool mod8(string num){
    return stoi(num) %8 == 0;
}


void solve()
{
    string n; cin >> n;
    int size = n.size();
    for(int i = 0; i < size; i++){
        int curr1 = (n[i] - '0');
        if(curr1 % 8 == 0){
            print("YES");
            print(curr1);
            return;
        }
        for(int j = i+1; j < size; j++){
            int curr2 = curr1 * 10 + (n[j] - '0');
            if(curr2 % 8 == 0){
                print("YES");
                print(curr2);
                return;
            }

            for(int k = j+1; k < size; k++){
                int curr3 = curr2 * 10 + (n[k] - '0');
                if(curr3 % 8 == 0){
                    print("YES");
                    print(curr3);
                    return;
                }   
            }
        }
    }
    print("NO");
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    T=DEBUG_TEST_CASES;
    #else
    T=1;
    #endif
    while(T--) {solve();}
    return 0;
}