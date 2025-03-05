/*
OJ: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> c = nums;
        unordered_map<int, int> u;
        sort(nums.begin(), nums.end());

        for(i=n-1;i>=0;i--){
            u[nums[i]] = i;
        }

        for(i = 0;i<n;i++){
            c[i] = u[c[i]];
        }
        return c;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 8,1,2, 2, 3 };
    for (auto x: sol.smallerNumbersThanCurrent(v))
        cout << x << ' ';
    cout << endl;
    return 0;
}