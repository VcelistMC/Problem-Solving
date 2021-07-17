n, k = map(int, input().split())
goodNums = 0

while n >= 0:
    kCount = 0
    nums = input()
    for i in range(k+1):
        if str(i) in nums:
            kCount += 1
    if kCount == k+1:
        goodNums += 1
    n-=1
print(goodNums)