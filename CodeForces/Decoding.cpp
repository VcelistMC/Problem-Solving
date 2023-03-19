#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void solve()
{
    int len; cin >> len;
    string word; cin >> word;
    vector<char> newWord(len);
    int change = 1;
    int i = 0, ind;
    if(len % 2 == 0)
    {
        int mid = (len / 2) - 1;
        newWord[mid] = word[i];
        i++;
        while(i < len)
        {
            ind = mid + change;
            if(ind < len) newWord[ind] = word[i];
            i++;

            ind = mid - change;
            if(ind >= 0) newWord[ind] = word[i];
            i++;

            change++;
        }
    }
    else
    {
        int mid = (len / 2);
        newWord[mid] = word[i];
        i++;
        while(i < len)
        {
            ind = mid - change;
            if(ind >= 0) newWord[ind] = word[i];
            i++;

            ind = mid + change;
            if(ind < len) newWord[ind] = word[i];
            i++;

            change++;
        }
    }
    for(int i = 0; i < len; i++) cout<<newWord[i];

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