import java.util.HashSet;

public class SubIslandCount {
    private String key(int i, int j){
        return i + ", " + j;
    }

    HashSet<String> visited = new HashSet<>();

    private boolean dfs(int[][] grid1, int[][] grid2, int i, int j){
        if(i < 0 || j < 0 || i >= grid1.length || j >= grid2[0].length || grid2[i][j] == 0 || visited.contains(key(i, j)))
            return true;
        
        visited.add(key(i, j));

        boolean res = true;
        if(grid1[i][j] == 0)
            res = false;

        res = dfs(grid1, grid2, i-1, j) && res;
        res = dfs(grid1, grid2, i, j-1) && res;
        res = dfs(grid1, grid2, i+1, j) && res;
        res = dfs(grid1, grid2, i, j+1) && res;

        return res;
    }
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int subIslandCount = 0;
        visited.clear();
        int rows = grid1.length;
        int cols = grid1[0].length;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid2[i][j] == 1 && !visited.contains(key(i, j)) && dfs(grid1, grid2, i, j)){
                    subIslandCount++;
                }
            }
        }
        return subIslandCount;
    }

    public static void main(String[] args) {
        SubIslandCount count = new SubIslandCount();
        int[][] grid1 = new int[][]{
            new int[]{1,1,1,0,0},
            new int[]{0,1,1,1,1},
            new int[]{0,0,0,0,0},
            new int[]{1,0,0,0,0},
            new int[]{1,1,0,1,1}
        };
        
        int[][] grid2 = new int[][]{
            new int[]{1,1,1,0,0},
            new int[]{0,0,1,1,1},
            new int[]{0,1,0,0,0},
            new int[]{1,0,1,1,0},
            new int[]{0,1,0,1,0}
        };
        
        System.out.println(count.countSubIslands(grid1, grid2));
    }
}


// public class SubIslandCount {
//     private void markSubIslands(int[][] grid1, int[][] grid2, int i, int j){
//         if(i < 0 || j < 0 || i >= grid1.length 
//             || j >= grid2[0].length 
//             || grid1[i][j] == 0 
//             || grid2[i][j] != 1)
//             {return;}

//         grid2[i][j] = -1;

//         markSubIslands(grid1, grid2, i-1, j);
//         markSubIslands(grid1, grid2, i, j-1);
//         markSubIslands(grid1, grid2, i+1, j);
//         markSubIslands(grid1, grid2, i, j+1);
//     }

//     private void clearSubIslands(int[][] grid1, int[][] grid2, int i, int j) {
//         if(i < 0 || j < 0 || i >= grid1.length 
//             || j >= grid2[0].length 
//             || grid2[i][j] != -1)
//             {return;}

//         grid2[i][j] = 0;

//         clearSubIslands(grid1, grid2, i-1, j);
//         clearSubIslands(grid1, grid2, i, j-1);
//         clearSubIslands(grid1, grid2, i+1, j);
//         clearSubIslands(grid1, grid2, i, j+1);
//     }

//     public int countSubIslands(int[][] grid1, int[][] grid2) {
//         int subIslandCount = 0;
//         int rows = grid1.length;
//         int cols = grid1[0].length;
//         for(int i = 0; i < rows; i++){
//             for(int j = 0; j < cols; j++){
//                 if(grid2[i][j] == 1){
//                     markSubIslands(grid1, grid2, i, j);
//                 }
//             }
//         }

//         for(int i = 0; i < rows; i++){
//             for(int j = 0; j < cols; j++){
//                 if(grid2[i][j] == -1){
//                     subIslandCount++;
//                     clearSubIslands(grid1, grid2, i, j);
//                 }
//             }
//         }
        
//         return subIslandCount;
//     }

//     public static void main(String[] args) {
//         SubIslandCount count = new SubIslandCount();
//         int[][] grid1 = new int[][]{
//             new int[]{1,1,1,0,0},
//             new int[]{0,1,1,1,1},
//             new int[]{0,0,0,0,0},
//             new int[]{1,0,0,0,0},
//             new int[]{1,1,0,1,1}
//         };
        
//         int[][] grid2 = new int[][]{
//             new int[]{1,1,1,0,0},
//             new int[]{0,0,1,1,1},
//             new int[]{0,1,0,0,0},
//             new int[]{1,0,1,1,0},
//             new int[]{0,1,0,1,0}
//         };
        
//         System.out.println(count.countSubIslands(grid1, grid2));
//     }
// }
