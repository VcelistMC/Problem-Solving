from collections import deque


class Solution:
    def shortestBridge(self, grid: list[list[int]]) -> int:
        # 1.find an land from a single island
        # 2.run a dfs to discover the entire island
        # 3.run a bfs on all nodes of an isalnd till we find the next island
        n = len(grid)
        visited = set()
        dirs = [[0,1], [0, -1], [1, 0], [-1, 0]]
        def dfs(i, j):
            if i < 0 or j < 0 or i>= n or j >= n or grid[i][j] == 0 or (i, j) in visited:
                return
            visited.add((i, j))

            for dir in dirs:
                dfs(i + dir[0], j + dir[1])

        def bfs():
            dist, q = 0, deque(visited)
            while q:
                for _ in range(len(q)):
                    x, y = q.popleft()
                    for dir in dirs:
                        nX = x + dir[0]
                        nY = y + dir[1]
                        if nX < 0 or nX >= n or nY < 0 or nY >= n or (nX, nY) in visited:
                            continue
                        if grid[nX][nY]:
                            return dist
                        
                        q.append((nX, nY))
                        visited.add((nX, nY))
                dist += 1

        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    dfs(i, j)
                    return bfs()
sol = Solution()
print(sol.shortestBridge([
    [0,1,0],
    [0,0,0],
    [0,0,1]
]))
