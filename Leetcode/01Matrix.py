#undone

class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        ROWS = len(mat)
        COLS = len(mat[0])
        ansMat = []
        visited = []
        def dfs(i, j):
            if(i < 0 or j < 0 or i >= ROWS or j >= COLS):
                return 2
            if(mat[i][j] == 0):
                return 0
            return 1 + min([
                dfs(i-1, j), 
                dfs(i, j-1), 
                dfs(i+1, j), 
                dfs(i, j+1)
            ])

        for i in range(ROWS):
            ansRow = []
            for j in range(COLS):
                ansRow.append(dfs(i, j))
            ansMat.append(ansRow)
        return ansMat

sol = Solution()
sol.updateMatrix([[0,0,0],[0,1,0],[1,1,1]])