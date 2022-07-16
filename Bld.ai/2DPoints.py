from curses import init_pair


n, k = map(int, input().split(" "))
points_x = []
for _ in range(n):
    points_x.append(list(map(int, input().split(" "))))

points_y = sorted(points_x, key=lambda l:l[1])

