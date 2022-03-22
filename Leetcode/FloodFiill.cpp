#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int level = 2) {
        if(level == -1)
            return image;
        int srcColor = image[sr][sc];
        image[sr][sc] = newColor;
        int rowsCount = image.size();
        int colsCount = image[0].size();

        if(sr - 1 >= 0){
            if(image[sr - 1][sc] == srcColor)
                floodFill(image, sr - 1, sc, newColor, level - 1);
        }
        if(sc - 1 >= 0){
            if(image[sr][sc - 1] == srcColor)
                floodFill(image, sr, sc - 1, newColor, level - 1);
        }
        if(sr + 1 < rowsCount){
            if(image[sr + 1][sc] == srcColor)
                floodFill(image, sr + 1, sc, newColor, level - 1);
        }
        if(sc + 1 < colsCount){
            if(image[sr][sc + 1] == srcColor)
                floodFill(image, sr, sc + 1, newColor, level - 1);
        }
        return image;
    }
    int main(int argc, char const *argv[])
    {
        vector<vector<int>> arr {
            vector<int>{0, 0, 0},
            vector<int>{0, 0, 0},
        };
        floodFill(arr, 0, 0, 2);
        for(vector<int> row: arr){
            for(int cell: row)
                cout << cell << " ";
            cout<<"\n";
        }
        return 0;
    }
    
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.main(argc, argv);
}
