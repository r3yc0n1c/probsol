# Algorithms
## TOC
- [Sorting](#sorting)
    - []
    - [Dutch National Flag problem](#dutch-national-flag-problem)


## Sorting

#### Dutch National Flag problem

Practice: [Sort Colors](https://leetcode.com/problems/sort-colors/description)

Algo:
```sh
Dutch_National_Flag(arr, arr_size)

low <- 0
mid <- 0
high <- arr_size - 1

while mid <= high 
    if arr[mid] == 0, then
        swap(arr[mid], arr[low])
        low <- low + 1
        mid <- mid + 1
    else if arr[mid] == 0, then
        mid <- mid + 1
    else if arr[mid] == 2, then
        swap(arr[mid], arr[high])
        high <- low - 1
```
Time Complexity: O(n), Only one traversal of the array is needed.

Space Complexity: O(1), No extra space is required.