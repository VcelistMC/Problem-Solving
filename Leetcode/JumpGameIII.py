from collections import deque


class Solution:
    def canReach(self, arr: list[int], start: int) -> bool:
        n = len(arr)
        graph = [[] for _ in range(n)]
        for i in range(n):
            if i + arr[i] < n:
                graph[i].append(i + arr[i])
            if i - arr[i] >= 0:
                graph[i].append(i - arr[i])

        q = deque()
        visited = set()
        q.append(start)
        visited.add(start)
        while(q):
            node = q.popleft()
            if arr[node] == 0:
                return True
            for sibling in graph[node]:
                if(not sibling in visited):
                    q.append(sibling)
                    visited.add(sibling)
        return False