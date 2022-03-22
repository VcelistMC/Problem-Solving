import java.util.HashSet;
public class MaxAreaOfIsland{
    private HashSet<String> visited = new HashSet<>();

    private String convertString(int i, int j){
        return i + "," + j;
    }

    public int dfs(int[][] grid, int i, int j){
        if(i < 0 || j < 0 ||i >= grid.length || i >= grid[0].length)
            return 0;
        if(grid[i][j] == 0 || visited.contains(convertString(i, j)))
            return 0;

        visited.add(convertString(i, j));
        return 1 + dfs(grid, i-1, j)
                 + dfs(grid, i, j-1) 
                 + dfs(grid, i+1, j)
                 + dfs(grid, i, j+1);
    }


    public int maxAreaOfIsland(int[][] grid) {
        visited.clear();
        int max = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] != 0){
                    int pmax = dfs(grid, i, j);
                    max = pmax > max? pmax: max;
                }
            }
        }
        return max;
    }
    public static void main(String[] args) {
        MaxAreaOfIsland areaOfIsland = new MaxAreaOfIsland();
        int[][] island = {{1}};
        areaOfIsland.maxAreaOfIsland(island);
    }
}