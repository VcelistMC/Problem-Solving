from math import ceil

n, m, a = map(int, input().split())

horizontal_flags = ceil(n/a)
vertical_flags = ceil(m/a)

print(horizontal_flags * vertical_flags)