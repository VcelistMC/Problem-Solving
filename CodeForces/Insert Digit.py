T = int(input())

for _ in range(T):
    n, d = map(int, input().split(" "))
    num = input()
    if(d == 0):
        print(num + str(d))
        continue
    i = 0
    curMax = int(num + str(d))
    for i in range(n+1):
        curMax = max(
            curMax,
            int(num[:i] + str(d) + num[i:])
        )
    
    print(curMax)