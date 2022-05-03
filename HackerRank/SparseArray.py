def matchingStrings(strings, queries):
    freqSet = {}
    resSet = {}
    for string in strings:
        freqSet.setdefault( string, 0 )
        freqSet[string] += 1
    
    i = 0
    for query in queries:
        # stringState = freqSet.get(query, [0, -1])
        # if stringState[1] == -1:
        #     freqSet.setdefault(query, [0, -1])
        #     freqSet[query][1] = i
        #     i += 1
        # res[stringState[1]] = stringState[0]
        resSet.setdefault(query, 0)
        resSet[query] = freqSet.get(query, 0)

    return [resSet.get(query) for query in queries]

matchingStrings(["def", "de", "fgh"], ["de", "lmn", "fgh"])