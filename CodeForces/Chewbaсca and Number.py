def solve(number):
    ans = ""
    flag = True
    for digit in number:
        digit = int(digit)
        newDigit = 9 - digit
        if newDigit == 0 and flag:
            flag = False
            ans += str(digit)
            continue
        if(newDigit < digit):
            digit = 9 - digit
        ans += str(digit)
        flag = False
    return ans



number = input()
print(solve(number))