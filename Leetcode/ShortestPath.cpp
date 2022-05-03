#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ShortestPath
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid.size();

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
            return -1;

        if(grid[0][0]==0 && rows==1 && cols==1)
            return 1;
        
        grid[0][0] = 1;
        queue<int> xQ;
        queue<int> yQ;
        queue<int> dQ;

        xQ.push(0);
        yQ.push(0);
        dQ.push(1);

        int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};

        while (!xQ.empty() && !yQ.empty())
        {
            int x = xQ.front();
            int y = yQ.front();
            int d = dQ.front();
            xQ.pop();
            yQ.pop();
            dQ.pop();

            for (int i = 0; i < 8; i++)
            {
                int newX = x + dirs[i][0];
                int newY = y + dirs[i][1];

                if (newX < 0 || newY < 0 || newX >= rows || newY >= cols)
                    continue;

                if (grid[newX][newY] == 0)
                {
                    if (newX == rows - 1 && newY == cols - 1)
                        return d + 1;

                    xQ.push(newX);
                    yQ.push(newY);
                    dQ.push(d+1);
                    grid[newX][newY] = 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    ShortestPath path;
    vector<vector<int>> grid{
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}};
    vector<vector<int>> grid2{
        {0, 1},
        {1, 0}};
    cout << path.shortestPathBinaryMatrix(grid2);
    return 0;
}
