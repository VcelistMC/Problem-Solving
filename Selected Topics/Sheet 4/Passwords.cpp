#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ll long long
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
#define ui unsigned int
#define endl "\n"
#define all(x) x.begin(), x.end()
#define inputVec(x) for(int i = 0; i < x.size(); i++) cin >> x[i]
#define inputIntVec(x, n) for(int i = 0; i < n; i++) {int num; cin >> num; x.push_back(num);}
#define outputVec(x) for(int i = 0; i < x.size(); i++) cout << x[i] << endl
#define print(x) cout << x << endl
int dirs4[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dirs8[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
bool inBounds(int x, int y, int n, int m){ return x >= 0 && y >= 0 && x < n && y < m; }
bool inBounds(pii p, int n, int m){ return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m; }
vector<string> pwds;

void recurs(vector<string> words, string rule, int pos, vector<string> currWord){
    if(pos == rule.size()){
        string word = "";
        for(string c: currWord) word += c;
        pwds.push_back(word);
        return;
    }
    else{
        if(rule[pos] == '0'){
            for(int i = 0; i < 10; i++){
                currWord.push_back(to_string(i));
                recurs(words, rule, pos+1, currWord);
                currWord.pop_back();
            }
        }else{
            for(string word: words){
                currWord.push_back(word);
                recurs(words, rule, pos+1, currWord);
                currWord.pop_back();
            }
        }
    }
}

void recurs(vector<string> words, string rule){
    pwds.clear();
    recurs(words, rule, 0, vector<string>());
}

void solve(int dicLen)
{
    vector<string> words(dicLen);
    inputVec(words);
    int rulesLen; cin >> rulesLen;
    vector<string> rules(rulesLen);
    inputVec(rules);
    for(string rule: rules){
        recurs(words, rule);
        for(string pwd: pwds){
            print(pwd);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    int T; ;
    while(cin >> T) {
        cout << "--\n";
        solve(T);
    }
    return 0;
}