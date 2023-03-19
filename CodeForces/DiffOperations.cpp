#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void solve()
{
    vi arr;
    int size; cin >> size;
    int first; cin >> first;
    bool isMultiple = true;
    size--;
    int num;
    while (size--)
    {
        cin >> num;
        if(num % first) isMultiple = false;
    }

    cout << (isMultiple? "YES\n": "NO\n");
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n; cin >> n;
    while (n--) solve();
    
    return 0;
}