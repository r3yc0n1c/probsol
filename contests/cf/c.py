import sys
import threading

def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, k = map(int, sys.stdin.readline().split())
        h = list(map(int, sys.stdin.readline().split()))
        k -= 1  # 0-based

        max_h = max(h)
        if h[k] == max_h:
            print("YES")
            continue

        # Sort heights and keep their indices
        towers = sorted([(val, idx) for idx, val in enumerate(h)])

        # Find where we are in the sorted list
        pos = 0
        while towers[pos][1] != k:
            pos += 1

        # Try to climb up!
        curr_h = towers[pos][0]
        ok = False
        # Since heights are sorted, let's just move up as much as possible
        while True:
            # Find the next tower with smallest height > curr_h and < 2*curr_h
            nxt = None
            for i in range(pos+1, len(towers)):
                nxt_h, nxt_idx = towers[i]
                if nxt_h < 2*curr_h:
                    nxt = i
                    if nxt_h == max_h:
                        ok = True
                        break
                else:
                    break
            if ok:
                break
            if nxt is None:
                break
            # Move up
            pos = nxt
            curr_h = towers[pos][0]
            if curr_h == max_h:
                ok = True
                break
        print("YES" if ok else "NO")

threading.Thread(target=main,).start()
