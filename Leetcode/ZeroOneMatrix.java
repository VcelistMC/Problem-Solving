public class ZeroOneMatrix{
    public int[][] updateMatrix(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(mat[i][j] == 1) mat[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(mat[i][j] == 0)
                    continue;
                if(i - 1 > 0) 
                    mat[i][j] = Math.min(mat[i][j], mat[i-1][j] + 1);
                if(j - 1 > 0)
                    mat[i][j] = Math.min(mat[i][j], mat[i][j-1] + 1); 
            }
        }

        for (int i = rows-1; i >= 0; i--) {
            for (int j = cols-1; j >= 0; j--) {
                if(mat[i][j] == 0)
                    continue;

                if(i + 1 < rows) 
                    mat[i][j] = Math.min(mat[i][j], mat[i+1][j] + 1);
                if(j + 1 < cols)
                    mat[i][j] = Math.min(mat[i][j], mat[i][j+1] + 1); 
            }
        }
        return mat;
    }
    public static void main(String[] args) {
        ZeroOneMatrix matrix = new ZeroOneMatrix();
        int[][] grid = new int[][]{
            new int[]{0,0,0},
            new int[]{0,1,0},
            new int[]{1,1,1}
        };
        System.out.println(matrix.updateMatrix(grid));
    }
}



/**
 * [#,#,#,#]
 * [#,1,#,#]
 * [1,0,1,#]
 * [#,1,#,#]
 */