shapes = {
    'Tetrahedron': 4,
    'Cube': 6,
    'Octahedron': 8,
    'Dodecahedron': 12,
    'Icosahedron': 20
}

def solve(n):
    sum = 0
    for _ in range(n):
        shape = input()
        sum += shapes[shape]
    return sum


n = int(input())
print(solve(n))