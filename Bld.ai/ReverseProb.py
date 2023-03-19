
n = int(input())
x = set()
strings = []
for _ in range(n-2):
    line = input()
    strings.append(line)
    for l in list(line):
        x.add(l)

out = ""
if n < len(x):
    print("NO")
else:
    print("YES")
    for string in strings:
        taken = min(3, n)
        out += string[:taken]
        n -= taken  

    print(out)
