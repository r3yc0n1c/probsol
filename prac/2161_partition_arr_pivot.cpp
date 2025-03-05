/*
OJ: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
Time:
Space:
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), p = 0, q = n-1;
        vector<int> v(n);

        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            if (nums[i] < pivot) {
                v[p++] = nums[i];
            }
            if (nums[j] > pivot) {
                v[q--] = nums[j];
            }
        }
        while (p <= q) {
            v[p++] = pivot;
        }
        
        return v;
    }
};

int main() {
    Solution sol;
    int p = 2;
    vector<int> v = { -3,4,3,2 };
    for(auto x: sol.pivotArray(v, p))
        cout << x << " "; 
    cout << endl;
    return 0;
}