//solved
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

map<int, tuple<int, int>> getMatchBoxes(int m)
{
    map<int, tuple<int, int>> boxes;
    for(int i = 0; i < m; i++)
    {
        int matchbox, matches;
        cin >> matchbox >> matches;

        boxes[i] = make_tuple(matchbox, matches);
    }
    return boxes;
}

int getMaxMatchbox(map<int, tuple<int, int>> boxes)
{
    map<int, tuple<int, int>>::iterator it;
    int maxBox = 0;
    for(it = boxes.begin(); it != boxes.end(); it++)
    {
        tuple<int, int> box = it -> second;
        if(get<1>(boxes[maxBox]) < get<1>(box))
            maxBox = it->first;
    }
    return maxBox;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, tuple<int, int>> matchboxes = getMatchBoxes(m);
    int res = 0;
    while(n > 0)
    {
        int biggestBox = getMaxMatchbox(matchboxes);
        tuple<int, int> &box = matchboxes[biggestBox];
        if(n > get<0>(box))
        {
            res += get<1>(box) * get<0>(box);
            get<1>(box) = 0;
            n-= get<0>(box);
        }
        else
        {
            res += get<1>(box) * n;
            n = 0;
        }
    }
    cout << res;
}

int main()
{
    solve();
    return 0;
}