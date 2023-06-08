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
const int first25Primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };


void solve(string fruit1, string fruit2)
{
    int len1 = fruit1.length();
    int len2 = fruit2.length();
    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(dp));  // initialize dp table

    // fill out the dp table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (fruit1[i-1] == fruit2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // construct the shortest name using dp table
    int i = len1, j = len2;
    string result = "";
    while (i > 0 && j > 0) {
        if (fruit1[i-1] == fruit2[j-1]) {
            result = fruit1[i-1] + result;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            result = fruit1[i-1] + result;
            i--;
        }
        else {
            result = fruit2[j-1] + result;
            j--;
        }
    }
    while (i > 0) {
        result = fruit1[i-1] + result;
        i--;
    }
    while (j > 0) {
        result = fruit2[j-1] + result;
        j--;
    }

    cout << result << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    string s1, s2;
    while(cin >> s1 >> s2) {solve(s1, s2);}
    return 0;
}