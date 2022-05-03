class Solution:
    def makeConnected(self, n: int, connections: list[list[int]]) -> int:
        if(len(connections) < n - 1):
            return -1
        
        visited = [False for _ in range(n)]

        def dfs(computer: int):
            if(visited[computer]): return

            visited[computer] = True
            
            for connection in connectionsLists[computer]:
                dfs(connection)


        isolatedClusters = 0

        connectionsLists = [[] for _ in range(n)]
        for connection in connections:
            connectionsLists[connection[0]].append(connection[1])
            connectionsLists[connection[1]].append(connection[0])


        for i in range(n):
            if not visited[i]:
                dfs(i)
                isolatedClusters+=1
        return isolatedClusters - 1