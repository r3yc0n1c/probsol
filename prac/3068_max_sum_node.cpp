/*
OJ: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll s1 = 0, s2 = 0;
        int c = 0, i, n=nums.size(), x;

        for(i=0;i<n;i++){
            x = (nums[i]^k);
            if(nums[i] < x){
                s1 += x;
                c++;
            }
            else{
                s2 += nums[i];
            }
        }

        if((c & 1) == 0){
            return (s1 + s2);
        }

        ll max1 = 0, max2 = 0;

        for(i=0;i<n;i++){
            x = (nums[i]^k);
            if(nums[i] < x){
                max1 = max(max1, s1-x+s2+nums[i]);
            }
            else{
                max2 = max(max2, s1+x+s2-nums[i]);
            }
        }

        return max(max1, max2);
    }
};

int main() {
    Solution s;
    cout << s.  << endl;
    return 0;
}