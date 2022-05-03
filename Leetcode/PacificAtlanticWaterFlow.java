import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class PacificAtlanticWaterFlow {
    boolean canFlowToPacific = false;
    boolean canFlowToAtlantic = false;
    HashSet<String> visited = new HashSet<>();
    int rows;
    int cols;
    
    String toKey(int i, int j){
        return i + ", " + j;
    }
    
    public void dfs(int[][] grid, int i, int j, int prevHeight) {
        if(i < 0 || j < 0){
            canFlowToPacific = true;
            return;
        }
        if(i >= rows || j >= cols){
            canFlowToAtlantic = true;
            return;
        }
        
        if(grid[i][j] > prevHeight || visited.contains(toKey(i, j)))
            return;
        visited.add(toKey(i, j));

        if(!(canFlowToAtlantic && canFlowToPacific)){
            dfs(grid, i-1, j, grid[i][j]);
            dfs(grid, i+1, j, grid[i][j]);
            dfs(grid, i, j-1, grid[i][j]);
            dfs(grid, i, j+1, grid[i][j]);
        }
    }
    
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> coords = new  ArrayList<>();
        rows = heights.length;
        cols = heights[0].length;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                canFlowToAtlantic = canFlowToPacific = false;
                visited.clear();
                dfs(heights, i, j, heights[i][j]);
                if(canFlowToAtlantic && canFlowToPacific){
                    coords.add(
                        Arrays.asList(i,j)
                    );
                }
            }
        }
        return coords;
    }
    
    public static void main(String[] args) {
        PacificAtlanticWaterFlow pacificAtlanticWaterFlow = new PacificAtlanticWaterFlow();
        int[][] island = new int[][]{
            new int[]{2,1},
            new int[]{1,2}
        };
        System.out.println(pacificAtlanticWaterFlow.pacificAtlantic(island));

    }
}
