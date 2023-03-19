from collections import deque
from importlib.resources import path


class Solution:
    def minReorder(self, n: int, connections: list[list[int]]) -> int:
        adjList = [[[], []] for _ in range(n)] #out #in
        visited = set()
        for connection in connections:
            adjList[connection[0]][0].append(connection[1])
            adjList[connection[1]][1].append(connection[0])
        # for i in range(n):
        #     print(i, adjList[i][0], adjList[i][1])
        res = 0
        q = deque()
        q.append(0)
        visited.add(0)
        while q:
            currNode = q.popleft()
            outgoing = adjList[currNode][0]
            incoming = adjList[currNode][1]
            for edge in outgoing:
                if not edge in visited:
                    res += 1
                q.append(edge)
                visited.add(edge)
            for edge in incoming:
                if not edge in visited:
                    q.append(edge)
                    visited.add(edge)
        return res
        

sol = Solution()
x = sol.minReorder(n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]])
print(x)