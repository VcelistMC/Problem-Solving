def parseInput():
    n = int(input())
    arr = map(int, input().split(" "))

    hashMap = set(arr)

    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if arr[i] + arr[j] + arr[k] not in hashMap:
                    return "NO"
    return "YES"

def start():
    n = int(input())
    for _ in range(n):
        ans = parseInput()
        print(ans)


start()