#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> incomingEdges(n);
        for(vector<int> edge: edges){
            incomingEdges[edge[1]].push_back(edge[0]);
        }
        vector<int> minNodes;
        for(int i = 0; i < n; i++){
            if(incomingEdges[i].size() == 0) minNodes.push_back(i);
        }

        return minNodes;
    }
};