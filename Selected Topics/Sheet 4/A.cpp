#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define lli long long int
#define llui long long unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl

void tokenize(string line, int &tapeLength, int &numTracks, vi &tracks){
    stringstream ss(line);
    string token;
    while(getline(ss, token, ' ')){
        if(tapeLength == -1){
            tapeLength = stoi(token);
            continue;
        }
        else if(numTracks == -1){
            numTracks = stoi(token);
            continue;
        }
        else {
            tracks.push_back(stoi(token));
        }
    }
}
vi sol, best, tracks;
int ans;

void recurs(int i, int curr, int numTracks, int tapeLength){
    if(i == numTracks){
        if(curr > ans){
            ans = curr;
            best.clear();
            for(auto num: sol) best.push_back(num);
        }
        return;
    }
    recurs(i+1, curr, numTracks, tapeLength);

    if(tracks[i]+curr <= tapeLength){
        sol.push_back(tracks[i]);
        recurs(i+1, curr+tracks[i], numTracks, tapeLength);
        sol.pop_back();
    }
}

void solve(string line)
{
    int tapeLength = -1, numTracks = -1;
    sol.clear(); best.clear(); tracks.clear();
    ans = 0;
    tokenize(line, tapeLength, numTracks, tracks);
    recurs(0,0, numTracks, tapeLength);
    for(auto bestT: best) cout << bestT << " ";
    cout << "sum:"<<ans << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    string inputLine;
    while(getline(cin, inputLine)) solve(inputLine);
    return 0;
}