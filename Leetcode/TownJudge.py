class Solution:
    def findJudge(self, n: int, trust: list[list[int]]) -> int:
        trustingGraph = [[] for _ in range(n+1)]
        trustedGraph = [[] for _ in range(n+1)]
        for trusting in trust:
            trustingGraph[trusting[0]].append(trusting[1])
            trustedGraph[trusting[1]].append(trusting[0])

        for i in range(1,n+1):
            if len(trustingGraph[i]) == 0 and len(trustedGraph[i]) == n-1:
                return i
        return -1
