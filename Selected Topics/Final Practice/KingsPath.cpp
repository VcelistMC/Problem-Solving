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
#define DEBUG_TEST_CASES 2

class triplet{
public:
    int first = 0;
    int second = 0;
    int third = 0;
    triplet(int a, int b, int c){
        first = a;
        second = b;
        third = c;
    }
    triplet(){
        first = 0;
        second = 0;
        third = 0;
    }

    bool operator<(const triplet& other) const {
        if (first < other.first) {
            return true;
        } else if (first == other.first) {
            if (second < other.second) {
                return true;
            } else if (second == other.second) {
                return third < other.third;
            }
        }
        return false;
    }
};



void solve()
{
    pii start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    int n; cin >> n;
    vector<triplet> seg(n);
    triplet minSeg, maxSeg;
    pii upperLeft, 
    for(int i = 0; i < n; i++){
        cin >> seg[i].first >> seg[i].second >> seg[i].third;
        if(i == 0){
            minSeg = seg[0], maxSeg = seg[0];
        }

        if(seg[i] < minSeg) minSeg = seg[i];
        if(!(seg[i] < maxSeg)) maxSeg = seg[i];
    }
    cout << minSeg.first << " " << minSeg.second << " "  << minSeg.third << endl;
    cout << maxSeg.first << " "  << maxSeg.second << " "  << maxSeg.third << endl;
    cout << endl;
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