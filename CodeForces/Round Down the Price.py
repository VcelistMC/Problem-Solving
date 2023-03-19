n = int(input())

for _ in range(n):
    m = input()
    newPrice = "1" + ("0" * (len(m) - 1))
    print(int(m) - int(newPrice))
