n, x = map(int, input().split(" "))
m, y = map(int, input().split(" "))

a = []
b = []
len_a = 0
len_b = 0
merged = []
# for i in range(1, max(n, m)+1):
    # if len_a < n:
    #     a.append(i * x)
    #     len_a += 1
    # if len_b < m:
    #     b.append(i * y)
    #     len_b += 1
while len_a < n and len_b < m:
    ai = (len_a+1) * x
    bi = (len_b+1) * y

    if ai < bi:
        merged.append(ai)
        len_a += 1
    else:
        merged.append(bi)
        len_b += 1

while len_a < n:
    merged.append((len_a+1) * x)
    len_a += 1
while len_b < m:
    merged.append((len_b+1) * y)
    len_b += 1
# merged = sorted(a + b)

len_arr = n + m
if len_arr % 2 == 1:
    ind = (len_arr) // 2
    print("{:.1f}".format(merged[ind]))
else:
    ind1 = (len_arr) // 2
    ind2 = ind1 - 1
    med = (merged[ind1] + merged[ind2]) / 2
    print("{:.1f}".format(med))