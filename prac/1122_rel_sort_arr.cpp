/*
OJ: https://leetcode.com/problems/relative-sort-array/
Time: O(n+m+k) // n = size of arr1, m = size of arr2, k = max element in arr1
Space: O(k)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m = 0;
        unordered_map<int, int> freq;
        vector<int> res;

        for(int x: arr1){
            freq[x]++;
            m = max(m, x);
        }

        for(int y: arr2){
            while(freq[y]--){
                res.push_back(y);
            }
        }

        for(int i=0;i<=m;i++){
            while(freq[i]-- > 0){
                res.push_back(i);
            }
        }

        return res;
    }
};

int main() {
    vector<int> arr1 = {8,6,22,8,44,17}, arr2 = {22,28,8,6};
    Solution s;

    for(int x: s.relativeSortArray(arr1, arr2))
        cout << x << " ";
    cout << endl;
    return 0;
}