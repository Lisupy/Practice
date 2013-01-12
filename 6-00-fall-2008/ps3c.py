

def constrainedMatchPair(firstMatch, secondMatch, lenFirst):
    ans = tuple()
    for n in firstMatch:
        for m in secondMatch:
            if n + lenFirst + 1 == m:
                ans = ans + (n,)
    return ans
