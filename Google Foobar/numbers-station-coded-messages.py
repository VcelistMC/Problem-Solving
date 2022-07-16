def solution(l, t):
    tmpSum = 0
    n = len(l)
    for i in range(n):
        tmpSum = 0
        for j in range(i, n):
            tmpSum += l[j]
            if tmpSum == t:
                return [i, j]
            if tmpSum > t:
                tmpSum = 0
                break
    return [-1, -1]

print(solution([1, 2, 3, 4], 15))
print(solution([4, 3, 10, 2, 8], 12))