#solved

def solve():
    num = int(input(), 2)
    nOfTrains = 0
    ans = 1

    if(num == 0):
        return 0

    while(num > ans):
        ans = ans << 2
        nOfTrains += 1
    return nOfTrains


print(solve())