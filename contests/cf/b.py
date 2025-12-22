t = int(input())

while t:
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    max_peaks = 0
    i = 0
    while i <= n-k:
        if all(x == 0 for x in a[i:i+k]):
            max_peaks += 1
            i += k + 1
        else:
            i += 1
    print(max_peaks)
    t -= 1
