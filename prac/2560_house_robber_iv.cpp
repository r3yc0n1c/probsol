/*
OJ: https://leetcode.com/problems/house-robber-iv/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), l = 1, r = *max_element(nums.begin(), nums.end());

        while(l<r){
            int m = (l+r)/2, t=0, i=0;
            while(i<n && t<k){
                if(nums[i] <= m){
                    t++;
                    i+=2;
                } else {
                    i++;
                }
            }
            if(t<k){
                l = m+1;
            } else {
                r = m;
            }
        }
        return r;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 2,2 };
    int k = 1;
    cout << sol.minCapability(v, k) << endl;
    return 0;
}