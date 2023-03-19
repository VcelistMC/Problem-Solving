n = int(input())
size = 0
goodArray = False
arr = {}

arr1 = list(map(int, input().split()))
for i in range(n):
    num = arr1[i]
    size += 1
    arr.setdefault(num, [])
    arr[num].append(i)

# if goodArray:
#     print(size)
#     for key in list(arr.keys()):
#         print(key, end= " ")
else:
    newSize = n
    for num, indices in arr.items():
        for i in range(len(indices) - 1):
            ind1 = indices[i]
            ind2 = indices[i+1]

            if((ind2 - ind1) % 2 != 0):
                newSize -= 2
                arr1[ind1] = -1
                arr1[ind2] = -1

    # newArr = [0 for _ in range(newSize)]

    # for num, indices in arr.items():
    #     for index in indices:
    #         newArr[index] = num

    print(newSize)
    if newSize == 0:
        print()
    # print(arr1)
    for i in range(n):
        if arr1[i] == -1: continue
        print(arr1[i], end=" ")