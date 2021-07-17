#include<iostream>
#include <vector>
using namespace std;

void minimumBribes(vector<int> q) {
    int n = q.size();
    int bribes = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(q[i] > i+1) {
            int bribe = q[i] - (i+1);
            if(bribe <= 2)  
                bribes += bribe;
            else {
                cout << "Too chaotic\n";
                return;
            }
        }
    }
    cout << bribes;
}

// 2 1 5 3 4
void calc(vector<int> q)
{
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        int per = q[i];
        if (per - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, per - 2); j < i; j++)
            if (q[j] > per) ans++;
    }
    cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        vector<int> vec;
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int ele; cin >> ele;
            vec.push_back(ele);
        }
        calc(vec);
    }
}