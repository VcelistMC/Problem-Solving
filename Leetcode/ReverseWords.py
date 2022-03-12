def reverseString(s: str) -> str:
    s = list(s)
    i = 0
    j = len(s) - 1
    while(i < j):
        tmp = s[i]
        s[i] = s[j]
        s[j] = tmp
        i+=1
        j-=1
    return "".join(s)

def reverseWords(s: str) -> str:
    s = s.split(" ")
    for i in range(len(s)):
        s[i] = reverseString(s[i])
    s = " ".join(s)
    return s

reverseWords("Let's take LeetCode contest")