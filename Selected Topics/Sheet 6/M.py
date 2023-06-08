T = int(input())

for _ in range(T):
    w1 = input()
    w2 = input()
    n = len(w1)
    m = len(w2)
    dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

    for i in range(n+1):
        for j in range(m+1):
            if i == 0: dp[i][j] = j
            elif j == 0: dp[i][j] = i
            elif w1[i-1] == w2[j-1]: dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(
                    dp[i][j-1],
                    dp[i-1][j],
                    dp[i-1][j-1]
                )

    print(dp[n][m])
