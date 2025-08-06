def primeproduct(m):
    if m <= 0:
        return False

    def prime(n):
        if n <= 1:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        for i in range(3, (n // 2) + 1, 2):
            if n % i == 0:
                return False
        return True

    for j in range(3, (m // 2) + 1):
        if m % j == 0:
            k = m // j
            if prime(j) and prime(k):
                return True
    return False


def delchar(string, char):
    if len(char) != 1:
        return string
    res = []
    for c in string:
        if c == char:
            continue
        else:
            res.append(c)
    return "".join(res)


def shuffle(list1, list2):
    result = []
    leng = min(len(list2), len(list1))
    for i in range(leng):
        result.append(list1[i])
        result.append(list2[i])
    if len(list1) > len(list2):
        result.extend(list1[leng:])
    else:
        result.extend(list2[leng:])
    return result

