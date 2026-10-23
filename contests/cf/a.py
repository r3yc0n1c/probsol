t = int(input())

while t:
    x = input().strip()
    x_dig = set(x)
    found = False
    for y in range(10):
        if str(y) in x_dig:
            print(y)
            found = True
            break
    if not found:
        y = 10
        while True:
            if set(str(y)) & x_dig:
                print(y)
                break
            y += 1
    t -= 1
