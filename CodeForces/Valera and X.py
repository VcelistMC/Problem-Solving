def parseInput():
    n = int(input())
    slipOfPaper = []
    for _ in range(n):
        slipOfPaper.append(list(input()))
    
    return slipOfPaper, n

def solve(paper, n):
    diagLetter = paper[0][0]
    invertLetter = paper[0][1]
    if(diagLetter == invertLetter):
        return False
    isXDiagonal = True
    isXInverted = True
    for i in range(1, n):
        if (paper[i][i] != diagLetter) or (paper[n - i - 1][n - i - 1] != diagLetter):
            isXDiagonal = False
            break
        
    for i in range(n):
        for j in range(n):
            if j == i or j == n - i - 1:
                continue
            if(invertLetter != paper[i][j]):
                isXInverted = False
    
    return (isXDiagonal and isXInverted)


def anotherSolve(paper, n):
    diagLetter = paper[0][0]
    invertLetter = paper[0][1]
    if(diagLetter == invertLetter):
        return False
    isXDiagonal = True
    isXInverted = True

    for i in range(n):
        if((not ((paper[i][i] == paper[n-i-1][n-i-1]) and (paper[i][i] == diagLetter))) or not (paper[i].count(diagLetter) == 2 or paper[i].count(diagLetter) == 1)):
            isXDiagonal = False
        if(paper[i].count(invertLetter) != n - 2):
            isXInverted = False


    return (isXDiagonal and isXInverted)


inp = parseInput()
print("YES" if anotherSolve(inp[0], inp[1]) else "NO")
