def getNextPalindrome(num):
    strNum = str(num)
    msd = -1
    for num in strNum:
        msd = int(num) if int(num) > msd else msd
    if msd == 9:
        msd = msd + 2
    else:
        msd = msd + 1
    
    palindrome = msd * int("1" * (len(strNum)))

    return palindrome

n = int(input())
for _ in range(n):
    input()
    num = int(input())
    print(getNextPalindrome(num) - num)