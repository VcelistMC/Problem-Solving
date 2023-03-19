using System;
public class Solution {
    public void destroyStuffLmao(int[][] grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.Length || j >= grid[0].Length || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;

        destroyStuffLmao(grid, i-1, j);
        destroyStuffLmao(grid, i, j-1);
        destroyStuffLmao(grid, i+1, j);
        destroyStuffLmao(grid, i, j+1);
    }
    public int NumEnclaves(int[][] grid) 
    {
        int rows = grid.Length;
        int cols = grid[0].Length;
        int enclaves = 0;

        for(int i = 0; i < rows; i++){
            if(grid[i][0] == 1)
                destroyStuffLmao(grid, i, 0);
            if(grid[i][cols - 1] == 1)
                destroyStuffLmao(grid, i, cols-1);
        }

        for(int j = 0; j < cols; j++)
        {
            if(grid[0][i] == 1)
                destroyStuffLmao(grid, 0, j);
            if(grid[rows-1][i] == 1)
                destroyStuffLmao(grid, rows-1, j);
        }

        for(int i = 0; i < grid.Length; i++)
        {
            for(int j = 0; j < grid[i].Length; j++)
            {
                if(grid[i][j] == 1)
                    enclaves++;
            }
        }
        return enclaves;
    }
}