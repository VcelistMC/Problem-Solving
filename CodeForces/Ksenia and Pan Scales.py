def parseInput():
    left, right = input().split('|')
    weights = list(input())

    return left, right, weights

# def solve(left, right, weights):
#     if (len(left) + len(right) + len(weights)) % 2 == 0:
#         while len(left) != len(right) and len(weights) != 0:
#             if len(weights) == 0:
#                 return "Impossible"
#             weight = weights[0]
#             if(len(left) > len(right)):
#                 right += weight
#             else:
#                 left += weight
#             weights.remove(weight)
#         if len(weights) == 0 and len(left) == len(right):
#             return '|'.join([left, right])
#     return "Impossible"


def anotherSolve(left, right, weights):
    if (len(left) + len(right) + len(weights)) % 2 == 0:
        for weight in weights:
            if(len(left) > len(right)):
                right += weight
            else:
                left += weight
        return "Impossible" if len(right) != len(left) else "|".join([left, right])
    return "Impossible"


left, right, weights = parseInput()
print(anotherSolve(left, right, weights))
