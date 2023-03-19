#include <iostream>
#include <unordered_map>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    char *buf;
    while (n--)
    {
        cin.getline(buf, 1);
        int numStations, numQueuries;
        unordered_map<int, vector<int>> stations_indices;
        cin >> numStations >> numQueuries;
        for(int i = 0; i < numStations; i++){
            int station; cin >> station;
            stations_indices[station].push_back(i);
        }
    }
    
}