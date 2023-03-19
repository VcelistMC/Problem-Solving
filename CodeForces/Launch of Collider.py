#unsolved

from re import search

def parseInput():
    cords = []
    directions = []

    n = int(input())

    directions = list(input())
    cords = list(map(int, input().split()))
    return cords, directions, n

def solve(cords, directions, n):
    time = 0
    while(True):
        if not search("R.*L", ''.join(directions)):
            return -1
        move(cords, directions)
        time+=1
        setOfCords = set(cords)
        if checkCollosion(setOfCords, cords):
            return time

def move(cords, directions):
    for i in range(len(cords)):
        if directions[i] == 'L':
            cords[i] -= 1
        else:
            cords[i] += 1

def checkCollosion(setOfCords, cords):
    for cord in setOfCords:
        if cords.count(cord) > 1:
            return True
    return False


if __name__ == '__main__':
    inp = parseInput()
    print(solve(inp[0], inp[1], inp[2]))