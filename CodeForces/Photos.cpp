#include <iostream>
#include <vector>
using namespace std;

bool in(char pixel)
{
    char colors[] = {'C', 'M', 'Y'};
    for(int i = 0; i < 3; i++)
    {
        if(pixel == colors[i])
            return true;
    }
    return false;
}

bool solve()
{
    int rows, cols;
    cin >> rows >> cols;
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            char pixel; cin >> pixel;
            if(in(pixel))
                return true;
        }
    }
    return false;
}

int main()
{
    cout << (solve()? "#Color" : "#Black&White");
}