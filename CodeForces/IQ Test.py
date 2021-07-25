#solved

def checkforUncompleteSquare(cells):
    return (
        cells.count("#") >= 3 or 
        cells.count(".") >= 3
    )



def solve(test):
    for i in range(3):
        for j in range(3):
            topLeft = test[i][j]
            topRight = test[i][j+1]
            botLeft = test[i+1][j]
            botRight = test[i+1][j+1]
            if checkforUncompleteSquare([topLeft, topRight, botLeft, botRight]):
                return "YES"
    return "NO"




def parseInput(): 
    test = []
    for _ in range(4):
        row = list(input())
        test.append(row)
    return test


test = parseInput()

print(solve(test))