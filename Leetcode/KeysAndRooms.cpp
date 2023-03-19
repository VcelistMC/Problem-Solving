#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int visitedRooms = 0;
    vector<bool> visited;
    int totalRooms;

    void visitAllRooms(vector<vector<int>>& rooms, int currentRoomIndex)
    {
        if(visited[currentRoomIndex])
            return;
        visitedRooms++;
        visited[currentRoomIndex] = true;

        for(int key: rooms[currentRoomIndex])
            visitAllRooms(rooms, key);
    }
public:


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        totalRooms = rooms.size();
        visitedRooms = 0;
        visited.clear();
        for(int i = 0; i < totalRooms; i++)
            visited.push_back(false);
        
        visitAllRooms(rooms, 0);
        return visitedRooms == totalRooms;
    }
};