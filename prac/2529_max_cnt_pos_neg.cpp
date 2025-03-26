/*
OJ: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        for(int x: nums){
            if(x<0) neg++;
            if(x>0) pos++;
        }
        return max(neg, pos);
    }
};

int main() {
    Solution sol;
    vector<int> v = { 3,-2,-1,0,0,1,2};
    cout << sol.maximumCount(v) << endl;
    return 0;
}