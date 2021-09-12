def parseInput():
    n = int(input())
    nums = map(int, input().split())

    freqMap = {}
    for num in nums:
        freqMap.setdefault(num, 0)
        freqMap[num] += 1
    return freqMap

def maxAndRemove(d):
    """ a) create a list of the dict's keys and values; 
        b) return the key with the max value"""  
    v=list(d.values())
    k=list(d.keys())
    return k[v.index(max(v))]

def solve(freqMap):
    while len(freqMap) != 1:
        k = maxAndRemove(freqMap)
        freqMap.pop(k)
        print(k)


dic = parseInput()
solve(dic)