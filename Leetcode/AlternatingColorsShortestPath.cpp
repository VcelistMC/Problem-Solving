#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution
{

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<pair<int, int>> res(n, {INT_MAX, INT_MAX});
        vector<int> minDistance(n, -1);
        queue<pair<int, int>> q;
        vector<vector<int>> redAdjList(n);
        vector<vector<int>> blueAdjList(n);

        for(auto edge: redEdges){
            redAdjList[edge[0]].push_back(edge[1]);
        }
        for(auto edge: blueEdges){
            blueAdjList[edge[0]].push_back(edge[1]);
        }
        q.push({0, 1});  // red
        q.push({0, -1}); // blue
        res[0] = {0,0};
        int dist = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();
                if (color == 1)
                {
                    for (int sibling : blueAdjList[node])
                    {
                        if (res[sibling].first > dist + 1)
                        {
                            q.push({sibling, -1});
                            res[sibling].first = dist + 1;
                        }
                    }
                }
                else
                {
                    for (int sibling : redAdjList[node])
                    {
                        if (res[sibling].second > dist + 1)
                        {
                            q.push({sibling, 1});
                            res[sibling].second = dist + 1;
                        }
                    }
                }
            }
            dist++;
        }

        for (int i = 0; i < n; i++)
        {
            int minDist = min(res[i].first, res[i].second);
            minDistance[i] = minDist == INT_MAX ? -1 : minDist;
        }
        return minDistance;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 5;
    vector<vector<int>> redEdges = {
        {2,0},
        {4,3},
        {4,4},
        {3,0},
        {1,4}
    };
    vector<vector<int>> blueEdges = {
        {2,1},
        {4,3},
        {3,1},
        {3,0},
        {1,1},
        {2,0},
        {0,3},
        {3,3},
        {2,3}
    };
    sol.shortestAlternatingPaths(n, redEdges, blueEdges);
    return 0;
}
