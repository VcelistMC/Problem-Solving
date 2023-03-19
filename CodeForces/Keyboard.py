from math import sqrt


def ecli_distance(a, b):
    a1 = pow(abs(a[0] - b[0]), 2)
    b1 = pow(abs(a[1] - b[1]), 2)

    return a1 + b1

def min_d(letterKeys, shiftKeys):
    minq = 9999999999
    for letterKey in letterKeys:
        for shiftKey in shiftKeys:
            minq = min(minq, ecli_distance(letterKey, shiftKey))
        
    return minq

def solve():
    n, m, x = map(int, input().split(" "))
    count = 0
    shiftKeys = []
    keyboard = {}
    can = [False for _ in range(26)]
    for i in range(n):
        line = list(input())
        for j in range(m):
            if(line[j] == "S"):
                shiftKeys.append((i, j))
            else:
                keyboard.setdefault(line[j], [])
                keyboard[line[j]].append([i, j])

    int(input())
    for keys, indices in keyboard.items():
        ind = ord(keys) - ord('a')
        can[ind] = can[ind] or min_d(indices, shiftKeys) <= x*x
    str = input()

    for l in str:
        if keyboard.get(l.lower(), -1) == -1: return -1
        if l.islower():
            continue
        elif (l.isupper() and len(shiftKeys) == 0): return -1
        else:
            # ind = keyboard[l.lower()]
            # minS = min_d(ind, shiftKeys)
            # if minS > x*x: count += 1
            count += 0 if(can[ord(l.lower()) - ord('a')]) else 1
    
    return count

print(solve())