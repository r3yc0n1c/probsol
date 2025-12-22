from math import gcd

t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    s = list(map(int, input().split()))

    possible = True

    # Check non-increasing prefix
    for i in range(1, n):
        if p[i-1] % p[i] != 0:
            possible = False
            break

    # Check non-increasing suffix
    if possible:
        for i in range(1, n):
            if s[i-1] % s[i] != 0:
                possible = False
                break

    # Global GCD must agree
    if possible and p[-1] != s[0]:
        possible = False

    # For every split, the combined GCD must be the total GCD
    if possible:
        for i in range(n-1):
            if gcd(p[i], s[i+1]) != p[-1]:
                possible = False
                break

    print("YES" if possible else "NO")
