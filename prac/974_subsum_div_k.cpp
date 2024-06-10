/*
OJ: https://leetcode.com/problems/subarray-sums-divisible-by-k/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        int sum = 0, subArrCount = 0, r;
        u[0] = 1;
        
        for(int n: nums){
            sum += n;
            r = (sum % k + k) % k;
            
            if(u[r]) subArrCount += u[r];

            u[r]++;
        }

        return subArrCount;
    }
};

int main() {
    vector<int> v = {4,5,0,-2,-3,1};
    int k=5;
    Solution s;
    cout << s.subarraysDivByK(v, k)  << endl;
    return 0;
}