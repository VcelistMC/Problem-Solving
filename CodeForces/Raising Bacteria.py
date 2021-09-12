def solve(x):
    ans = 0
    while(x != 0):
        if x%2 != 0:
            ans += 1
            x -= 1
        x = x //2
    return ans
    
x = int(input())
print(solve(x))