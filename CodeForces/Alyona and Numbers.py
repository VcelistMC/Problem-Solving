n, m = map(int, input().split())

ans = 0

hashMap = {}

for i in range(1, n+1):
    for j in range(1, m+1):
        key = i + j
        try:
            if hashMap[key]:
                ans += 1
        except:
            if key >= 5:
                if key % 5 == 0:
                    ans += 1
                    hashMap[key] = True
                    continue
            hashMap[key] = False
print(ans)