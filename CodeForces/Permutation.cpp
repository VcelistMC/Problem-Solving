#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> avail;
    int n; cin >> n;
    while(n--)
    {
        int i;
        int m; cin >> m;
        int *a = new int[m];
        for (int i = 1; i <= m; i++)
        {
            avail.insert(i);
        }
        
        
        cout << "2" << endl;

        while(!avail.empty())
        {
            int curr = *avail.begin();
            while(curr <= m)
            {
                int temp = curr*2;
                cout << curr << " ";
                avail.erase(curr);
 
                if(temp > m) break;

                curr = temp;
            }
        }
        cout << endl;
        
    }
}