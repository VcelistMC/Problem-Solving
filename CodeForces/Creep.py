def creepScore(binStr):
    score = -1
    n = len(binStr)
    z = 0
    o = 0
    for i in range(0, n):
        z = 0
        o = 0
        for j in range(0, i+1):
            if binStr[j] == "0": z += 1
            else: o += 1

        p_score = abs(z - o)
        score = p_score if p_score > score else score
    
    return z, o


# zereos, ones
def solve(a, b):
    binStr = ""
    o = 0
    z = 0
    while a != 0 and b != 0:
        str1 = binStr + "0"
        str2 = binStr + "1"

        score1 = abs((z+1) - o)
        score2 = abs(z - (o+1))

        if score1 < score2:
            binStr = str1
            a -= 1
            z += 1
        else:
            binStr = str2
            b -= 1
            o += 1

    if a != 0: binStr += ("0" * a)
    if b != 0: binStr += ("1" * b)
    return binStr

def start():
    n = int(input())

    for _ in range(n):
        a, b = input().split(" ")
        print(solve(int(a), int(b)))

start()

# st = solve(3, 7)
# z, o = creepScore(st)
# z1, o1 = creepScore("0001111111")
# print(st, abs(z - o), abs(z1 - o1))