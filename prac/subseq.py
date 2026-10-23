def get_subsec(arr):
    n = len(arr)
    s = []
    for i in range(1 << n):
        ss = []
        for j in range(n):
            if i & (1 << j):
                ss.append(arr[j])
        s.append(ss)
    return s


a = [1, 2, 3]
print(get_subsec(a))