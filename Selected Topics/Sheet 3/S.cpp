#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
typedef std::pair<ui,ui> uiPair;

struct comp {
    constexpr bool operator()(
        uiPair const &a,
        uiPair const &b
    ){
        return a.second < b.second;
    }
};

ui min(ui t1, ui t2, ui t3){
    return min(min(t1, t2), t3);
}

void solve()
{
    int n, num; cin >> n;
    map<ui, ui> ballValue;
    priority_queue<uiPair, vector<uiPair>, comp> ballQ;
    vector<int> snowmen;
    while(n--){
        cin >> num;
        ballValue[num]++;
    }
    if(ballValue.size() < 3){
        print(0);
        return;
    }

    for(auto it: ballValue){
        ballQ.push(make_pair(it.first, it.second));
    }

    while(ballQ.size() >= 3){
        uiPair t1 = ballQ.top();
        ballQ.pop();
        uiPair t2 = ballQ.top();
        ballQ.pop();
        uiPair t3 = ballQ.top();
        ballQ.pop();
        
        t1.second--;
        t2.second--;
        t3.second--;

        vector<ui> tmp;
        tmp.push_back(t1.first);
        tmp.push_back(t2.first);
        tmp.push_back(t3.first);
        sort(all(tmp));

        for(int i = 2; i >= 0; i--) snowmen.push_back(tmp[i]);

        if(t1.second > 0) ballQ.push(t1);
        if(t2.second > 0) ballQ.push(t2);
        if(t3.second > 0) ballQ.push(t3);
    }

    print(snowmen.size() / 3);
    for(int i = 0; i < snowmen.size(); i += 3){
        cout << snowmen[i] << " " << snowmen[i+1] << " " << snowmen[i+2] << endl;
    }

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
    solve();
    return 0;
}