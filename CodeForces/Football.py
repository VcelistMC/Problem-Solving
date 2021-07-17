def solve():
    n = int(input())
    firstTeam = input()
    goals = [1, 0]
    teams = [firstTeam, ""]
    if n == 1:
        return firstTeam
    for i in range(n-1):
        goal = input()
        if goal == firstTeam:
            goals[0] += 1
        else:
            teams[1] = goal
            goals[1] += 1
    return teams[0] if goals[0] > goals[1] else teams[1]
    

print(solve())