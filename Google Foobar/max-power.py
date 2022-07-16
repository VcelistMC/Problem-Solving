def solution(xs):
    n = len(xs)
    if n == 1:
        return str(xs[0])
    negCount, zeroCount, negMax = 0, 0, -1001
    prod = 1
    for num in xs:
        if num == 0:
            zeroCount += 1
            continue
        if num < 0:
            negCount += 1
            negMax = max(negMax, num)
            
        prod *= num
        
    if zeroCount == n:
        return "0"
    
    if negCount % 2 == 1:
        if negCount == 1 and zeroCount + negCount == n:
            return "0"
        
        prod = int(prod/negMax)
    return str(prod)

# print(solution([2, 0, 2, 2, 0]))
# print(solution([-2, -3, 4, -5]))
print(solution([0, -3, 0, 0, 1]))