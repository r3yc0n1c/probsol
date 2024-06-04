/*
OJ: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
Time: O(N)
Space: O(1)
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

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0, N = (1<<n), x, i, j;
        for(i=0;i<N;i++){
            x = 0;
            for(j=0;j<n;j++){
                if(i & (1<<j)){
                    x ^= nums[j];
                }
            }
            sum += x;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.  << endl;
    return 0;
}