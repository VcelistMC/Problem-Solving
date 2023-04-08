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

vi tokenize(string line, int &tapeLength, int &numTracks, vi &tracks){
    stringstream ss(line);
    string token;
    vi taken;
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
            taken.push_back(0);
        }
    }
    return taken;
}
int currMax = -1;
vi currMaxTaken;
int solve(int tapeLength, vi &tracks, int n, int curr, int maxTape, vi &takenTracks){
    if(tapeLength == 0 || curr == n){
        if(currMax < maxTape - tapeLength){
            currMax = maxTape - tapeLength;
            currMaxTaken = takenTracks;
        }
        return 0;
    }

    if(tracks[curr] > tapeLength) 
        return solve(tapeLength, tracks, n, curr+1, maxTape, takenTracks);

    takenTracks.push_back(tracks[curr]);
    int with = tracks[curr] + solve(tapeLength - tracks[curr], tracks, n, curr+1, maxTape, takenTracks);
    takenTracks.pop_back();
    int without = solve(tapeLength, tracks, n, curr+1, maxTape, takenTracks);

    return max(with, without);
}

void solve(string line)
{
    int tapeLength = -1, numTracks = -1;
    vi tracks, takenTracks;
    currMaxTaken.clear();
    vi isTaken = tokenize(line, tapeLength, numTracks, tracks);

    int ans = solve(tapeLength, tracks, numTracks, 0, tapeLength, takenTracks);
    if(ans == tapeLength){
        for(auto i: tracks){
            cout << i << " ";
        }    
    }else{
        for(auto i: currMaxTaken){
            cout << i << " ";
        }
    }
    cout << "sum:" << ans << endl;
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