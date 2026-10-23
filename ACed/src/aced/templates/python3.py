import math
import string
import sys
from array import array
from bisect import bisect_left, bisect_right, insort_left, insort_right
from collections import (
    counter,  # Frequency hashing
    defaultdict,  # Safe dictionary with default values
    deque,  # Fast O(1) double-ended queue
    namedtuple,  # Clean object-like tuples
    ordereddict,  # Preserves insertion order
)
from functools import (
    cache,  # Cleaner Python 3.9+ memoization syntax
    cmp_to_key,  # Custom sorting comparators
    lru_cache,  # Built-in Memoization for DP / Recursion
)
from heapq import (
    heapify,  # O(n) in-place transformation to heap
    heappop,  # O(log n) removal of min element
    heappush,  # O(log n) insertion into a min-heap
    heappushpop,
)
from itertools import (
    accumulate,  # Prefix running totals
    chain,  # Flatten iterables
    combinations,  # Subsets of size k
    permutations,  # Unique arrangements
)
from typing import DefaultDict, Deque, Dict, List, Tuple, TypedDict

# TreeMap / TreeSet equivalent (O(log n) dynamic sorted operations)
from sortedcontainers import SortedDict, SortedList, SortedSet

# speeds up large text inputs/outputs
input = sys.stdin.read


def print_fast(*args, sep=" ", end="\n"):
    sys.stdout.write(sep.join(map(str, args)) + end)


# increase maximum recursion limit for deep DFS algo
sys.setrecursionlimit(2000)
