def sortString(string): return sorted(list(string))

def lexString(a, b, n, m, k):
    c = ""
    a = sortString(a)
    b = sortString(b)
    
    lastTaken = ""
    toTake = "a" if a[0] < b[0] else "b"
    temp_k = k

    while n != 0 and m != 0:
        toTake = "a" if a[0] < b[0] else "b"
        if toTake == lastTaken:
            temp_k -= 1
            if temp_k == 0:
                temp_k == k
                toTake = "a" if lastTaken == "b" else "b"
        else:
            temp_k = k

        if toTake == "a":
            c += a[0]
            a.remove(a[0])
            n -= 1
            lastTaken = "a"
        else:
            c += b[0]
            b.remove(b[0])
            m -= 1
            lastTaken = "b"

    return c

def parseInput():
    n, m, k = input().split(" ")
    a = input()
    b = input()

    return a, b, int(n), int(m), int(k)

def start():
    testCases = int(input())
    # res = []
    for _ in range(testCases):
        a, b, n, m ,k = parseInput()
        print(lexString(a, b, n, m, k))

    # print("\n".join(res))


start()