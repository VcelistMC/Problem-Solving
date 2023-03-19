from collections import deque
import queue
from typing import Set



class Solution:
    def minMutation(self, start: str, end: str, bank: list[str]) -> int:
        def replace(inp: str, index: int, newVal: str):
            inp = list(inp)
            inp[index] = newVal
            return ''.join(inp)

        bankSet = set()
        for validMut in bank:
            bankSet.add(validMut)
        
        visited = set()
        q = deque()
        genes = ['A', 'C', 'G', 'T']
        q.append(start)
        visited.add(start)

        mutations = 0

        while(q):
            for _ in range(len(q)):
                currGeneStr = q.popleft()
                if currGeneStr == end:
                    return mutations

                for gene in range(8):
                    oldGene = currGeneStr[gene]
                    for newGene in genes:
                        currGeneStr = replace(currGeneStr, gene, newGene)
                        if (not currGeneStr in visited) and (currGeneStr in bankSet):
                            visited.add(currGeneStr)
                            q.append(currGeneStr)
                    currGeneStr = replace(currGeneStr, gene, oldGene)

            mutations += 1
        return -1

sol = Solution()
print(sol.minMutation(start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]))